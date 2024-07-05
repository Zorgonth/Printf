/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:59:24 by sal-zuba          #+#    #+#             */
/*   Updated: 2023/04/25 23:01:05 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_putchar(char c, int counter);
int		ft_type(va_list arg, int counter);
int		ft_putstr(va_list arg, int counter);
int		ft_pow(int n);
size_t	ft_strlen(const char *str);
int		ft_putnbr(va_list arg, int counter);
int		ft_digit(int n);
int		ft_unsigned(va_list arg, int counter);
int		ft_pointer(va_list arg, int counter);
int		ft_null(int counter);
int		ft_printf(const char *format, ...);
int		ft_digit3(unsigned long n);
int		ft_hex(va_list arg, int counter, char format);
int		ft_convert(unsigned long n, int counter, char c);

#endif