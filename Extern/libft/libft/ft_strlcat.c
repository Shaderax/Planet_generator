/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouzeva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:39:13 by nrouzeva          #+#    #+#             */
/*   Updated: 2016/11/26 11:59:18 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned	int i;
	unsigned	int len;

	i = 0;
	len = ft_strlen(dst);
	if (size <= len)
		return (size + ft_strlen(src));
	while (src[i] != '\0' && i < (size - len - 1))
	{
		dst[len + i] = src[i];
		i++;
	}
	dst[len + i] = '\0';
	return (ft_strlen(src) + len);
}
