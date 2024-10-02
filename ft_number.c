/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:54:07 by racasado          #+#    #+#             */
/*   Updated: 2024/09/20 19:35:10 by racasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(va_list argcs, char *base, int is_signed)
{
	long long	n;
	char		*str;
	int			len;

	if (is_signed)
		n = va_arg(argcs, int);
	else
		n = va_arg(argcs, unsigned int);
	str = itoa_base(n, base, is_signed);
	if (!str)
		return (0);
	write(1, str, ft_strlen(str));
	len = ft_strlen(str);
	free(str);
	return (len);
}
