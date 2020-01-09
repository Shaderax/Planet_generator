# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nrouzeva <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/05 14:25:16 by nrouzeva          #+#    #+#              #
#    Updated: 2017/04/12 00:29:15 by nrouzeva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = #-Wall -Wextra #-Werror

OBJ_PATH = ./obj
SRC_LIB_PATH = ./libft
SRC_PRINTF_PATH = ./printf

SRC_LIB_NAME =	ft_atoi.c \
			ft_bzero.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_itoa_base.c \
			ft_itoa_hexa.c \
			ft_itoa_ull.c \
			ft_memalloc.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memdel.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar.c \
			ft_putchar_fd.c \
			ft_putendl.c \
			ft_putendl_fd.c \
			ft_putnbr.c \
			ft_putnbr_fd.c \
			ft_putstr.c \
			ft_putstr_fd.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strclr.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strdel.c \
			ft_strdup.c \
			ft_strequ.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlen.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strncat.c \
			ft_strncmp.c \
			ft_strncpy.c \
			ft_strnequ.c \
			ft_strnew.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strsplit.c \
			ft_strstr.c \
			ft_strsub.c \
			ft_strtrim.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_lstnew.c \
			ft_lstdelone.c \
			ft_lst_pushback.c \
			ft_lstdel.c \
			ft_lstadd.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_del.c \
			ft_len_number.c \
			ft_len_number_ull.c \
			ft_wd_count.c \
			ft_split_word.c \
			get_next_line.c \
			ft_strjfri.c \
			ft_sqrt.c \
			ft_tabdel.c \
			ft_atof.c

SRC_PRINTF_NAME = converter_address_p_v.c \
			converter_caractere.c \
			converter_di_sd.c \
			converter_long_d_lsd.c \
			converter_long_o_luo.c \
			converter_long_u_lud.c \
			converter_o_uo.c \
			converter_string.c \
			converter_tools_number.c \
			converter_u_ud.c \
			converter_x_uh.c \
			converter_unicode.c \
			converter_string.c \
			converter_unicode.c \
			option_application_caractere.c \
			option_application_number.c \
			option_application_string.c \
			ft_get_.c \
			ft_printf.c \
			buffer.c \
			ft_putstr2.c \
			option_application_hexa.c \
			option_application_octal.c

SRC_LIB = $(addprefix $(SRC_LIB_PATH)/,$(SRC_LIB_NAME))
SRC_PRINTF = $(addprefix $(SRC_PRINTF_PATH)/,$(SRC_PRINTF_NAME))

OBJ = $(SRC_LIB_NAME:.c=.o)
OBJ += $(SRC_PRINTF_NAME:.c=.o)
OBJS = $(addprefix $(OBJ_PATH)/,$(OBJ))

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(OBJ_PATH)/%.o: libft/%.c libft/includes/get_next_line.h libft/includes/libft.h printf/ft_printf.h printf/struct.h Makefile
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -o $@ -c $< -I ./libft/includes/ -I ./printf/

$(OBJ_PATH)/%.o: printf/%.c libft/includes/get_next_line.h libft/includes/libft.h printf/ft_printf.h printf/struct.h Makefile
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -o $@ -c $< -I ./libft/includes/ -I ./printf/

clean:
	@rm -rf $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@rm -rf $(NAME)

re: fclean all
