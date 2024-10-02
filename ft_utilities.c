/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:09:29 by racasado          #+#    #+#             */
/*   Updated: 2024/09/20 19:35:45 by racasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_variables(char *str, long long n, char *base, int len)
{
	if (n == 0)
		*str = *base;
	str[len] = '\0';
}

char	*itoa_base(long long n, char *base, int is_signed)
{
	char	*str;
	int		len;
	int		base_len;
	int		is_negative;

	is_negative = 0;
	base_len = ft_strlen(base);
	if (is_signed && n < 0)
	{
		is_negative = 1;
		n = -n;
	}
	len = ft_nbrlen(n, base_len) + is_negative;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	set_variables(str, n, base, len);
	while (len-- > is_negative)
	{
		str[len] = base[n % base_len];
		n /= base_len;
	}
	if (is_negative)
		str[0] = '-';
	return (str);
}

static int	ft_pointer_len(unsigned long long n, int base_len)
{
	int	len;

	len = 1;
	while (n >= (unsigned long long)base_len)
	{
		n /= base_len;
		len++;
	}
	return (len);
}

char	*pointer_to_string(unsigned long long n, char *base)
{
	char	*str;
	int		len;
	int		base_len;

	base_len = ft_strlen(base);
	len = ft_pointer_len(n, base_len);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = base[n % base_len];
		n /= base_len;
	}
	return (str);
}
