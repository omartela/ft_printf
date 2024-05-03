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

unsigned int	count_unsdigit(unsigned int n)
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

int	ft_putunsnbr_fd(unsigned int n)
{
	int count;

	count = 0;
	if (n >= 10)
	{
		ft_putunsnbr_fd(n / 10);
	}
	count += write(n % 10 + '0', 1);
	return (count);
}

unsigned int	ft_print_unsnbr(va_list args)
{
	unsigned int	unsnbr;

	unsnbr = va_arg(args, unsigned int);
	return (ft_putunsnbr_fd(unsnbr));
}
