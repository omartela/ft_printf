/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:06:51 by omartela          #+#    #+#             */
/*   Updated: 2024/05/03 14:06:56 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putptr_fd(unsigned long ptr)
{
	int count;

	count = 0;
	if (ptr >= 16)
	{
		ft_putptr_fd(ptr / 16);
		ft_putptr_fd(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			count += write(ptr % 16 + '0', 1);
		else
			count += write(ptr - 10 + 'a', 1);
	}
	return (count);
}

unsigned int	ft_print_ptr(va_list args)
{
	void	*ptr;

	ptr = va_arg(args, void *);
	return (ft_putptr_fd((unsigned long)ptr));
}
