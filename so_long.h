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


# endif

# define MAP_WIDTH 11 
# define MAP_WEIGHT 11
# define PIXEL 64

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdarg.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "./MLX42/include/MLX42/MLX42.h"

typedef struct s_image
{
	mlx_image_t	*floor;
	mlx_image_t	*cols;
	mlx_image_t	*hero;
	mlx_image_t	*coin;
	mlx_image_t	*door;
	mlx_image_t	*exit;
}	t_image;

typedef struct s_game
{
	char	**map;
	int		line;
	int		cols;
	int		coin;
	int		playerx;
	int		playery;
	int		doorx;
	int		doory;
	int		count;
	mlx_t	*mlx;
	t_image	*image;
}	t_game;

void		ft_error(t_game *game);
int			countx(char *argv);
int			county(char **map, int lines);
char		**open_map(char *argv, int line);
static void	char_to_image(t_game *game, int i, int j);
static void	fill(char **map, int line, int cols);
int			windwalk(t_game *game);
void		freemap(char **map);
void		set_images(t_game *game);
void		end(t_game *game);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			strlen2(char *argv);
void		set_xy(t_game *game);
char		*ft_strdup(const char *s1);
char		**cmap(t_game *game);
int			check_cols(t_game *game);
int			check_hd(t_game *game);
int			check_coin(t_game *game);
int			check_char(t_game *game);
int			check_map(t_game *game);
char		*ft_strchr(char *str, int c);
void		*ft_calloc(size_t num, size_t size);
size_t		ft_strlen(char *str);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_free(char **s);
char		*new_storage(char *s, char *line);
char		*new_line(char *s);
char		*read_line(char *s, int fd);
char		*get_next_line(int fd);
int			print(char c, va_list args);
int			ft_printf(const char *format, ...);
char		*tipe_finder(char c);
int			putstr_c(char *s);
int			putchar_c(char c);
static int	write_nbr(int n, int count);
int			putnbr_c(int n);
void		keybinding(mlx_key_data_t keydata, void *param);
static void	char_to_image(t_game *game, int i, int j);
void		print_map(t_game *game);
mlx_texture_t	*set_img_floor(t_game *game);
mlx_texture_t	*set_img_cols(t_game *game);
mlx_texture_t	*set_img_door(t_game *game);
mlx_texture_t	*set_img_coin(t_game *game);
mlx_texture_t	*set_img_hero(t_game *game);

#endif