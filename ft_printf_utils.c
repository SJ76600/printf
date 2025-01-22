/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjupille <sjupille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 08:20:50 by sjupille          #+#    #+#             */
/*   Updated: 2024/11/19 10:52:45 by sjupille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(const char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(const char *s)
{
	int	i;

	i = -1;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[++i])
		write(1, &s[i], 1);
	return (i);
}

int	ft_printnbr(int n)
{
	int		len;
	long	nb;

	len = 0;
	nb = n;
	if (nb < 0)
	{
		len += ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
	{
		len += ft_printnbr(nb / 10);
		len += ft_printnbr(nb % 10);
	}
	else
		len += ft_putchar(nb % 10 + '0');
	return (len);
}

int	ft_printunsignbr(unsigned int n)
{
	int	len;

	len = 0;
	if (n > 9)
	{
		len += ft_printnbr(n / 10);
		len += ft_printnbr(n % 10);
	}
	else
		len += ft_putchar(n % 10 + '0');
	return (len);
}
