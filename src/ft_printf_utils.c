/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:56:50 by sal-zuba          #+#    #+#             */
/*   Updated: 2023/04/25 23:19:36 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int	ft_putchar(char c, int counter)
{
	write(1, &c, 1);
	counter++;
	return (counter);
}

int	ft_putstr(va_list arg, int counter)
{
	int		i;
	char	*s;

	s = va_arg(arg, char *);
	i = ft_strlen(s);
	if (s == NULL)
		counter = ft_null(counter);
	counter += i;
	write(1, s, i);
	return (counter);
}

int	ft_type(va_list arg, int counter)
{
	int	d;

	d = va_arg(arg, int);
	write(1, &d, 1);
	counter++;
	return (counter);
}

int	ft_putnbr(va_list arg, int counter)
{
	unsigned int	i;
	int				n;
	int				x;

	n = va_arg(arg, int);
	x = ft_digit(n);
	if (n < 0)
	{
		counter = ft_putchar('-', counter);
		i = (unsigned int)n * -1;
	}
	else
		i = (unsigned int)n;
	while (x > 0)
	{
		counter = ft_putchar((i / ft_pow(x)) + 48, counter);
		i = i % ft_pow(x);
		x--;
	}
	return (counter);
}
