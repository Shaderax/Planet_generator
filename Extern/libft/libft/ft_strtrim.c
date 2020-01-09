/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouzeva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:17:18 by nrouzeva          #+#    #+#             */
/*   Updated: 2016/11/08 18:30:36 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s)
{
	int		i;
	int		len;

	i = 0;
	if (s)
	{
		len = ft_strlen(s) - 1;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		{
			i++;
			if (s[i] == '\0')
				return (ft_strdup(""));
		}
		while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
			len--;
		return (ft_strsub(s, i, (len - i + 1)));
	}
	return (NULL);
}
