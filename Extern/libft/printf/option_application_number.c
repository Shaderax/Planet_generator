/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_application_number.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouzeva <nrouzeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 12:55:32 by nrouzeva          #+#    #+#             */
/*   Updated: 2017/02/03 06:40:01 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fonction_en_trop(t_info *info, char **res)
{
	if (ft_strchr("idDup", info->specifier) &&
			info->precision == 0 && *res[0] == '0' && !(FL_DS & info->flags))
	{
		ft_strdel(res);
		*res = ft_strdup("");
	}
	if (info->precision >= 0 && info->flags & FL_O)
		info->flags ^= FL_O;
	if (FL_O & info->flags && info->width > info->precision)
		info->precision = info->width - !(!(FL_SPACE & info->flags));
}

int		ft_flags_number(char **res, t_info *info, char **final_str)
{
	if ((FL_PLS & info->flags) && *res[0] != '-'
			&& ft_strchr("idD", info->specifier))
	{
		if (!(FL_O & info->flags))
			info->width++;
		if (!(FL_O & info->flags))
			info->precision++;
		*res = ft_strjfri("+", *res, 2);
	}
	else if ((FL_SPACE & info->flags) && *res[0] != '+' && *res[0] != '-'
				&& ft_strchr("idD", info->specifier))
		buffcpy(final_str, info, " ");
	return (0);
}

int		ft_width_number(char **res, char **final_str, t_info *info)
{
	int truc;
	int i;

	truc = 0;
	if ((FL_PLS & info->flags) || (FL_SPACE & info->flags))
		truc = 1;
	if ((FL_O & info->flags) && *res[0] == '-' && (truc = 1))
	{
		*res = ft_strjfri("", *res + 1, 0);
		buffcpy(final_str, info, "-");
	}
	i = info->width - (int)ft_strlen(*res) - truc;
	if ((FL_MN & info->flags))
		buffcpy(final_str, info, *res);
	while (i > 0 && i != 0)
	{
		if (FL_O & info->flags)
			buffcpy(final_str, info, "0");
		else
			buffcpy(final_str, info, " ");
		i--;
	}
	return (0);
}

int		ft_precision_number(char **res, t_info *info, char **final_str)
{
	int i;

	i = info->precision - ((int)ft_strlen(*res));
	if (info->precision > (int)ft_strlen(*res))
		while (i > 0 && i-- != 0)
			*res = ft_strjfri("0", *res, 2);
	if (FL_MN & info->flags && info->precision > info->width)
		buffcpy(final_str, info, *res);
	i = 0;
	while ((*res)[++i] != '\0')
	{
		if ((*res)[i] == '-')
		{
			(*res)[i] = (*res)[0];
			(*res)[0] = '-';
			break ;
		}
		if ((*res)[i] == '+')
		{
			(*res)[i] = (*res)[0];
			(*res)[0] = '+';
			break ;
		}
	}
	return (0);
}

int		ft_option_apply_number(char **final_str, char **res, t_info *info)
{
	if (*res[0] == '-' && info->precision > (int)ft_strlen(*res) - 1 &&
			info->precision > 0)
		info->precision++;
	if (FL_MN & info->flags && FL_O & info->flags)
		info->flags ^= FL_O;
	ft_fonction_en_trop(info, res);
	if (!res)
		*res = ft_strdup("(null)");
	if (info->flags != 0)
		ft_flags_number(res, info, final_str);
	if (info->precision >= 0)
		ft_precision_number(res, info, final_str);
	if (info->width != 0 && info->width >= 0)
		ft_width_number(res, final_str, info);
	if (!(FL_MN & info->flags))
		buffcpy(final_str, info, *res);
	ft_strdel(res);
	return (0);
}
