/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouzeva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:46:29 by nrouzeva          #+#    #+#             */
/*   Updated: 2016/11/07 17:23:23 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	i = 0;
	str = NULL;
	if (s)
		str = (char *)malloc(sizeof(*str) * (ft_strlen(s) + 1));
	if (str && s && f)
	{
		while (s[i])
		{
			str[i] = (*f)((unsigned int)i, (char)(s[i]));
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
