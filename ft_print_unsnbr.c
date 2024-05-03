/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsnbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:13:08 by omartela          #+#    #+#             */
/*   Updated: 2024/05/03 14:11:37 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putunsnbr(unsigned int n)
{
	int	count;
	int	rvalue;

	count = 0;
	if (n >= 10)
	{
		ft_putunsnbr(n / 10);
	}
	rvalue = write(1, n % 10 + '0', 1);
	if (rvalue < 0)
		return (-1);
	count += rvalue;
	return (count);
}

unsigned int	ft_print_unsnbr(va_list args)
{
	unsigned int	unsnbr;

	unsnbr = va_arg(args, unsigned int);
	return (ft_putunsnbr(unsnbr));
}
