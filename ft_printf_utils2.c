/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjupille <sjupille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:33:54 by sjupille          #+#    #+#             */
/*   Updated: 2024/11/18 16:00:46 by sjupille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhexaptr(unsigned long long n, char *s)
{
	int	len;

	len = 0;
	if (n > 15)
	{
		len += ft_printhexaptr(n / 16, s);
		len += ft_printhexaptr(n % 16, s);
	}
	else
		len += ft_putchar(s[n % 16]);
	return (len);
}

int	ft_printptr(unsigned long long n, char *s)
{
	int	len;

	len = 0;
	if (!n)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	if (n > 0)
		len += ft_printstr("0x");
	len += ft_printhexaptr(n, s);
	return (len);
}

int	ft_printhexa(unsigned int n, char *s)
{
	int	len;

	len = 0;
	if (n > 15)
	{
		len += ft_printhexa(n / 16, s);
		len += ft_printhexa(n % 16, s);
	}
	else
		len += ft_putchar(s[n % 16]);
	return (len);
}
