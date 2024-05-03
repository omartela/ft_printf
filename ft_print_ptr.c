/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 16:06:51 by omartela          #+#    #+#             */
/*   Updated: 2024/05/02 14:52:14 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putptr_fd(uintptr_t ptr, int fd)
{
	if (ptr >= 16)
	{
		ft_putptr_fd(ptr / 16, fd);
		ft_putptr_fd(ptr % 16, fd);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar_fd(ptr % 16 + '0', fd);
		else
			ft_putchar_fd(ptr - 10 + 'a', fd);
	}
}

unsigned int	count_ptr(uintptr_t ptr)
{
	unsigned int	count;

	count = 2;
	while (ptr != 0)
	{
		ptr = ptr / 16;
		++count;
	}
	return (count);
}

unsigned int	ft_print_ptr(va_list args)
{
	void	*ptr;

	ptr = va_arg(args, void *);
	printf("0x");
	ft_putptr_fd((uintptr_t)ptr, 1);
	return (count_ptr((uintptr_t)ptr));
}
