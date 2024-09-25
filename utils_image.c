/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francflo <francflo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:30:31 by francflo          #+#    #+#             */
/*   Updated: 2024/09/25 19:24:46 by francflo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_texture_t	*set_img_floor(t_game *game)
{
	mlx_texture_t	*a_floor;

	a_floor = mlx_load_png("./png/floor.png");
	if (!a_floor)
		ft_error(game);
	game->image->floor = mlx_texture_to_image(game->mlx, a_floor);
	mlx_delete_texture(a_floor);
	if (!game->image->floor)
		ft_error(game);
	return (a_floor);
}

mlx_texture_t	*set_img_cols(t_game *game)
{
	mlx_texture_t	*a_cols;

	a_cols = mlx_load_png("./png/cols.png");
	if (!a_cols)
		ft_error(game);
	game->image->cols = mlx_texture_to_image(game->mlx, a_cols);
	mlx_delete_texture(a_cols);
	if (!game->image->cols)
		ft_error(game);
	return (a_cols);
}

mlx_texture_t	*set_img_door(t_game *game)
{
	mlx_texture_t	*a_door;

	a_door = mlx_load_png("./png/door.png");
	if (!a_door)
		ft_error(game);
	game->image->door = mlx_texture_to_image(game->mlx, a_door);
	mlx_delete_texture(a_door);
	if (!game->image->door)
		ft_error(game);
	return (a_door);
}

mlx_texture_t	*set_img_coin(t_game *game)
{
	mlx_texture_t	*a_coin;

	a_coin = mlx_load_png("./png/coin.png");
	if (!a_coin)
		ft_error(game);
	game->image->coin = mlx_texture_to_image(game->mlx, a_coin);
	mlx_delete_texture(a_coin);
	if (!game->image->coin)
		ft_error(game);
	return (a_coin);
}

mlx_texture_t	*set_img_hero(t_game *game)
{
	mlx_texture_t	*a_hero;

	a_hero = mlx_load_png("./png/hero.png");
	if (!a_hero)
		ft_error(game);
	game->image->hero = mlx_texture_to_image(game->mlx, a_hero);
	mlx_delete_texture(a_hero);
	if (!game->image->hero)
		ft_error(game);
	return (a_hero);
}
