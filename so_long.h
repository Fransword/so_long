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
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
//# include "./MLX42/include/MLX42/MLX42.h

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
//char    **open_map(char *argv, int *rows, int *cols);

# endif