/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>          +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:10:14 by omartela          #+#    #+#             */
/*   Updated: 2024/05/03 13:54:03 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_puthexnbr_fd(unsigned int n, int fd, char format)
{
	int	count;

	count = 0;
	if (n >= 16)
	{
		ft_puthexnbr_fd(n / 16, fd, format);
		ft_puthexnbr_fd(n % 16, fd, format);
	}
	else
	{
		if (n <= 9)
			write(1, n % 16 + '0', 1);
		else
		{
			if (format == 'X')
				count += write(1, n - 10 + 'A', 1);
			if (format == 'x')
				count += write(1, n - 10 + 'a', 1);
		}
	}
	return (count);
}

unsigned int	ft_print_hexadecimal(va_list args, char format)
{
	unsigned int	hexnbr;

	hexnbr = va_arg(args, unsigned int);
	return (ft_puthexnbr_fd(hexnbr, 1, format));
}
