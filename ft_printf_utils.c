/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:24:47 by omartela          #+#    #+#             */
/*   Updated: 2024/05/01 16:24:56 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

unsigned int	ft_print_char(va_list args)
{
	int	c;

	c = va_arg(args, int);
	ft_putchar_fd(c, 1);
	return (1);

}

unsigned int	ft_print_str(va_list args)
{
	char			*str;
	unsigned int	count;

	count = 0;
	str = va_arg(args, char *);
	ft_putstr_fd(str, 1);
	while (*str)
	{
		++count;
		++str;
	}
	return (count);
}

unsigned int	count_digit(int n)
{
	unsigned int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		++count;
	}
	return (count);
}

unsigned int	ft_print_nbr(va_list args)
{
	int	nbr;

	nbr = va_arg(args, int);
	ft_putnbr_fd(nbr, 1);
	return (count_digit(nbr));
}

