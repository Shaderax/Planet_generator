/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouzeva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:47:17 by nrouzeva          #+#    #+#             */
/*   Updated: 2016/12/19 17:08:30 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len_number(long long n, int base)
{
	int		len;
	long	l_nb;

	l_nb = n;
	len = 0;
	if (n < 0)
	{
		l_nb = -n;
		len++;
	}
	while (l_nb != l_nb % base)
	{
		len++;
		l_nb = (l_nb - l_nb % base) / base;
	}
	len++;
	return (len);
}
