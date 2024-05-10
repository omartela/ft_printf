/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsnbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:13:08 by omartela          #+#    #+#             */
/*   Updated: 2024/05/10 12:13:12 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_putunsnbr(unsigned int n, int *count)
{
	char	c;

	if (n >= 10)
		if (ft_putunsnbr(n / 10, count) == -1)
			return (-1);
	c = n % 10 + '0';
	if (write(1, &c, 1) == -1)
		return (-1);
	else
		*count += 1;
	return (*count);
}

int	ft_print_unsnbr(va_list args)
{
	unsigned int	unsnbr;
	int				count;

	count = 0;
	unsnbr = va_arg(args, unsigned int);
	return (ft_putunsnbr(unsnbr, &count));
}
