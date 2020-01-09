/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouzeva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:18:29 by nrouzeva          #+#    #+#             */
/*   Updated: 2017/01/17 14:47:39 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(char *str)
{
	char *dest;

	if (!str)
		return (NULL);
	dest = (char *)malloc((sizeof(*dest) * ft_strlen(str)) + 1);
	if (dest)
		dest = ft_strcpy(dest, str);
	return (dest);
}
