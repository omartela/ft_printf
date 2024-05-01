/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 08:47:40 by omartela          #+#    #+#             */
/*   Updated: 2024/04/30 08:47:40 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

unsigned int	ft_format(const char *format, va_list args, unsigned int count)
{
	if (*format == 'c')
		count += ft_print_char(args);
	else if (*format == 's')
		count += ft_print_str(args);
	else if (*format == 'p')
		count += ft_print_ptr(args);
	else if (*format == 'i' || *format == 'd')
		count += ft_print_nbr(args);
	else if (*format == 'u')
		count += ft_print_unsnbr(args);
	else if (*format == 'x' || *format == 'X')
		count += ft_print_hexadecimal(args, *format);
	else if (*format == '%')
	{
		ft_putchar_fd('%', 1);
		++count;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			count = ft_format(++format, args, count);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			++count;
		}
		++format;
	}
	va_end(args);
	return (count);
}
