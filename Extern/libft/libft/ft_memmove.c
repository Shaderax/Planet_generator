/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouzeva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:04:08 by nrouzeva          #+#    #+#             */
/*   Updated: 2016/11/06 17:31:19 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (n == 0)
		return (dest);
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	while (n-- > 0)
		((char *)dest)[n] = ((char *)src)[n];
	return (dest);
}
