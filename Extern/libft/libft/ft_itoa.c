/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouzeva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:52:37 by nrouzeva          #+#    #+#             */
/*   Updated: 2017/01/17 17:16:55 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_itoa(long long n)
{
	char				*str;
	int					len;
	int					i;
	unsigned long long	l_nb;

	i = 0;
	l_nb = n;
	len = ft_len_number(n, 10);
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
		str[len - i - 1] = (l_nb % 10) + 48;
		l_nb = (l_nb - l_nb % 10) / 10;
		i++;
	}
	str[len] = '\0';
	return (str);
}
