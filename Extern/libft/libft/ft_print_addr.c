/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouzeva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:52:37 by nrouzeva          #+#    #+#             */
/*   Updated: 2018/05/25 11:32:23 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_print_addr(unsigned long long n)
{
	char				base[16];

	ft_strcpy(base, "0123456789abcdef");
	if (n == 0)
		return ;
	ft_print_addr(n / 16);
	write(1, &base[n % 16], 1);
	return ;
}
