/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouzeva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:09:59 by nrouzeva          #+#    #+#             */
/*   Updated: 2016/11/06 11:44:12 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *str1, const char *str2)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(str1);
	while (str2[i] != '\0')
	{
		str1[len + i] = str2[i];
		i++;
	}
	str1[len + i] = str2[i];
	return (str1);
}
