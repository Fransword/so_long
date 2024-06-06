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

void    error(void)
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

int	county(char **map, int lines)
{
	int i;
    int j;

    i = 1;
    j = strlen2(map[0]);
    while (i < lines)
    {
        if (strlen2(map[i] != j))
            error();
        i++;
    }
    return (j);
}

char    **open_map(char *argv, int *rows, int *cols)
{
    int     fd;
    char    **map;
    int     i;
    int     j;

    fd = open(argv, O_RDONLY);
    if (fd < 0)
        return (NULL);
    *rows = countx(argv);
    *cols = county(NULL);
    map = (char **)malloc(sizeof(char *) * (*rows));
    if (!map)
        return (NULL);
    i = 0;
    if (i < *rows)
    {
        map[i] = (char *)malloc(sizeof(char *) * (*cols));
        if (!map[i])
            return (NULL);
        if (read(fd, map[i], *cols) < *cols)
            return (NULL);
        map[i][*cols] = '\0';
        i++;
    }
    close (fd);
    return (map);
}

int main(int argc, char **argv)
{
    t_game  *game;

    if (argc != 2 || (ft_strncmp(".ber", &argv[1][strlen2(argv[1]) - 4], 4)))
        error();
    game = malloc(sizeof(t_game));
    if (!game)
        return (0);
    game->count = 0;
    game->lines = countx(argv[1]);
    game->map = open_map(argv[1], game->line);
    game->cols = county(game->map, game->line);
    set_xy(game);
    check_map(game);
    game->mlx = mlx_init(game->cols * PIXEL, game->line * PIXEL, "so_long", false);
    game->image = malloc(sizeof(t_image));
    if (!game->image)
        return (0);
    set_image(game);
    map_print(game);
    mlx_key_hook(game->mlx, &my_keyhook, game);
    mlx_loop(game->mlx);
    return (0);
}