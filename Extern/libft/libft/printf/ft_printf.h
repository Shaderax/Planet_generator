/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrouzeva <nrouzeva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 03:22:51 by nrouzeva          #+#    #+#             */
/*   Updated: 2017/03/09 14:27:14 by nrouzeva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"
# include <wchar.h>
# include "struct.h"
# include <stddef.h>
# include <stdint.h>

# define FL_MN		1 << 0
# define FL_PLS		1 << 1
# define FL_DS		1 << 2
# define FL_O		1 << 3
# define FL_SPACE	1 << 4

# define L_HH		1 << 0
# define L_H		1 << 1
# define L_L		1 << 2
# define L_LL		1 << 3
# define L_J		1 << 4
# define L_Z		1 << 5
# define L_T		1 << 6

# define UU unsigned long long

int			ft_get_flags(char *format, t_info *info);
int			ft_get_aff_min(char *format, t_info *info);
int			ft_get_pre(char *format, t_info *info);
int			ft_get_length(char *format, t_info *info);
int			ft_get_convert(char *format, t_info *info);

int			ft_di_sd(char **final_str, t_info *info, void *ap);
int			ft_o_uo(char **final_str, t_info *info, void *ap);
int			ft_u_ud(char **final_str, t_info *info, void *ap);
int			ft_x_uh(char **final_str, t_info *info, void *ap);
int			ft_xx_uh(char **final_str, t_info *info, void *ap);
int			ft_d_lsd(char **final_str, t_info *info, void *ap);
int			ft_o_luo(char **final_str, t_info *info, void *ap);
int			ft_u_lud(char **final_str, t_info *info, void *ap);
int			ft_c_wn(char **final_str, t_info *info, void *ap);
int			ft_c_uc(char **final_str, t_info *info, void *ap);
int			ft_s_wc(char **final_str, t_info *info, void *ap);
int			ft_s_c(char **final_str, t_info *info, void *ap);
int			ft_p_v(char **final_str, t_info *info, void *ap);
int			ft_pourcentage_c(char **final_str, t_info *info, void *ap);

int			ft_option_apply_string(char **final_str, char *res, t_info *info);
int			ft_option_apply_number(char **final_str, char **res, t_info *info);
int			ft_option_apply_caractere(char **str, char *res, t_info *info);
int			ft_option_apply_octal(char **str, char *res, t_info *info);
int			ft_option_apply_hexa(char **str, char *res, t_info *info);

void		buffcpy(char **buf, t_info *info, char *str);
UU			ft_length_converter(t_info *info, void *ap);

int			ft_printf(const char *restrict format, ...);
int			ft_putstr2(char *str, int i);

int			ft_unini(char **final_str, int *ap);

#endif
