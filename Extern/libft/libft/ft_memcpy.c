/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouzeva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:43:06 by nrouzeva          #+#    #+#             */
/*   Updated: 2016/11/05 16:13:12 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	char			*dest;
	const char		*source;

	dest = dst;
	source = src;
	i = 0;
	while (i < n)
	{
		*dest++ = *source++;
		i++;
	}
	return (dst);
}
