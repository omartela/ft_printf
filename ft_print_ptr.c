/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:35:18 by omartela          #+#    #+#             */
/*   Updated: 2024/05/10 12:33:55 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_putptr(unsigned long ptr, int *count)
{
	char	c;

	if (ptr >= 16)
	{
		if (ft_putptr(ptr / 16, count) == -1)
			return (-1);
		if (ft_putptr(ptr % 16, count) == -1)
			return (-1);
	}
	else
	{
		if (ptr <= 9)
			c = ptr + '0';
		else
			c = ptr - 10 + 'a';
		if (write(1, &c, 1) == -1)
			return (-1);
		else
			*count += 1;
	}
	return (*count);
}

int	ft_print_ptr(va_list args)
{
	void	*ptr;
	int		count;

	count = 0;
	ptr = va_arg(args, void *);
	if (write(1, "0x", 2) == -1)
		return (-1);
	count += 2;
	ft_putptr((unsigned long)ptr, &count);
	return (count);
}
