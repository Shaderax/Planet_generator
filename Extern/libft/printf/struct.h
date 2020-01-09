/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouzeva <nrouzeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 03:29:05 by nrouzeva          #+#    #+#             */
/*   Updated: 2017/02/03 03:30:20 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef	struct	s_info
{
	int			i;
	int			c;
	int			flags;
	int			width;
	int			precision;
	int			length;
	char		specifier;
}				t_info;

#endif
