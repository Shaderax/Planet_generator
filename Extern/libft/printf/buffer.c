/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouzeva <nrouzeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 03:34:59 by nrouzeva          #+#    #+#             */
/*   Updated: 2017/02/03 03:45:42 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	buff_max(char **buf, t_info *info)
{
	char *str;

	if (info->c == 2048)
	{
		str = ft_strdup(*buf);
		free(*buf);
		*buf = NULL;
		*buf = ft_strnew(sizeof(str) + sizeof(char) * 2048);
		ft_strcpy(*buf, str);
		ft_strdel(&str);
	}
}

void	buffcpy(char **buf, t_info *info, char *str)
{
	while (*str)
	{
		buff_max(buf, info);
		buf[0][info->c] = *str;
		info->c++;
		str++;
	}
}
