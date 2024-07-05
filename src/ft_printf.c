/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:51:47 by sal-zuba          #+#    #+#             */
/*   Updated: 2023/12/21 11:37:43 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_check(va_list list, const char *format, int ind, int counter)
{
	if (format[ind] == 'c')
		counter = ft_type(list, counter);
	else if (format[ind] == 's')
		counter = ft_putstr(list, counter);
	else if (format[ind] == 'd' || format[ind] == 'i')
		counter = ft_putnbr(list, counter);
	else if (format[ind] == 'u')
		counter = ft_unsigned(list, counter);
	else if (format[ind] == 'p')
		counter = ft_pointer(list, counter);
	else if (format[ind] == 'x' || format[ind] == 'X')
		counter = ft_hex(list, counter, format[ind]);
	else if (format[ind] == '%')
		counter = ft_putchar('%', counter);
	return (counter);
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		counter;
	int		ind;

	va_start(list, format);
	ind = 0;
	counter = 0;
	while (format[ind])
	{
		if (format[ind] == '%')
		{
			counter = ft_check(list, format, ++ind, counter);
			if (format[ind + 1] == '\0')
				break ;
			else
				ind++;
		}
		if (format[ind] != '%')
		{
			counter = ft_putchar(format[ind], counter);
			ind++;
		}
	}
	va_end(list);
	return (counter);
}
