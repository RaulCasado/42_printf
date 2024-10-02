/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:56:54 by racasado          #+#    #+#             */
/*   Updated: 2024/10/01 11:29:37 by racasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(const char *format, va_list argcs, int i)
{
	if (format[i] == 's')
		return (ft_putstring(argcs));
	else if (format[i] == 'c')
		return (ft_putchar(argcs));
	else if (format[i] == '%')
		return (ft_percentage());
	else if (format[i] == 'p')
		return (ft_putpointer(argcs));
	else if (format[i] == 'x')
		return (ft_putnbr_base(argcs, "0123456789abcdef", 0));
	else if (format[i] == 'X')
		return (ft_putnbr_base(argcs, "0123456789ABCDEF", 0));
	else if (format[i] == 'd' || format[i] == 'i')
		return (ft_putnbr_base(argcs, "0123456789", 1));
	else if (format[i] == 'u')
		return (ft_putnbr_base(argcs, "0123456789", 0));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	argcs;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(argcs, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_format(format, argcs, i);
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(argcs);
	return (count);
}
