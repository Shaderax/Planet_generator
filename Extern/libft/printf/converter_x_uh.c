/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_x_uh.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouzeva <nrouzeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 03:31:16 by nrouzeva          #+#    #+#             */
/*   Updated: 2017/02/03 03:31:17 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_x_uh(char **final_str, t_info *info, void *ap)
{
	char				*res;
	unsigned long long	n;

	n = ft_length_converter(info, ap);
	res = ft_strdup("");
	if (FL_O & info->flags && n != 0 && FL_DS & info->flags)
		buffcpy(final_str, info, "0x");
	else if (FL_DS & info->flags && n != 0)
		res = ft_strjfri(res, "0x", 1);
	res = ft_strjfri(res, ft_itoa_hexa(n, 16, "0123456789abcdef"), 3);
	if (info->width != 0 && FL_DS & info->flags && n != 0
			&& (info->flags & FL_O))
		info->width = info->width - 2;
	ft_option_apply_hexa(final_str, res, info);
	ft_strdel(&res);
	return (1);
}

int		ft_xx_uh(char **final_str, t_info *info, void *ap)
{
	char				*res;
	unsigned long long	n;

	n = ft_length_converter(info, ap);
	res = ft_strdup("");
	if (FL_O & info->flags && FL_DS & info->flags && n != 0)
		buffcpy(final_str, info, "0X");
	else if (FL_DS & info->flags && n != 0)
		res = ft_strjfri(res, "0X", 1);
	res = ft_strjfri(res, ft_itoa_hexa(n, 16, "0123456789ABCDEF"), 3);
	if (info->width != 0 && FL_DS & info->flags && n != 0
			&& (info->flags & FL_O))
		info->width = info->width - 2;
	ft_option_apply_hexa(final_str, res, info);
	ft_strdel(&res);
	return (1);
}
