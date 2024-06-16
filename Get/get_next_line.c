/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francflo <francflo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:54:12 by francflo          #+#    #+#             */
/*   Updated: 2024/06/06 18:42:45 by francflo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../so_long.h"

char	*ft_free(char **s)
{
	free(*s);
	*s = NULL;
	return (NULL);
}

char	*new_storage(char *s, char *line)
{
	char	*tmp;
	int		i;
	int		j;

	j = 0;
	if (!line)
		return (NULL);
	tmp = ft_calloc((ft_strlen(s)- ft_strlen(line) + 2), sizeof(char));
	i = ft_strlen(line);
	while (s[i])
	{
		tmp[j] = s[i];
		i++;
		j++;
	}
	free(s);
	s = NULL;
	tmp[j] = 0;
	return (tmp);
}

char	*new_line(char *s)
{
	char	*line;
	int		i;

	i = 0;
	if (!s[i])
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
		i--;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		ft_free(&s);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*read_line(char *s, int fd)
{
	char	buff[BUFFER_SIZE + 1];
	char	*tmp;
	int		nbytes;

	nbytes = 1;
	buff[0] = 0;
	if (!s)
	{
		s = ft_calloc(1, 1);
		if (!s)
			return (NULL);
	}
	while (nbytes > 0 && !ft_strchr(buff, '\n'))
	{
		nbytes = read(fd, buff, BUFFER_SIZE);
		if (nbytes < 0)
			ft_free(&s);
		buff[nbytes] = 0;
		tmp = ft_strjoin(s, buff);
		free(s);
		if (!tmp)
			return (NULL);
		s = tmp;
	}
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(s);
		s = NULL;
		return (NULL);
	}
	s = read_line(s, fd);
	if (!s)
		return (NULL);
	line = new_line(s);
	if (!line)
	{
		free(s);
		s = NULL;
	}
	s = new_storage(s, line);
	return (line);
}
