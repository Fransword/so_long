/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francflo <francflo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 13:15:55 by francflo          #+#    #+#             */
/*   Updated: 2024/06/16 13:15:55 by francflo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	freemap(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	end(t_game *game)
{
	freemap(game->map);
	mlx_terminate(game->mlx);
	exit(0);
}

mlx_texture_t	*set_img_exit(t_game *game)
{
	mlx_texture_t	*a_exit;

	a_exit = mlx_load_png("./png/exit.png");
	if (!a_exit)
		ft_error(game);
	game->image->exit = mlx_texture_to_image(game->mlx, a_exit);
	mlx_delete_texture(a_exit);
	if (!game->image->exit)
		ft_error(game);
	return (a_exit);
}

void	set_images(t_game *game)
{
	set_img_floor(game);
	set_img_cols(game);
	set_img_door(game);
	set_img_coin(game);
	set_img_hero(game);
	set_img_exit(game);
}
