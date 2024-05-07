/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>          +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:10:14 by omartela          #+#    #+#             */
/*   Updated: 2024/05/07 16:29:54 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_puthexnbr(unsigned int n, char f, int *cn)
{
	char	c;

	if (n >= 16)
	{
		if (ft_puthexnbr(n / 16, f, cn) == -1)
			return (-1);
		if (ft_puthexnbr(n % 16, f, cn) == -1)
			return (-1);
	}
	else
	{
		if (n <= 9)
			c = n % 16 + '0';
		else
			c = n - 10 + f;
		if (write(1, &c, 1) == -1)
			return (-1);
		else
			*cn += 1;
	}
	return (*cn);
}

int	ft_print_hexadecimal(va_list args, char format)
{
	unsigned int	hexnbr;
	int				count;

	count = 0;
	hexnbr = va_arg(args, unsigned int);
	if (format == 'X')
		format = 'A';
	else
		format = 'a';
	return (ft_puthexnbr(hexnbr, format, &count));
}
