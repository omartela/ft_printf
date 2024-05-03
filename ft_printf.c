/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 08:47:40 by omartela          #+#    #+#             */
/*   Updated: 2024/05/03 15:08:08 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_format(const char *format, va_list args, unsigned int count)
{
	int rvalue;

	rvalue = 0;
	if (*format == 'c')
		rvalue = ft_print_char(args);
	else if (*format == 's')
		rvalue = ft_print_str(args);
	else if (*format == 'p')
		rvalue = ft_print_ptr(args);
	else if (*format == 'i' || *format == 'd')
		rvalue = ft_print_nbr(args);
	else if (*format == 'u')
		rvalue = ft_print_unsnbr(args);
	else if (*format == 'x' || *format == 'X')
		rvalue = ft_print_hexadecimal(args, *format);
	else if (*format == '%')
	{
		rvalue = write(1,'%', 1);
	}
	if (rvalue < 0)
		return (rvalue);
	count += rvalue;
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
