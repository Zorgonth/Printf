/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:12:50 by sal-zuba          #+#    #+#             */
/*   Updated: 2023/04/25 23:19:45 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_pow(int n)
{
	int	res;

	res = 1;
	while (n > 1)
	{
		res *= 10;
		n--;
	}
	return (res);
}

int	ft_digit(int n)
{
	int				i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_hex(va_list arg, int counter, char format)
{
	unsigned int	n;

	n = va_arg(arg, unsigned int);
	if (n == 0)
		counter = ft_putchar('0', counter);
	if (format == 'x')
		counter = ft_convert(n, counter, 'a');
	else if (format == 'X')
		counter = ft_convert(n, counter, 'A');
	return (counter);
}

int	ft_unsigned(va_list arg, int counter)
{
	unsigned int	n;
	int				x;

	n = va_arg(arg, unsigned int);
	x = ft_digit3(n);
	while (x > 0)
	{
		counter = ft_putchar((n / ft_pow(x)) + 48, counter);
		n = n % ft_pow(x);
		x--;
	}
	return (counter);
}

int	ft_pointer(va_list arg, int counter)
{
	unsigned long		n;

	n = va_arg(arg, unsigned long);
	counter = ft_putchar('0', counter);
	counter = ft_putchar('x', counter);
	if (n == 0)
		counter = ft_putchar('0', counter);
	else
		counter = ft_convert(n, counter, 'a');
	return (counter);
}
