/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francflo <francflo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:42:03 by francflo          #+#    #+#             */
/*   Updated: 2024/06/06 18:42:03 by francflo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_cols(t_game *game)
{
    int     i;
    i = 0;
    while (game->map[0][i] != '\n' && game->map[0][i] != '\0')
    {
        if (game->map[0][i] != '1' || game->map[game->line - 1][i] != '1')
            error();
        i++;
    }
    i = 0;
    while (game->line > (i + 1))
    {
        if (game->map[i][0] != '1' || game->map[i][game->cols - 1] != '1')
        {
            write (1, "entro\n", 11);
            error();
        }
        i++;
    }
    return (1);
}

int check_hd(t_game *game)
{
    int countp;
    int counte;
    int i;
    int j;

    i = 0;
    j = 0;
    countp = 0;
    counte = 0;
    while (game->map[i][j])
    {
        j = 0;
        while (game->map[i][j] != '\n' && game->map[i][j] != '\0')
        {
            if (game->map[i][j] == 'E')
                counte++;
            if (game->map[i][j] == 'P')
                countp++;
        }
    }
}

int check_coin(t_game *game)
{
    int     i;
    int     j;
    int     count;

    i = 0;
    j = 0;
    count = 0;
    while (game->map[i][j])
    {
        j = 0;
        while (game->map[i][j] != '\n' && game->map[i][j] != '\0')
        {
            if (game->map[i][j] == 'C')
                count++;
            j++;
        }
        i++;
    }
    if (count <= 0)
        error();
    return (count);
}

int check_char(t_game *game)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    while (game->map[i][j])
    {
        j = 0;
        while (game->map[i][j] != '\n' && game->map[i][j] != '\0')
        {
            if (game->map[i][j] == '1' || game->map[i][j] == '0'
                || game->map[i][j] == 'E' || game->map[i][j] == 'C'
                || game->map[i][j] == 'P')
                j++;
            else
                error();
        }
        i++;
    }
    return (1);
}
int check_map(t_game *game)
{
    check_char(game);
    check_cols(game);
    check_hd(game);
    game->coin = check_coin(game);
    floodfill(game);
    return (1);
}