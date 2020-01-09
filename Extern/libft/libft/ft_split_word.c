/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouzeva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:58:52 by nrouzeva          #+#    #+#             */
/*   Updated: 2016/11/10 12:03:52 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_split_word(char const *s, char c)
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
