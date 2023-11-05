# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/25 11:16:03 by yoropeza          #+#    #+#              #
#    Updated: 2023/11/05 20:52:04 by yoropeza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRCDIR	= src
OBJDIR	= obj
LIBFT	= lib/libft
LIBMLX	= lib/MLX42

HEADER	= -I ./inc -I $(LIBMLX)/include -I $(LIBFT)/inc
LFLAGS	= -L$(LIBFT) -lft -L$(LIBMLX) -lmlx42 
LIBS	= -lglfw -L /Users/$(USER)/.brew/opt/glfw/lib/ -lm
SRC		:= $(wildcard $(SRCDIR)/mandatory/*.c)
SRC_B	:= $(wildcard $(SRCDIR)/bonus/*.c)
OBJS	:= $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))
OBJS_B	:= $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC_B))

CC 		= gcc
CFLAGS	= -Wall -Werror -Wextra
RM 		= rm -rf

UNAME	= $(shell uname -s)

ifeq ($(UNAME), Linux)
LIBS	= -ldl -lglfw -lm
$(warning Linux detected! Changing libs flags...)
endif

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

all: libmlx libft $(NAME)

libft:
	@$(MAKE) -C $(LIBFT)

libmlx:
	@$(MAKE) -C $(LIBMLX)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) $(LIBS) $(HEADER) -o $(NAME) &&\
	printf "$(GREEN)$(BOLD)So_long ready to play!\n$(RESET)"

bonus : libmlx libft $(OBJS_B)
	@$(CC) $(CFLAGS) $(OBJS_B) $(LFLAGS) $(LIBS) $(HEADER) -o $(NAME) &&\
	printf "$(GREEN)$(BOLD)So_long ready to play!\n$(RESET)"

obj/%.o : src/%.c
	@mkdir -p $(OBJDIR)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADER) && printf "$(WHITE)$(BOLD)\rCompiling: \
	$(CYAN)$(notdir $@)$(GREEN)\r\e[35C[OK]\n$(RESET)"

clean:
	@$(RM) $(OBJDIR) && printf "$(GREEN)$(BOLD)All objects cleaned! :)\n$(RESET)"
	@make -C $(LIBFT) clean
	@make -C $(LIBMLX) clean

fclean: clean
	@$(RM) $(NAME) && printf "$(YELLOW)$(BOLD)$(NAME) $(GREEN)file cleaned! :)\n$(RESET)"
	@make -C $(LIBFT) fclean
	@make -C $(LIBMLX) fclean

re: fclean all

.PHONY: all clean fclean re
