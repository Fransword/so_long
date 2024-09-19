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

void	press_w(t_game *game)
{
	if (game->map[game->playery - 1][game->playerx] != '1')
	{
		if (game->map[game->playery][game->playerx] == 'E')
			mlx_image_to_window(game->mlx, game->image->door,
				game->playerx * PIXEL, game->playery * PIXEL);
		else
			mlx_image_to_window(game->mlx, game->image->floor,
				game->playerx * PIXEL, game->playery * PIXEL);
		game->playery --;
		mlx_image_to_window(game->mlx, game->image->hero,
			game->playerx * PIXEL, game->playery * PIXEL);
		game->count++;
		ft_printf("count: %i\n", game->count);
		if (game->map[game->playery][game->playerx] == 'C')
		{
			game->coin--;
			game->map[game->playery][game->playerx] = '0';
			if (game->coin == 0)
				mlx_image_to_window(game->mlx, game->image->exit,
					game->doory * PIXEL, game->doorx * PIXEL);
		}
		if (game->map[game->playery][game->playerx] == 'E' && game->coin == 0)
			end(game);
	}
}

void	press_a(t_game *game)
{
	if (game->map[game->playery][game->playerx - 1] != '1')
	{
		if (game->map[game->playery][game->playerx - 1] != '1')
		{
			if (game->map[game->playery][game->playerx] == 'E')
				mlx_image_to_window(game->mlx, game->image->door,
					game->playerx * PIXEL, game->playery * PIXEL);
			else
				mlx_image_to_window(game->mlx, game->image->floor,
					game->playerx * PIXEL, game->playery * PIXEL);
			game->playerx --;
			mlx_image_to_window(game->mlx, game->image->hero,
				game->playerx * PIXEL, game->playery * PIXEL);
			game->count++;
			ft_printf("count: %i\n", game->count);
			if (game->map[game->playery][game->playerx] == 'C')
			{
				game->coin--;
				game->map[game->playery][game->playerx] = '0';
				if (game->coin == 0)
					mlx_image_to_window(game->mlx, game->image->exit,
						game->doory * PIXEL, game->doorx * PIXEL);
			}
			if (game->map[game->playery][game->playerx] == 'E'
			&& game->coin == 0)
				end(game);
		}
	}
}

void	press_s(t_game *game)
{
	if (game->map[game->playery + 1][game->playerx] != '1')
	{
		if (game->map[game->playery][game->playerx] == 'E')
			mlx_image_to_window(game->mlx, game->image->door,
				game->playerx * PIXEL, game->playery * PIXEL);
		else
			mlx_image_to_window(game->mlx, game->image->floor,
				game->playerx * PIXEL, game->playery * PIXEL);
		game->playery ++;
		mlx_image_to_window(game->mlx, game->image->hero,
			game->playerx * PIXEL, game->playery * PIXEL);
		game->count++;
		ft_printf("count: %i\n", game->count);
		if (game->map[game->playery][game->playerx] == 'C')
		{
			game->coin--;
			game->map[game->playery][game->playerx] = '0';
			if (game->coin == 0)
				mlx_image_to_window(game->mlx, game->image->exit,
					game->doory * PIXEL, game->doorx * PIXEL);
		}
		if (game->map[game->playery][game->playerx] == 'E' && game->coin == 0)
			end(game);
	}
}

void	press_d(t_game *game)
{
	if (game->map[game->playery][game->playerx + 1] != '1')
	{
		if (game->map[game->playery][game->playerx] == 'E')
			mlx_image_to_window(game->mlx, game->image->door,
				game->playerx * PIXEL, game->playery * PIXEL);
		else
			mlx_image_to_window(game->mlx, game->image->floor,
				game->playerx * PIXEL, game->playery * PIXEL);
		game->playerx ++;
		mlx_image_to_window(game->mlx, game->image->hero,
			game->playerx * PIXEL, game->playery * PIXEL);
		game->count++;
		ft_printf("count: %i\n", game->count);
		if (game->map[game->playery][game->playerx] == 'C')
		{
			game->coin--;
			game->map[game->playery][game->playerx] = '0';
			if (game->coin == 0)
				mlx_image_to_window(game->mlx, game->image->exit,
					game->doory * PIXEL, game->doorx * PIXEL);
		}
		if (game->map[game->playery][game->playerx] == 'E' && game->coin == 0)
			end(game);
	}
}

void	keybinding(mlx_key_data_t keydata, void *param)
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
		end(game);
}
