/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:59:29 by omartela          #+#    #+#             */
/*   Updated: 2024/05/07 16:54:16 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <unistd.h>
# include <stdarg.h>

int				ft_print_char(va_list args);
int				ft_print_str(va_list args);
int				ft_putnbr(int n, int *count);
int				ft_putunsnbr(unsigned int n, int *count);
int				ft_print_unsnbr(va_list args);
int				ft_puthexnbr(unsigned int n, char f, int *cn);
int				ft_print_hexadecimal(va_list args, char format);
int				ft_putptr(unsigned long ptr, int *count);
int				ft_print_ptr(va_list args);
int				ft_format(const char *format, va_list args);
int				ft_printf(const char *format, ...);
int				ft_print_nbr(va_list args);

#endif
