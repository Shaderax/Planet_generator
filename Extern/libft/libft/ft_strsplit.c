/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouzeva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:06:31 by nrouzeva          #+#    #+#             */
/*   Updated: 2016/11/25 19:54:09 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_word(char const *s, char c)
{
	char	*str;
	int		i;
	int		j;

	str = NULL;
	if (!(str = malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (str);
	i = 0;
	j = 0;
	while (s[i] != c && s[i] != '\0')
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		wrd;

	i = 0;
	j = 0;
	if (!(s && c))
		return (NULL);
	wrd = ft_wd_count(s, c);
	if (!(tab = malloc(sizeof(char*) * (wrd + 1))))
		return (tab);
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			tab[j++] = ft_word(s + i, c);
			while (s[i] != c && s[i])
				i++;
		}
	}
	tab[j] = NULL;
	return (tab);
}
