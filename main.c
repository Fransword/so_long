/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francflo <francflo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:26:06 by francflo          #+#    #+#             */
/*   Updated: 2024/05/01 19:07:12 by francflo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	countx(char *argv)
{
	int		i;
	char	*map;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (0);
	map = get_next_line(fd);
	i = 0;
	while (map)
	{
		map = get_next_line(fd);
		i++;
	}
	close(fd);
	printf ("%d\n", i);
	return (i);
}

int	county(char **map)
{
	int		i;

	i = 0;
	while (map[0][i] != '\0')
		i++;
	printf ("%d", i);
	return (i);
}


int	main(int argc, char **argv)
{
	int	i;
	int	fd;
	int	rows;
	char	**map;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit(1);
	rows = countx(argv[1]);
	map = (char **)malloc(sizeof(char *) * (rows + 1));
	if (!map)
		free(map);
	i = 0;
	while (rows > i)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	map[i] = NULL;
	county(map);
}
