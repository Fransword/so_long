/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francflo <francflo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:01:52 by francflo          #+#    #+#             */
/*   Updated: 2024/05/01 18:29:11 by francflo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
#define MAP_WIDTH 11 
#define MAP_HEIGHT 11 
# endif
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdarg.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
//# include "./MLX42/include/MLX42/MLX42.h

typedef struct s_image
{
    mlx_image_t     *floor;
    mlx_image_t     *wall;
    mlx_image_t     *hero;
    mlx_image_t     *coin;
    mlx_image_t     *door;
    mlx_image_t     *exit;
}   t_image;

typedef struct  s_game
{
    char        **map;
    int             line;
    int             cols;
    int             coin;
    int             playerx;
    int             playery;
    int             doorx;
    int             doory;
    int             count;
    mlx_image_t     *mlx;
    t_image         *image;   
}   t_game;

int		countx(char *argv);
int		county(char **map);
int		main(int argc, char **argv);
char	*get_next_line(int fd);
char	*new_storage(char *storage, char *line);
char	*ft_free(char **storage);
void	*ft_calloc(size_t num, size_t size);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*read_line(char *storage, int fd);
size_t	ft_strlen(char *str);

# endif