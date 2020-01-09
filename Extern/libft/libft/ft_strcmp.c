/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouzeva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:57:31 by nrouzeva          #+#    #+#             */
/*   Updated: 2016/11/06 18:39:13 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *str, const char *str2)
{
	int i;

	i = 0;
	while (str[i] && str2[i] && str[i] == str2[i])
		i++;
	return ((unsigned char)str[i] - (unsigned char)str2[i]);
}
