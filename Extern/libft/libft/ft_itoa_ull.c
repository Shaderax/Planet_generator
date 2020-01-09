/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouzeva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:52:37 by nrouzeva          #+#    #+#             */
/*   Updated: 2017/01/18 19:30:21 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_itoa_ull(unsigned long long n, int base)
{
	char				*str;
	int					len;
	int					i;

	i = 0;
	len = ft_len_number_ull(n, base);
	str = NULL;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (str);
	while (i < len)
	{
		str[len - i - 1] = (n % base) + 48;
		n = (n - n % base) / base;
		i++;
	}
	str[len] = '\0';
	return (str);
}
