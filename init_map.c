/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francflo <francflo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 00:28:45 by francflo          #+#    #+#             */
/*   Updated: 2024/05/04 00:28:45 by francflo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

/*int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Uso: %s <archivo del mapa>\n", argv[0]);
        exit(1);
    }

    int rows, cols;
    char **map = open_map(argv[1], &rows, &cols);

    // Hacer algo con el mapa, como imprimirlo
    printf("Mapa abierto exitosamente:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }

    // Liberar la memoria asignada para el mapa
    for (int i = 0; i < rows; i++)
    {
        free(map[i]);
    }
    free(map);
    return 0;
}*/