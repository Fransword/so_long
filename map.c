/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francflo <francflo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 12:43:47 by francflo          #+#    #+#             */
/*   Updated: 2024/06/16 12:43:47 by francflo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	char_to_image(t_game *game, int i, int j)
{
	mlx_image_to_window(game->mlx, game->image->floor, j * PIXEL, i * PIXEL);
	if (game->map[i][j] == '1')
		mlx_image_to_window(game->mlx, game->image->cols, j * PIXEL, i * PIXEL);
	if (game->map[i][j] == 'C')
		mlx_image_to_window(game->mlx, game->image->coin, j * PIXEL, i * PIXEL);
	if (game->map[i][j] == 'E')
		mlx_image_to_window(game->mlx, game->image->door, j * PIXEL, i * PIXEL);
	if (game->map[i][j] == 'P')
	{
		game->playerx = j;
		game->playery = i;
	}
}

void	print_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->line)
	{
		j = 0;
		while (j < game->cols)
		{
			char_to_image(game, i, j);
			j++;
		}
		i++;
	}
	mlx_image_to_window(game->mlx, game->image->hero,
		game->playerx * PIXEL, game->playery * PIXEL);
}

static void	fill(char **map, int line, int cols)
{
	map[line][cols] = '1';
	if (map[line - 1][cols] != '1')
		fill(map, (line - 1), cols);
	if (map[line + 1][cols] != '1')
		fill(map, (line + 1), cols);
	if (map[line][cols - 1] != '1')
		fill(map, line, (cols - 1));
	if (map[line][cols + 1] != '1')
		fill(map, line, (cols + 1));
}

int	windwalk(t_game *game)
{
	int	i;
	int	j;
	char	**copium;

	copium = cmap(game);
	fill(copium, game->playerx, game->playery);
	i = 0;
	j = 0;
	while (copium[i][j])
	{
		j = 0;
		while (copium[i][j] != '\n' && copium[i][j] != '\0')
		{
			if (copium[i][j] == 'c' || copium[i][j] == 'E')
				//ft_error(game);
				exit(0);
			j++;
		}
		i++;
	}
	freemap(copium);
	return (1);
}
