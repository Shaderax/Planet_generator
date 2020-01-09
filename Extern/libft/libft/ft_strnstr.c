/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouzeva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:58:24 by nrouzeva          #+#    #+#             */
/*   Updated: 2016/11/06 18:34:46 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*s1 && s2[i] == '\0')
		return ((char *)(s1));
	if (n < ft_strlen(s2))
		return (NULL);
	while (s1[i])
	{
		j = 0;
		while ((i + j) < n && s1[i + j] && s2[j] && s1[i + j] == s2[j])
			j++;
		if (s2[j] == '\0' || j == n)
			return ((char *)(s1 + i));
		i++;
	}
	return (NULL);
}
