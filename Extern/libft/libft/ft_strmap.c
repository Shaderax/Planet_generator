/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouzeva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:44:01 by nrouzeva          #+#    #+#             */
/*   Updated: 2016/11/07 17:22:40 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = NULL;
	if (s)
		str = (char *)malloc(sizeof(*str) * (ft_strlen(s) + 1));
	if (str && s && f)
	{
		while (s[i])
		{
			str[i] = (*f)((char)(s[i]));
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
