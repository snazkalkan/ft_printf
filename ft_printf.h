/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpancar <bpancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 16:29:58 by skalkan           #+#    #+#             */
/*   Updated: 2024/11/11 20:33:24 by bpancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	ft_putchar(char s);
int	ft_putnbr(int a);
int	ft_putstr(char *s);
int	ft_unsigned(unsigned int a);
int	ft_pointer(unsigned long p);
int	ft_recursive_hex(unsigned int p, char *base);
int	ft_handle_format(char c, va_list arg);

#endif