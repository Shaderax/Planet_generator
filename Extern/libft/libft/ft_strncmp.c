/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouzeva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:48:36 by nrouzeva          #+#    #+#             */
/*   Updated: 2016/11/07 10:23:57 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	unsigned int i;

	i = 0;
	while (i < len && (s1[i] && s2[i]) && s1[i] == s2[i])
		i++;
	if (i == len)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
