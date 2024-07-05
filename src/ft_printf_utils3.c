/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-zuba <sal-zuba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:15:24 by sal-zuba          #+#    #+#             */
/*   Updated: 2023/04/25 23:19:51 by sal-zuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_digit3(unsigned long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_convert(unsigned long n, int counter, char c)
{
	int		remain;
	char	*str;
	int		i;

	i = 0;
	str = malloc(ft_digit3(n) + 1);
	if (!str)
		return (0);
	remain = 0;
	while (n > 0)
	{
		remain = n % 16;
		if (remain < 10)
			str[i] = '0' + remain;
		else
			str[i] = c + (remain - 10);
		n = n / 16;
		i++;
	}
	str[i] = '\0';
	while (--i >= 0)
		counter = ft_putchar(str[i], counter);
	free(str);
	return (counter);
}

int	ft_null(int counter)
{
	char	*tmp;
	int		i;

	tmp = "(null)";
	i = ft_strlen(tmp);
	counter += i;
	write(1, tmp, i);
	return (counter);
}
