/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_long_u_lud.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouzeva <nrouzeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 03:35:55 by nrouzeva          #+#    #+#             */
/*   Updated: 2017/02/03 06:20:07 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_u_lud(char **final_str, t_info *info, void *ap)
{
	info->length = 0;
	info->length |= L_L;
	ft_u_ud(final_str, info, ap);
	return (1);
}
