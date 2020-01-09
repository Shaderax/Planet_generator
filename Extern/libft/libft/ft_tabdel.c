/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouzeva <nrouzeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 15:19:22 by nrouzeva          #+#    #+#             */
/*   Updated: 2017/03/10 15:24:26 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabdel(void **tab, int height)
{
	int super_count;

	super_count = -1;
	while (++super_count < height)
		free(tab[super_count]);
	free(tab);
}
