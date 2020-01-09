/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_CcSsp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouzeva <nrouzeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 16:27:11 by nrouzeva          #+#    #+#             */
/*   Updated: 2017/02/03 06:01:02 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_s_wc(char **final_str, t_info *info, void *ap)
{
	char	*res;

	res = ft_strdup("");
	if (!(ft_unini(&res, ((int*)ap))))
		ft_strdel(&res);
	ft_option_apply_string(final_str, res, info);
	return (1);
}

int		ft_s_c(char **final_str, t_info *info, void *ap)
{
	char *res;

	res = ft_strdup("");
	if (info->length & L_L)
	{
		if (!(ft_unini(&res, ((int*)ap))))
			ft_strdel(&res);
	}
	else
	{
		free(res);
		res = ft_strjfri(res, (char*)ap, 0);
	}
	ft_option_apply_string(final_str, res, info);
	return (0);
}
