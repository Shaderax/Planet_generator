/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouzeva <nrouzeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 13:40:42 by nrouzeva          #+#    #+#             */
/*   Updated: 2017/02/05 19:57:41 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"

# define BUFF_SIZE 8

typedef struct	s_fd
{
	int			fd;
	char		*res;
	struct s_fd	*next;
}				t_fd;

int				get_next_line(const int fd, char **line);
char			*ft_strjfri(const char *s1, const char *s2, int opt);
#endif
