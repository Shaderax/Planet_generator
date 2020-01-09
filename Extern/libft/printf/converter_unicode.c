/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouzeva <nrouzeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/31 10:33:44 by nrouzeva          #+#    #+#             */
/*   Updated: 2017/02/02 18:58:18 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_unicode_2(unsigned int nbr, char *res)
{
	res = (char *)ft_memalloc(sizeof(char) * 3);
	res[0] = (nbr << 20) >> 26 | 0xc0;
	res[1] = (nbr << 26) >> 26 | 0x80;
	res[2] = '\0';
	return (res);
}

char	*ft_unicode_3(unsigned int nbr, char *res)
{
	res = (char *)ft_memalloc(sizeof(char) * 4);
	res[0] = (nbr << 14) >> 26 | 0xe0;
	res[1] = (nbr << 20) >> 26 | 0x80;
	res[2] = (nbr << 26) >> 26 | 0x80;
	res[3] = '\0';
	return (res);
}

char	*ft_unicode_4(unsigned int nbr, char *res)
{
	res = (char *)ft_memalloc(sizeof(char) * 5);
	res[0] = (nbr << 8) >> 26 | 0xf0;
	res[1] = (nbr << 14) >> 26 | 0x80;
	res[2] = (nbr << 20) >> 26 | 0x80;
	res[3] = (nbr << 26) >> 26 | 0x80;
	res[4] = '\0';
	return (res);
}

char	*ft_unicode(int ap)
{
	int		i;
	char	*ret;

	i = 0;
	ret = NULL;
	if (ap < 128)
	{
		ret = (char *)ft_memalloc(sizeof(char) * 2);
		ret[0] = (char)ap;
		ret[1] = '\0';
		return (ret);
	}
	else if (ap >= 128 && ap <= 2047)
		ret = ft_unicode_2((ap), ret);
	else if ((ap >= 2048 && ap <= 55295) || (ap >= 57344 && ap <= 65535))
		ret = ft_unicode_3((ap), ret);
	else if ((ap >= 65536 && ap <= 196607) || (ap >= 917504 && ap <= 1114111))
		ret = ft_unicode_4((ap), ret);
	return (ret);
}

int		ft_unini(char **final_str, int *ap)
{
	int i;

	i = 0;
	if (!ap)
		return (0);
	while (*ap)
	{
		*final_str = ft_strjfri(*final_str, ft_unicode(*ap), 3);
		ap++;
	}
	return (1);
}
