/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francflo <francflo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 12:19:42 by francflo          #+#    #+#             */
/*   Updated: 2024/06/16 12:19:42 by francflo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int print(char c, va_list args)
{
    int     i;

    i = 0;
    if (c == 'c')
        i = putchar_c(va_args(args, int));
    else if (c == 's')
        i = putstr_c(va_args(args, char *));
    else if (c == 'd' || c == 'i')
        i = putnbr_c(va_args(args, int));
    else if (c == '%')
        i = putchar_c('%');
    return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	unsigned int		i;
	unsigned int		j;
    int                 k;

	i = -1;
	j = 0;
	va_start(args, format);
    while (format[++i])
    {
        if (format[i] == '%' && tipe_finder(format[i + 1]))
        {
            k = print(format[++i]. args)
            if (k < 0)
                return (-1);
            j += k - 1;
        }
        else
            if (write(1, &format[i], 1) < 0)
                return (-1);
            j++;
    }
	va_end(args);
	return (j);
}