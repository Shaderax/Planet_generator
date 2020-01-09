/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_long_o_luo.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouzeva <nrouzeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 03:36:04 by nrouzeva          #+#    #+#             */
/*   Updated: 2017/02/03 06:19:54 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_o_luo(char **final_str, t_info *info, void *ap)
{
	info->length = 0;
	info->length |= L_L;
	ft_o_uo(final_str, info, ap);
	return (1);
}
