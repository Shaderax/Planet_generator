/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouzeva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:52:37 by nrouzeva          #+#    #+#             */
/*   Updated: 2016/12/21 10:14:39 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_itoa_base(long long n, int base, char *str2)
{
	char				*str;
	int					len;
	int					i;
	unsigned long long	l_nb;

	i = 0;
	l_nb = n;
	len = ft_len_number(l_nb, base);
	str = NULL;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (str);
	if (n < 0)
	{
		str[0] = '-';
		l_nb = -n;
	}
	while (i < (n < 0 ? len - 1 : len))
	{
		str[len - i - 1] = str2[l_nb % base];
		l_nb = l_nb / base;
		i++;
	}
	str[len] = '\0';
	return (str);
}
