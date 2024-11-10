/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skalkan <skalkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 05:46:32 by skalkan           #+#    #+#             */
/*   Updated: 2024/11/10 18:59:15 by skalkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putchar(char s)
{
    write(1, &s, 1);
    return (1);
}

int ft_handle_format(char c, va_list arg)
{
    int count;

    count = 0;
    if (c == 'c')
        count += ft_putchar(va_arg(arg, int));
    else if (c == 's')
        count += ft_putstr(va_arg(arg,char *));
    else if (c == 'p')
        count += ft_pointer(va_arg(arg, unsigned long));
    else if (c == 'd' || c == 'i')
        count += ft_putnbr(va_arg(arg,int));
    else if (c == 'u')
        count += ft_unsigned(va_arg(arg,unsigned int));
    else if (c == '%')
		count += ft_putchar('%');
    else if (c == 'x')
        count += ft_recursive_hex(va_arg(arg,unsigned int),"0123456789abcdef");
    else if (c == 'X')
        count += ft_recursive_hex(va_arg(arg,unsigned int),"0123456789ABCDEF");
    return (count);
}

int ft_printf(const char *s, ...)
{
    va_list arg;
    int count;
    int i;

    count = 0;
    i = 0;
    va_start(arg,s);
    while (s[i])
    {
        if (s[i] != '%')
        {
            ft_putchar(s[i]);
            count++;
        }
        if (s[i] == '%')
        {
            i++;
            while (s[i] == ' ' && s[i])
                i++;
            count += ft_handle_format(s[i],arg);
        }
        i++;
    }
    return (count);
}