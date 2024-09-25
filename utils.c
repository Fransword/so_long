/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francflo <francflo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:05:35 by francflo          #+#    #+#             */
/*   Updated: 2024/06/06 19:05:35 by francflo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && n != 0)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
		n--;
	}
	return (0);
}

int	strlen2(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

void	set_xy(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] != '\n' && game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'E')
			{
				game->doorx = i;
				game->doory = j;
			}
			if (game->map[i][j] == 'P')
			{
				game->playerx = i;
				game->playery = j;
			}
			j++;
		}
		i++;
	}
}

char	*ft_strdup(const char *s1)
{
	int		n;
	int		i;
	char	*ptr;
	char	*aux;

	aux = (char *)s1;
	i = 0;
	n = strlen2(aux) + 1;
	if (!s1)
		return (0);
	ptr = (char *)malloc(sizeof (char) * n);
	if (!ptr)
		return (0);
	while (aux[i])
	{
		ptr[i] = aux[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	**cmap(t_game *game)
{
	int		i;
	char	**cmap;

	i = 0;
	cmap = malloc(sizeof(char *) * (game->line + 1));
	while (game->map[i])
	{
		cmap[i] = ft_strdup(game->map[i]);
		i++;
	}
	cmap[i] = NULL;
	return (cmap);
}
