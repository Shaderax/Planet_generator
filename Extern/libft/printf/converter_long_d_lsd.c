/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_long_d_lsd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouzeva <nrouzeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 03:35:29 by nrouzeva          #+#    #+#             */
/*   Updated: 2017/02/03 06:19:43 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_d_lsd(char **final_str, t_info *info, void *ap)
{
	info->length = 0;
	info->length |= L_L;
	ft_di_sd(final_str, info, ap);
	return (1);
}
