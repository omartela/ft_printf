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
#include "unistd.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	while (*s != '\0')
	{
		ft_putchar_fd(*s, fd);
		++s;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-", 1);
		write(fd, "2", 1);
		n = 147483648;
	}
	else if (n < 0)
	{
		n = -1 * n;
		write(fd, "-", 1);
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	c = n % 10 + '0';
	write(fd, &c, 1);
}

unsigned int	ft_print_char(const char *format, va_list args)
{
	int c;

	c = va_arg(args, int);
	ft_putchar_fd(c, 1);
	return (1);

}

unsigned int	ft_print_str(const char *format, va_list args)
{
	char *str;
	unsigned count;

	count = 0;
	str = va_arg(args, char*);
	ft_putstr_fd(str, 1);
	while (*str)
	{
		++count;
		++str;
	}
	return (count);
}

unsigned int	count_digit(int n)
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

unsigned int ft_print_nbr(const char *format, va_list args)
{
	int nbr;

	nbr = va_arg(args, int);
	ft_putnbr_fd(nbr, 1);
	return (count_digit(nbr));
}

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

void	ft_putunsnbr_fd(unsigned int n, int fd)
{
	if (n >= 10)
	{
		ft_putunsnbr_fd(n / 10, fd);
	}
	ft_putchar_fd(n % 10 + '0', fd);
}

unsigned int	ft_print_unsnbr(const char *format, va_list args)
{
	unsigned int unsnbr;

	unsnbr = va_arg(args, unsigned int);
	ft_putunsnbr_fd(unsnbr, 1);
	return (count_unsdigit(unsnbr));
}

void	ft_puthexnbr_fd(unsigned int n, int fd, char formatter)
{
	if (n >= 16)
	{
		ft_puthexnbr_fd(n / 16, fd, formatter);
		ft_puthexnbr_fd(n % 16, fd, formatter);
	}
	else
		if (n <= 9)
			ft_putchar_fd(n % 16 + '0', fd);
		else
		{
			if (formatter == 'X')
				ft_putchar_fd(n - 10 + 'A', fd);
			if (formatter == 'x')
				ft_putchar_fd(n - 10 + 'a', fd);
		}
}

unsigned int	count_hexnbr(unsigned int hexnbr)
{
	unsigned int count;

	count = 0;

	if (hexnbr == 0)
		return (1);
	while (hexnbr != 0)
	{
		hexnbr = hexnbr / 16;
		++count;
	}
	return (count);
}

unsigned int	ft_print_hexadecimal(const char *format, va_list args, char formatter)
{
	unsigned int hexnbr;

	hexnbr = va_arg(args, unsigned int);
	ft_puthexnbr_fd(hexnbr, 1, formatter);
	return (count_hexnbr(hexnbr));
}

void ft_putptr_fd(uintptr_t ptr, int fd)
{
	
	if (ptr >= 16)
	{
		ft_putptr_fd(ptr / 16, fd);
		ft_putptr_fd(ptr % 16, fd);
	}
	else
		if (ptr <= 9)
			ft_putchar_fd(ptr % 16 + '0', fd);
		else
		{
			ft_putchar_fd(ptr - 10 + 'A', fd);
		}
}

unsigned int	count_ptr(uintptr_t ptr)
{
	unsigned count;

	count = 0;
	while (ptr != 0)
	{
		ptr = ptr / 16;
		++count;
	}
	return(count);
}

unsigned int	ft_print_ptr(const char *format, va_list args)
{
	void *ptr;

	ptr = va_arg(args, void *);
	ft_putptr_fd((uintptr_t)ptr, 1);
	return (count_ptr((uintptr_t)ptr));
}

unsigned int ft_format(const char *format, va_list args, unsigned count)
{
	if (*format == 'c')
		count += ft_print_char(format, args);
	else if (*format == 's')
		count += ft_print_str(format, args);
	else if (*format == 'p')
		count += ft_print_ptr(format, args);
	else if (*format == 'i' || *format == 'd')
		count += ft_print_nbr(format, args);
	else if (*format == 'u')
		count += ft_print_unsnbr(format, args);
	else if (*format == 'x' || *format == 'X')
		count += ft_print_hexadecimal(format, args, *format);
	else if (*format == '%')
	{
		ft_putchar_fd('%', 1);
		++count;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list args;
	int count;

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

#include <stdio.h>
int main(void) {
    char c = 'A';
    char *s = "Hello, world!";
    int d = -42;
    int i = 123;
    unsigned int u = 4294967295; // Maximum value of unsigned int
    uintptr_t p = (uintptr_t)&c; // Address of variable c
    printf("Testing ft_printf:\n");

    // Test cases
    ft_printf("%%c: %c\n", c);
    ft_printf("%%s: %s\n", s);
    ft_printf("%%p: %p\n", p);
    ft_printf("%%d: %d\n", d);
    ft_printf("%%i: %i\n", i);
    ft_printf("%%u: %u\n", u);
    ft_printf("%%x: %x\n", u);
    ft_printf("%%X: %X\n", u);

    // Compare with original printf
    printf("\nTesting original printf:\n");
    printf("%%c: %c\n", c);
    printf("%%s: %s\n", s);
    printf("%%p: %p\n", p);
    printf("%%d: %d\n", d);
    printf("%%i: %i\n", i);
    printf("%%u: %u\n", u);
    printf("%%x: %x\n", u);
    printf("%%X: %X\n", u);

    return 0;
}

