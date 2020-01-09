# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nrouzeva <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/05 14:25:16 by nrouzeva          #+#    #+#              #
#    Updated: 2017/02/03 06:41:32 by nrouzeva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: $(NAME) all clean fclean re

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = ./libft/ft_atoi.c \
		./libft/ft_bzero.c \
		./libft/ft_isalnum.c \
		./libft/ft_isalpha.c \
		./libft/ft_isascii.c \
		./libft/ft_isdigit.c \
		./libft/ft_isprint.c \
		./libft/ft_itoa.c \
		./libft/ft_itoa_ull.c \
		./libft/ft_itoa_base.c \
		./libft/ft_itoa_hexa.c \
		./libft/ft_memalloc.c \
		./libft/ft_memccpy.c \
		./libft/ft_memchr.c \
		./libft/ft_memcmp.c \
		./libft/ft_memcpy.c \
		./libft/ft_memdel.c \
		./libft/ft_memmove.c \
		./libft/ft_memset.c \
		./libft/ft_putchar.c \
		./libft/ft_putchar_fd.c \
		./libft/ft_putendl.c \
		./libft/ft_putendl_fd.c \
		./libft/ft_putnbr.c \
		./libft/ft_putnbr_fd.c \
		./libft/ft_putstr.c \
		./libft/ft_putstr_fd.c \
		./libft/ft_strcat.c \
		./libft/ft_strchr.c \
		./libft/ft_strclr.c \
		./libft/ft_strcmp.c \
		./libft/ft_strcpy.c \
		./libft/ft_strdel.c \
		./libft/ft_strdup.c \
		./libft/ft_strequ.c \
		./libft/ft_striter.c \
		./libft/ft_striteri.c \
		./libft/ft_strjoin.c \
		./libft/ft_strlcat.c \
		./libft/ft_strlen.c \
		./libft/ft_strmap.c \
		./libft/ft_strmapi.c \
		./libft/ft_strncat.c \
		./libft/ft_strncmp.c \
		./libft/ft_strncpy.c \
		./libft/ft_strnequ.c \
		./libft/ft_strnew.c \
		./libft/ft_strnstr.c \
		./libft/ft_strrchr.c \
		./libft/ft_strsplit.c \
		./libft/ft_strstr.c \
		./libft/ft_strsub.c \
		./libft/ft_strtrim.c \
		./libft/ft_tolower.c \
		./libft/ft_toupper.c \
		./libft/ft_lstnew.c \
		./libft/ft_lstdelone.c \
		./libft/ft_lstdel.c \
		./libft/ft_lstadd.c \
		./libft/ft_lstiter.c \
		./libft/ft_lstmap.c \
		./libft/ft_len_number.c \
		./libft/ft_len_number_ull.c \
		./libft/ft_wd_count.c \
		./libft/ft_split_word.c \
		./libft/ft_strjfri.c

SRC3 = ./converter_address_p_v.c \
		./converter_caractere.c \
		./converter_di_sd.c \
		./converter_long_d_lsd.c \
		./converter_long_o_luo.c \
		./converter_long_u_lud.c \
		./converter_o_uo.c \
		./converter_string.c \
		./converter_tools_number.c \
		./converter_u_ud.c \
		./converter_x_uh.c \
		./converter_unicode.c \
		./converter_string.c \
		./converter_unicode.c \
		./option_application_caractere.c \
		./option_application_number.c \
		./option_application_string.c \
		./ft_get_.c \
		./ft_printf.c \
		./buffer.c \
		./ft_putstr2.c \
		./option_application_hexa.c \
		./option_application_octal.c

OBJ = $(patsubst ./libft/%.c, %.o, $(SRC))

OBJ2 = $(SRC3:.c=.o)

$(NAME):
		@echo Compiling
		@$(CC) $(CFLAGS) -c $(SRC) $(SRC3)
		@ar rc $(NAME) $(OBJ) $(OBJ2)
		@ranlib $(NAME)

all: $(NAME)

clean:
		@rm -rf $(OBJ) $(OBJ2)

fclean: clean
		@rm -rf $(NAME)

re: fclean all
