/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>          +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:10:14 by omartela          #+#    #+#             */
/*   Updated: 2024/05/01 16:11:28 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_puthexnbr_fd(unsigned int n, int fd, char format)
{
	if (n >= 16)
	{
		ft_puthexnbr_fd(n / 16, fd, format);
		ft_puthexnbr_fd(n % 16, fd, format);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd(n % 16 + '0', fd);
		else
		{
			if (format == 'X')
				ft_putchar_fd(n - 10 + 'A', fd);
			if (format == 'x')
				ft_putchar_fd(n - 10 + 'a', fd);
		}
	}
}

unsigned int	count_hexnbr(unsigned int hexnbr)
{
	unsigned int	count;

	count = 0;

	if (hexnbr == 0)
		return (1);
	while (hexnbr != 0)
	{
		hexnbr = hexnbr / 16;
		++count;
	}
	return (count);
}

unsigned int	ft_print_hexadecimal(va_list args, char format)
{
	unsigned int	hexnbr;

	hexnbr = va_arg(args, unsigned int);
	ft_puthexnbr_fd(hexnbr, 1, format);
	return (count_hexnbr(hexnbr));
}