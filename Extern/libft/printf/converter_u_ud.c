/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_u_ud.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouzeva <nrouzeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 03:32:09 by nrouzeva          #+#    #+#             */
/*   Updated: 2017/02/03 06:01:42 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_u_ud(char **final_str, t_info *info, void *ap)
{
	char		*res;
	long long	n;

	res = ft_strdup("");
	n = ft_length_converter(info, ap);
	res = ft_strjfri(res, ft_itoa_ull(n, 10), 3);
	ft_option_apply_number(final_str, &res, info);
	return (1);
}
