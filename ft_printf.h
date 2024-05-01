/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:59:29 by omartela          #+#    #+#             */
/*   Updated: 2024/05/01 15:33:31 by omartela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include "libft/libft.h"
# include <stdarg.h>

unsigned int	ft_print_char(va_list args);
unsigned int	ft_print_str(va_list args);
unsigned int	count_digit(int n);
unsigned int	count_unsdigit(unsigned int n);
void			ft_putunsnbr_fd(unsigned int n, int fd);
unsigned int	ft_print_unsnbr(va_list args);
void			ft_puthexnbr_fd(unsigned int n, int fd, char format);
unsigned int	count_hexnbr(unsigned int hexnbr);
unsigned int	ft_print_hexadecimal(va_list args, char format);
void			ft_putptr_fd(uintptr_t ptr, int fd);
unsigned int	count_ptr(uintptr_t ptr);
unsigned int	ft_print_ptr(va_list args);
unsigned int	ft_format(const char *format, va_list args, unsigned int count);
int				ft_printf(const char *format, ...);
unsigned int	ft_print_nbr(va_list args);
int				ft_printf(const char *format, ...);

#endif
