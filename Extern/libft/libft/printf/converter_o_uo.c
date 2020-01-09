/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_o_uo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouzeva <nrouzeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 03:36:38 by nrouzeva          #+#    #+#             */
/*   Updated: 2017/02/03 03:36:39 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_o_uo(char **final_str, t_info *info, void *ap)
{
	char		*res;
	long long	n;

	res = ft_strdup("");
	if (info->length & L_L || info->length & L_LL || info->length & L_J
			|| info->length & L_Z)
		res = ft_strjfri(res, ft_itoa_ull(*(unsigned long*)&ap, 8), 3);
	else
	{
		n = ft_length_converter(info, ap);
		res = ft_strjfri(res, ft_itoa_base(n, 8, "0123456789"), 3);
	}
	if (FL_DS & info->flags && res[0] != '0')
		res = ft_strjfri("0", res, 2);
	ft_option_apply_octal(final_str, res, info);
	ft_strdel(&res);
	return (1);
}
