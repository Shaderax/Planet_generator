/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_application_hexa.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouzeva <nrouzeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 20:05:54 by nrouzeva          #+#    #+#             */
/*   Updated: 2017/02/03 06:40:29 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_width_hexa(char **res, char **final_str, t_info *info)
{
	int i;

	i = info->width - (int)ft_strlen(*res);
	if ((FL_MN & info->flags))
		buffcpy(final_str, info, *res);
	while (i > 0 && i != 0)
	{
		if (!(FL_MN & info->flags) && FL_O & info->flags)
			buffcpy(final_str, info, "0");
		else
			buffcpy(final_str, info, " ");
		i--;
	}
	return (0);
}

int		ft_precision_hexa(char **res, t_info *info, char **final_str)
{
	int i;

	i = info->precision - (int)ft_strlen(*res);
	if (info->precision > (int)ft_strlen(*res))
		while (i > 0 && i-- != 0)
			*res = ft_strjfri("0", *res, 0);
	if (FL_MN & info->flags && info->precision > info->width)
		buffcpy(final_str, info, *res);
	return (0);
}

int		ft_option_apply_hexa(char **final_str, char *res, t_info *info)
{
	if (info->precision == 0 && res[0] == '0')
	{
		ft_strdel(&res);
		res = ft_strdup("");
	}
	if (info->precision >= 0 && info->flags & FL_O)
		info->flags ^= FL_O;
	if (!res)
		res = ft_strdup("(null)");
	if (info->precision >= 0)
		ft_precision_hexa(&res, info, final_str);
	if (info->width != 0 && info->width >= 0)
		ft_width_hexa(&res, final_str, info);
	if (!(FL_MN & info->flags))
		buffcpy(final_str, info, res);
	return (0);
}
