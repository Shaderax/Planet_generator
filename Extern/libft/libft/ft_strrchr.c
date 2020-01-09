/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouzeva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:02:46 by nrouzeva          #+#    #+#             */
/*   Updated: 2016/11/06 15:25:50 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strrchr(const char *str, int c)
{
	char *last;

	last = NULL;
	while (*str)
	{
		if (*str == (char)c)
			last = ((char *)str);
		str++;
	}
	if (*str == (char)c)
		last = ((char *)str);
	return (last);
}
