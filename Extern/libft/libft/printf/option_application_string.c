/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_application_string.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouzeva <nrouzeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 12:56:27 by nrouzeva          #+#    #+#             */
/*   Updated: 2017/02/03 06:37:57 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_width_3(char **res, char **final_str, t_info *info)
{
	int i;

	i = info->width - (int)ft_strlen(*res);
	if ((FL_MN & info->flags) && info->precision < 0)
		buffcpy(final_str, info, *res);
	while (i > 0 && i != 0)
	{
		buffcpy(final_str, info, " ");
		i--;
	}
	return (0);
}

int		ft_precision_3(char **res, t_info *info, char **final_str)
{
	char *ptr;

	ptr = NULL;
	if (info->precision <= (int)ft_strlen(*res))
	{
		ptr = ft_strsub(*res, 0, info->precision);
		ft_strdel(res);
		*res = ft_strjfri(ptr, "", 1);
	}
	if (FL_MN & info->flags)
		buffcpy(final_str, info, *res);
	return (0);
}

int		ft_option_apply_string(char **final_str, char *res, t_info *info)
{
	if (!res)
		res = ft_strdup("(null)");
	if (info->precision >= 0)
		ft_precision_3(&res, info, final_str);
	if (info->width != 0 && info->precision < info->width)
		ft_width_3(&res, final_str, info);
	if (!(FL_MN & info->flags))
		buffcpy(final_str, info, res);
	ft_strdel(&res);
	return (0);
}
