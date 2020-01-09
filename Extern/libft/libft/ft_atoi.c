/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouzeva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 10:47:39 by nrouzeva          #+#    #+#             */
/*   Updated: 2016/11/06 17:30:47 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	int i;
	int o;
	int resultat;

	i = 0;
	resultat = 0;
	o = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
			str[i] == '\f' || str[i] == '\r' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			o = 1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		resultat = resultat * 10 + str[i] - '0';
		i++;
	}
	if (o == 1)
		resultat = resultat * -1;
	return (resultat);
}
