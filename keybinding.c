/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybinding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francflo <francflo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:17:54 by francflo          #+#    #+#             */
/*   Updated: 2024/06/16 15:17:54 by francflo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void press_w(t_game *game)
{}

void press_a(t_game *game)
{}

void press_s(t_game *game)
{}

void press_d(t_game *game)
{}

void keybinding(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		press_w(game);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		press_s(game);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		press_a(game);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		press_d(game);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		end_game(game);
}