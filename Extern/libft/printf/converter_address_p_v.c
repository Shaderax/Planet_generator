/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_address_p_v.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouzeva <nrouzeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 03:35:39 by nrouzeva          #+#    #+#             */
/*   Updated: 2017/02/03 05:04:29 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_p_v(char **final_str, t_info *info, void *ap)
{
	char *res;

	res = ft_strdup("");
	buffcpy(final_str, info, "0x");
	res = ft_strjfri(res, ft_itoa_hexa((long long)ap, 16,
				"0123456789abcdef"), 3);
	info->width = info->width - 2;
	ft_option_apply_number(final_str, &res, info);
	ft_strdel(&res);
	return (1);
}
