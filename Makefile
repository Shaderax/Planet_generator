NAME = Scop

SRC_PATH = ./src
OBJ_PATH = ./obj
LIB_PATH = ./lib/
INC_PATH = ./inc $(LIB_PATH)/libft/libft/includes/ $(LIB_PATH)libft/printf/ $(LIB_PATH)glfw/include/ ./$(LIB_PATH)/libmatrix

SRC_NAME = scop.c \
		   init.c \
		   input.c \
		   shader_new.c \
		   shader_set_var.c \
		   window.c \
		   callback.c \
		   object.c \
		   projection.c \
		   view.c \
		   tools.c \
		   mouse.c \
		   light.c \
		   error.c \
		   buffer.c \
		   scene.c \
		   texture.c \
		   parser.c

OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_NAME = libft glfw/src libmatrix

CC = gcc
CFLAGS = -Wextra -Wall -g -Werror -g3 -O2 #-fsanitize=address -fsanitize=undefined
LIB_FLAGS = -lmatrix -lglfw3 -framework AppKit -framework OpenGL -framework IOKit -framework CoreVideo

RED=\033[1;31m
GREEN=\033[1;32m
NC=\033[0m

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH))
LIB = $(addprefix -L$(LIB_PATH),$(LIB_NAME))

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ)
	cmake $(LIB_PATH)glfw
	make -C $(LIB_PATH)glfw
	make -C $(LIB_PATH)libft
	make -C $(LIB_PATH)libmatrix
	@echo "$(GREEN)[✓]$(NC) Library built"
	$(CC) $(CFLAGS) $(LIB) -lft $(INC) $(OBJ) $(LIB_FLAGS) -o $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c Makefile inc/scop.h
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)
	@echo "$(GREEN)[✓]$(NC) Source compiled : $<"

clean:
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "$(RED)[-]$(NC) Objects cleaned"
	@make -C $(LIB_PATH)libft clean
	@make -C $(LIB_PATH)libmatrix clean
	@echo "$(RED)[-]$(NC) Library cleaned"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)[-]$(NC) Program clear"
	@make -C $(LIB_PATH)libft fclean
	@make -C $(LIB_PATH)libmatrix fclean
	@echo "$(RED)[-]$(NC) Libft clear"

re:fclean
	@make
