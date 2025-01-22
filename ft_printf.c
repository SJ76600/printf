/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjupille <sjupille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:24:37 by sjupille          #+#    #+#             */
/*   Updated: 2024/11/19 10:52:58 by sjupille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list args, const char c)
{
	int		len;
	char	*min;
	char	*maj;

	len = 0;
	min = "0123456789abcdef";
	maj = "0123456789ABCDEF";
	if (c == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (c == 's')
		len += ft_printstr(va_arg(args, char *));
	else if (c == 'p')
		len += ft_printptr(va_arg(args, unsigned long long), min);
	else if (c == 'd' || c == 'i')
		len += ft_printnbr(va_arg(args, int));
	else if (c == 'u')
		len += ft_printunsignbr(va_arg(args, unsigned int));
	else if (c == 'x')
		len += ft_printhexa(va_arg(args, unsigned int), min);
	else if (c == 'X')
		len += ft_printhexa(va_arg(args, unsigned int), maj);
	else if (c == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = -1;
	len = 0;
	va_start(args, format);
	while (format[++i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			len += ft_format(args, format[i + 1]);
			i++;
		}
		else
			len += ft_putchar(format[i]);
	}
	va_end(args);
	return (len);
}

