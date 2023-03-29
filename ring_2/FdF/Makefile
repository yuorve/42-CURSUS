# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/28 19:29:04 by yoropeza          #+#    #+#              #
#    Updated: 2023/03/29 16:34:18 by yoropeza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = fdf.c \
	init_fdf.c \
	key_hooks.c \
	read_file.c \
	transformations.c \
	utils.c \
	fdf_utils.c

OBJ = $(SRC:.c=.o)

CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror
MLX_FLAGS 	= -lmlx -framework OpenGL -framework AppKit
RM 			= rm -rf

BOLD	= \033[1m
BLACK	= \033[30;1m
RED		= \033[31;1m
GREEN	= \033[32;1m
YELLOW	= \033[33;1m
BLUE	= \033[34;1m
MAGENTA	= \033[35;1m
CYAN	= \033[36;1m
WHITE	= \033[37;1m
RESET	= \033[0m

LIBFT_PATH = lib/libft
LIBFT = $(LIBFT_PATH)/libft.a
LIBFT_INC = $(LIBFT_PATH)/includes

MLX_PATH = lib/minilibx
MLX = $(MLX_PATH)/libmlx.a
MLX_INC = $(MLX_PATH)

all: mlx libft $(NAME)

libft:
	@$(MAKE) -C $(LIBFT)

mlx:
	@$(MAKE) -C $(MLX)

$(NAME): $(OBJ)
	@make -C $(LIBFT_PATH)
	@make -C $(MLX_PATH)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L $(LIBFT_PATH) -lft -L $(MLX_PATH) $(MLX_FLAGS) && printf "$(GREEN)$(BOLD)FdF ready to render!\n$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -I $(LIBFT_INC) -I $(MLX_INC) -c $< -o $@ && printf "$(WHITE)$(BOLD)\rCompiling: $(CYAN)$(notdir $@)$(GREEN)\r\e[35C[OK]\n$(RESET)"

clean:
	@$(RM) $(OBJ) && printf "$(GREEN)$(BOLD)All objects cleaned! :)\n$(RESET)"
	@make -C $(LIBFT_PATH) clean
	@make -C $(MLX_PATH) clean

fclean: clean
	@$(RM) $(NAME) && printf "$(YELLOW)$(BOLD)$(NAME) $(GREEN)file cleaned! :)\n$(RESET)"
	@make -C $(LIBFT_PATH) fclean
	@make -C $(MLX_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
