/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_application_caractere.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouzeva <nrouzeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 14:13:34 by nrouzeva          #+#    #+#             */
/*   Updated: 2017/02/03 06:37:14 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_width_2(char **final_str, char **res, t_info *info)
{
	int i;

	i = info->width - ft_strlen(*res);
	if (FL_MN & info->flags)
		buffcpy(final_str, info, *res);
	while (i > 0 && i != 0)
	{
		buffcpy(final_str, info, " ");
		i--;
	}
	return (0);
}

int		ft_option_apply_caractere(char **str, char *res, t_info *info)
{
	if (!res)
		res = ft_strdup("(null)");
	if (info->width != 0 && info->precision < info->width)
		ft_width_2(str, &res, info);
	if (!(FL_MN & info->flags))
		buffcpy(str, info, res);
	if (info->specifier != 'c' && info->specifier != 'C' &&
			info->specifier != '%')
		free(res);
	return (0);
}
