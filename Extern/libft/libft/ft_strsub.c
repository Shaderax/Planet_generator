/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouzeva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:45:16 by nrouzeva          #+#    #+#             */
/*   Updated: 2016/11/08 17:36:38 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *str;

	if (!s)
		return (NULL);
	s = s + start;
	str = NULL;
	str = ft_strnew(len);
	if (str == NULL)
		return (str);
	if (str)
		ft_strncpy(str, s, len);
	return (str);
}
