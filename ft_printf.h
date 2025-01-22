/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjupille <sjupille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:54:14 by sjupille          #+#    #+#             */
/*   Updated: 2024/11/18 15:53:46 by sjupille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int			ft_format(va_list args, const char c);
int			ft_printf(const char *format, ...);
int			ft_putchar(const char c);
int			ft_printstr(const char *s);
int			ft_printnbr(int n);
int			ft_printunsignbr(unsigned int n);
int			ft_printhexaptr(unsigned long long n, char *s);
int			ft_printhexa(unsigned int n, char *s);
int			ft_printptr(unsigned long long n, char *s);

#endif