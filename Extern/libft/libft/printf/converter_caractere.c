/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_caractere.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouzeva <nrouzeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 03:36:15 by nrouzeva          #+#    #+#             */
/*   Updated: 2017/02/03 05:02:16 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_c_wn(char **final_str, t_info *info, void *ap)
{
	char	*res;
	int		*nb_str;

	nb_str = (int *)ft_memalloc(sizeof(int) * 2);
	nb_str[0] = (int)ap;
	nb_str[1] = '\0';
	res = ft_strdup("");
	if (*(int*)&ap == 0)
	{
		res[0] = (char)-1;
		res[1] = '\0';
	}
	else
		ft_unini(&res, nb_str);
	free(nb_str);
	ft_option_apply_caractere(final_str, res, info);
	ft_strdel(&res);
	return (1);
}

int		ft_c_uc(char **final_str, t_info *info, void *ap)
{
	char *res;

	res = ft_strdup("");
	if (info->length & L_L)
		ft_unini(&res, (int*)&ap);
	else
	{
		if (*(unsigned char*)&ap == 0)
			res[0] = -1;
		else
			res[0] = *(unsigned char*)&ap;
		res[1] = '\0';
	}
	ft_option_apply_caractere(final_str, res, info);
	ft_strdel(&res);
	return (1);
}
