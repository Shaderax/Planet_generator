/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouzeva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:52:37 by nrouzeva          #+#    #+#             */
/*   Updated: 2018/05/24 15:28:17 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int			ft_len_number_hexa(unsigned long long n, int base)
{
	int					len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / base;
	}
	return (len);
}

char		*ft_itoa_hexa(unsigned long long n, int base, char *str2)
{
	char				*str;
	int					len;
	int					i;

	if (n == 0)
	{
		return (ft_strdup("0"));
	}
	i = 0;
	len = ft_len_number_hexa(n, base);
	str = NULL;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (str);
	while (i < len)
	{
		str[len - i - 1] = str2[n % base];
		n = n / base;
		i++;
	}
	str[len] = '\0';
	return (str);
}
