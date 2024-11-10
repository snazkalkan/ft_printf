/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fncs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skalkan <skalkan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 21:54:24 by skalkan           #+#    #+#             */
/*   Updated: 2024/11/10 19:20:47 by skalkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putstr(char *s)
{
    int count;

    count = 0;
    if (!s)
    {
        write (1, "(null)", 6);
        return(6);
    }
    while (s[count])
    {
        write(1, &s[count], 1);
        count++;
    }
    return (count);
}
int ft_putnbr(int a) // a = 42
{
    int count;

    count = 0;
    if (a == -2147483648)
    {
        write(1, "-2147483648", 11);
        return (11);
    }
    if (a < 0)
    {
        a = -a;
        count += ft_putchar('-');
    }
    if (a > 9)
    {
        count += ft_putnbr(a / 10); // a / 10 = 4
        count += ft_putnbr(a % 10); // a % 10 = 2
    }
    if (a <= 9)
        count += ft_putchar(a + '0'); // bu adımda '4' karakteri yazdırlır.
    return(count); // ft_putchar fonksiyonu her çağrıldığında 1 döner, yani count 1 artar. 
}

int ft_unsigned(unsigned int a)
{
    int count;

    count = 0;
    if (a <= 9)
        count += ft_putchar(a + '0');
    else
    {
        count += ft_unsigned(a / 10);
        count += ft_unsigned(a % 10);
    }
    return (count);
}
int ft_pointer(unsigned long p)
{
    int count;
    char *base; 
    char str[16];
    int i;

    count = 0;
    base = "0123456789abcdef";
    i = 0;
    if (!p)
    {
        write(1, "(nil)", 5);
        return 5;
    }
    write(1, "0x", 2);
    count += 2;
    while (p)
    {
        str[i++] = base[p % 16];
        p /= 16;
    }
    while (--i >= 0)
        count += ft_putchar(str[i]);
    return count;
}

int ft_recursive_hex(unsigned int p, char *base)
{
    int count;

    count = 0;
    if (p >= 16)
        count += ft_recursive_hex(p / 16, base);
    count += ft_putchar(base[p % 16]);
    return (count);
}
