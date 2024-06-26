/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francflo <francflo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:42:20 by francflo          #+#    #+#             */
/*   Updated: 2024/06/06 18:42:20 by francflo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(void)
{
	write(2, "ERROR\n", 6);
	exit(1);
}

int	countx(char *argv)
{
	int		i;
	char	*map;
	int		fd;

	fd = open(argv, O_RDONLY);
	i = 0;
	map = get_next_line(fd);
	free(map);
	while (map)
	{
		map = get_next_line(fd);
		free(map);
		i++;
	}
	close(fd);
	return (i);
}

/*char	**open_map(char *argv, int *line)
{
   char	**map;
	int		i;
	int		fd;

	fd = open(argv, O_RDONLY);
	map = malloc((sizeof(char *)) * (*line + 1));
	if (map == NULL)
		return (0);
	i = 0;
	while (i < *line)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = 0;
	close(fd);
	return (map);
}*/

char	**open_map(char *argv, int *line)
{
    char	**map;
	int		i;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		error();
	map = malloc((sizeof(char *)) * (*line + 1));
	if (!map)
		return (0);
	i = 0;
	while (i < *line)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
		{
			while (i-- > 0)
				free(map[i]);
			free(map);
			close(fd);
			error();
		}
		i++;
	}
	map[i] = 0;
	close(fd);
	return (map);
}

int main(int argc, char **argv)
{
	t_game  *game;

	if (argc != 2 || (ft_strncmp(".ber", &argv[1][strlen2(argv[1]) - 4], 4)))
		error();
	game = malloc(sizeof(t_game));
	if (!game)
	{
		write(1, "peto", 4);
		return (0);
	}
	game->count = 0;
	game->line = countx(argv[1]);
	//write(1, "aqui 1\n", 7);
	if (game->line == 0)
		error();
	game->map = open_map(argv[1], &game->line);
	game->cols =  strlen2(game->map[0]);
	set_xy(game);
	check_map(game);
	game->mlx = mlx_init(game->cols * PIXEL, game->line * PIXEL, "so_long", false);
	game->image = malloc(sizeof(t_image));
	if (!game->image)
		return (0);
	set_images(game);
	print_map(game);
	mlx_key_hook(game->mlx, &keybinding, game);
	mlx_loop(game->mlx);
	return (0);
}
