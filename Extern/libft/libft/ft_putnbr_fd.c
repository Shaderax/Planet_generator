/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouzeva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:01:57 by nrouzeva          #+#    #+#             */
/*   Updated: 2016/11/07 16:20:56 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "unistd.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int long_n;

	long_n = n;
	if (long_n < 0)
	{
		write(fd, "-", 1);
		long_n = -long_n;
	}
	if (long_n > 9)
		ft_putnbr_fd(long_n / 10, fd);
	ft_putchar_fd(long_n % 10 + '0', fd);
}
