/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 08:47:40 by omartela          #+#    #+#             */
/*   Updated: 2024/05/10 12:21:16 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_format(const char *format, va_list args)
{
	int	rvalue;

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
		rvalue = write(1, "%", 1);
	return (rvalue);
}

static int	ft_print_helper(const char *format, va_list args)
{
	int	count;
	int	rvalue;

	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			rvalue = ft_format(++format, args);
			if (rvalue == -1)
				return (-1);
			count += rvalue;
		}
		else
		{
			if (write(1, format, 1) == -1)
				return (-1);
			++count;
		}
		if (!*format)
			return (0);
		++format;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	count = ft_print_helper(format, args);
	va_end(args);
	return (count);
}
