/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_di_sd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouzeva <nrouzeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 03:36:55 by nrouzeva          #+#    #+#             */
/*   Updated: 2017/02/03 06:01:23 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_di_sd(char **final_str, t_info *info, void *ap)
{
	char	*res;

	res = ft_strdup("");
	if (info->length & L_HH)
		res = ft_strjfri(res, ft_itoa(*(signed char*)&ap), 3);
	else if (info->length & L_H)
		res = ft_strjfri(res, ft_itoa(*(short int*)&ap), 3);
	else if (info->length & L_L)
		res = ft_strjfri(res, ft_itoa(*(long int*)&ap), 3);
	else if (info->length & L_LL)
		res = ft_strjfri(res, ft_itoa(*(long long int*)&ap), 3);
	else if (info->length & L_J)
		res = ft_strjfri(res, ft_itoa(*(uintmax_t*)&ap), 3);
	else if (info->length & L_Z)
		res = ft_strjfri(res, ft_itoa(*(size_t*)&ap), 3);
	else if (info->length & L_T)
		res = ft_strjfri(res, ft_itoa(*(ptrdiff_t*)&ap), 3);
	else
		res = ft_strjfri(res, ft_itoa((*(int*)(&ap))), 3);
	ft_option_apply_number(final_str, &res, info);
	return (1);
}
