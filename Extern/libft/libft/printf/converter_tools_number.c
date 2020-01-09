/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i_douxX.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouzeva <nrouzeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 15:57:52 by nrouzeva          #+#    #+#             */
/*   Updated: 2017/02/03 03:31:48 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stddef.h>
#include <stdint.h>

unsigned long long	ft_length_converter(t_info *info, void *ap)
{
	unsigned long long	n;

	n = 0;
	if (info->length & L_HH)
		n = *(unsigned char*)&ap;
	else if (info->length & L_H)
		n = *(unsigned short int*)&ap;
	else if (info->length & L_L)
		n = *(unsigned long int*)&ap;
	else if (info->length & L_LL)
		n = *(unsigned long long*)&ap;
	else if (info->length & L_J)
		n = *(uintmax_t*)&ap;
	else if (info->length & L_Z)
		n = *(size_t*)&ap;
	else if (info->length & L_T)
		n = *(ptrdiff_t*)&ap;
	else
		n = *(unsigned int*)&ap;
	return (n);
}

int					ft_pourcentage_c(char **final_str, t_info *info, void *ap)
{
	char *res;

	ap = NULL;
	res = ft_strdup("");
	res = ft_strjfri(res, "%", 1);
	ft_option_apply_caractere(final_str, res, info);
	ft_strdel(&res);
	return (1);
}
