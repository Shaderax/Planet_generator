/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouzeva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:43:18 by nrouzeva          #+#    #+#             */
/*   Updated: 2016/11/25 19:39:58 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *str2)
{
	if (ft_strncmp(str2, "", 1) == 0)
		return ((char*)str);
	while ((*str != '\0') && ft_strncmp(str, str2, ft_strlen(str2)) != 0)
		str++;
	if (*str == '\0')
		return (NULL);
	return ((char *)str);
}
