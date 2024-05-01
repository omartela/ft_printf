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

# ifndef FT_PRINTF.H
# define FT_PRINTF.H

# include <unistd.h>
# include <stdarg.h>

unsigned int	ft_print_char(const char *format, va_list args);
unsigned int	ft_print_str(const char *format, va_list args);
unsigned int	count_digit(int n);
unsigned int	count_unsdigit(unsigned int n);
void			ft_putunsnbr_fd(unsigned int n, int fd);
unsigned int	ft_print_unsnbr(const char *format, va_list args);
void			ft_puthexnbr_fd(unsigned int n, int fd, char formatter);
unsigned int	count_hexnbr(unsigned int hexnbr);
unsigned int	ft_print_hexadecimal(const char *format, va_list args, char formatter);
void 			ft_putptr_fd(uintptr_t ptr, int fd);
unsigned int	count_ptr(uintptr_t ptr);
unsigned int	ft_print_ptr(const char *format, va_list args);
unsigned int 	ft_format(const char *format, va_list args, unsigned count);
int				ft_printf(const char *format, ...);

# endif
