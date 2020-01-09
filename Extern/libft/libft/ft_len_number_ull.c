/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouzeva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:47:17 by nrouzeva          #+#    #+#             */
/*   Updated: 2017/01/18 15:11:18 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len_number_ull(unsigned long long n, int base)
{
	int		len;

	len = 0;
	while (n != n % base)
	{
		len++;
		n = (n - n % base) / base;
	}
	len++;
	return (len);
}
