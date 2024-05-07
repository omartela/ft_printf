/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:24:47 by omartela          #+#    #+#             */
/*   Updated: 2024/05/07 20:34:08 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_char(va_list args)
{
	int	c;

	c = va_arg(args, int);
	return (write(1, &c, 1));
}

int	ft_print_str(va_list args)
{
	char			*str;
	unsigned int	count;

	count = 0;
	str = va_arg(args, char *);
	if (!str)
		return (write(1, "(null)", 6));
	while (str[count])
		++count;
	return (write(1, str, count));
}

int	ft_putnbr(long n, int *count)
{
	char	c;

	if (n < 0)
	{
		n = -1 * n;
		if (write(1, "-", 1) == -1)
			return (-1);
		*count += 1;
	}
	if (n >= 10)
		if (ft_putnbr(n / 10, count) == -1)
			return (-1);
	c = n % 10 + '0';
	if (write(1, &c, 1) == -1)
		return (-1);
	*count += 1;
	return (*count);
}

int	ft_print_nbr(va_list args)
{
	int	nbr;
	int	count;

	count = 0;
	nbr = va_arg(args, int);
	return (ft_putnbr(nbr, &count));
}
