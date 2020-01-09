/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouzeva <nrouzeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 12:54:42 by nrouzeva          #+#    #+#             */
/*   Updated: 2017/02/03 05:02:38 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	launch_function_1(int i, char **final_str, t_info *info, void *ap)
{
	int		(*tab_ptr[15])(char**, t_info*, void*);

	tab_ptr[0] = &ft_di_sd;
	tab_ptr[1] = &ft_di_sd;
	tab_ptr[2] = &ft_o_uo;
	tab_ptr[3] = &ft_u_ud;
	tab_ptr[4] = &ft_x_uh;
	tab_ptr[5] = &ft_xx_uh;
	tab_ptr[6] = &ft_d_lsd;
	tab_ptr[7] = &ft_o_luo;
	tab_ptr[8] = &ft_u_lud;
	tab_ptr[9] = &ft_c_wn;
	tab_ptr[10] = &ft_c_uc;
	tab_ptr[11] = &ft_s_wc;
	tab_ptr[12] = &ft_s_c;
	tab_ptr[13] = &ft_p_v;
	tab_ptr[14] = &ft_pourcentage_c;
	if ((tab_ptr[i])(final_str, info, ap))
		return (1);
	return (0);
}

int	ft_generical_point(char **final_str, t_info *info, void *ap)
{
	int		i;
	char	str[16];

	i = 0;
	ft_strcpy(str, "diouxXDOUCcSsp%");
	while (str[i] && str[i] != info->specifier)
		i++;
	if (ft_strchr(str, info->specifier) &&
			launch_function_1(i, final_str, info, ap))
		return (1);
	return (0);
}

int	ft_stock_things(char *format, char **final_str, t_info *info, va_list ap)
{
	void	*rien;

	if (!(format[info->i]))
		return (0);
	rien = NULL;
	info->flags = 0;
	info->width = 0;
	info->length = 0;
	info->precision = -1;
	info->specifier = 0;
	ft_get_flags(format, info);
	ft_get_aff_min(format, info);
	ft_get_pre(format, info);
	ft_get_length(format, info);
	ft_get_convert(format, info);
	if (ft_strchr("diouxXDOUCcSsp", info->specifier))
		rien = va_arg(ap, void *);
	else if (info->specifier != '%')
		ft_option_apply_caractere(final_str, ft_strdup(&info->specifier), info);
	ft_generical_point(final_str, info, rien);
	return (1);
}

int	ft_printf(const char *restrict format, ...)
{
	t_info	*info;
	va_list ap;
	char	*buf;
	int		i;

	buf = (char *)malloc(sizeof(char) * 5048);
	info = (t_info *)malloc(sizeof(t_info));
	info->c = 0;
	info->i = 0;
	va_start(ap, format);
	while (format[info->i])
		if (format[info->i] == '%')
		{
			info->i++;
			if (ft_stock_things((char *)format, &buf, info, ap))
				info->i++;
		}
		else
			buf[info->c++] = format[info->i++];
	va_end(ap);
	i = info->c;
	ft_putstr2(buf, i);
	ft_strdel(&buf);
	ft_memdel((void**)&info);
	return (i);
}
