/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:38:38 by racasado          #+#    #+#             */
/*   Updated: 2024/09/23 12:26:47 by racasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer(va_list argcs)
{
	void				*pointer;
	unsigned long long	pointer_adress;
	char				*str;
	int					len;

	pointer = va_arg(argcs, void *);
	pointer_adress = (unsigned long long)pointer;
	if (pointer == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	str = pointer_to_string(pointer_adress, "0123456789abcdef");
	if (!str)
		return (0);
	write(1, "0x", 2);
	len = ft_strlen(str) + 2;
	write(1, str, ft_strlen(str));
	free(str);
	return (len);
}
