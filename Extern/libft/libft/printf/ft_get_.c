/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouzeva <nrouzeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 12:57:07 by nrouzeva          #+#    #+#             */
/*   Updated: 2017/01/28 00:41:06 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_flags(char *format, t_info *info)
{
	while (format[info->i] && (format[info->i] == '-' || format[info->i] == '+'
			|| format[info->i] == '#' || format[info->i] == '0'
			|| format[info->i] == ' '))
	{
		if (format[info->i] == '-')
			info->flags |= FL_MN;
		else if (format[info->i] == '+')
			info->flags |= FL_PLS;
		else if (format[info->i] == '#')
			info->flags |= FL_DS;
		else if (format[info->i] == '0')
			info->flags |= FL_O;
		else if (format[info->i] == ' ')
			info->flags |= FL_SPACE;
		info->i++;
	}
	return (1);
}

int		ft_get_aff_min(char *format, t_info *info)
{
	if (format[info->i] != '.' && format[info->i] >= '0'
			&& format[info->i] <= '9')
	{
		info->width = ft_atoi(format + info->i);
		while (format[info->i] != '.' && format[info->i] >= '0'
				&& format[info->i] <= '9')
			info->i++;
	}
	return (1);
}

int		ft_get_pre(char *format, t_info *info)
{
	if (format[info->i] != '.')
		return (0);
	if (format[info->i] == '.')
		info->i++;
	if (format[info->i] >= '0' && format[info->i] <= '9')
		info->precision = ft_atoi(format + info->i);
	while (format[info->i] >= '0' && format[info->i] <= '9')
		info->i++;
	if (info->precision == -1)
		info->precision = 0;
	return (1);
}

int		ft_get_length(char *format, t_info *info)
{
	if (format[info->i] && (format[info->i] == 'h' || format[info->i] == 'l'
				|| format[info->i] == 'j' || format[info->i] == 'z' ||
				format[info->i] == 't'))
	{
		if (format[info->i] == 'h' && format[info->i + 1] == 'h')
			info->length |= L_HH;
		else if (format[info->i] == 'h')
			info->length |= L_H;
		else if (format[info->i] == 'l' && format[info->i + 1] == 'l')
			info->length |= L_LL;
		else if (format[info->i] == 'l')
			info->length |= L_L;
		else if (format[info->i] == 'j')
			info->length |= L_J;
		else if (format[info->i] == 'z')
			info->length |= L_Z;
		else if (format[info->i] == 't')
			info->length |= L_T;
		if (info->length & L_HH || info->length & L_LL)
			info->i = info->i + 2;
		else
			info->i++;
	}
	return (1);
}

int		ft_get_convert(char *format, t_info *info)
{
	char strwsp[16];

	ft_strcpy(strwsp, "diouxXDOUCcSsp%\0");
	if (ft_strchr(strwsp, format[info->i]))
	{
		info->specifier = format[info->i];
		return (1);
	}
	else if (format[info->i] >= 0 && format[info->i] <= 127)
		info->specifier = format[info->i];
	return (0);
}
