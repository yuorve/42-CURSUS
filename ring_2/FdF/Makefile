# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/28 19:29:04 by yoropeza          #+#    #+#              #
#    Updated: 2023/03/29 10:01:56 by yoropeza         ###   ########.fr        #
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

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

LIBFT_PATH = libs/libft
LIBFT = $(LIBFT_PATH)/libft.a
LIBFT_INC = $(LIBFT_PATH)/includes

MLX_PATH = libs/minilibx
MLX = $(MLX_PATH)/libmlx.a
MLX_INC = $(MLX_PATH)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_PATH)
	@make -C $(MLX_PATH)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L $(LIBFT_PATH) -lft -L $(MLX_PATH) $(MLX_FLAGS)

%.o: %.c
	@$(CC) $(CFLAGS) -I $(LIBFT_INC) -I $(MLX_INC) -c $< -o $@

clean:
	@make -C $(LIBFT_PATH) clean
	@make -C $(MLX_PATH) clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
