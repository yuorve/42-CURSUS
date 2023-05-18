# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/17 12:20:01 by yoropeza          #+#    #+#              #
#    Updated: 2023/05/18 12:55:10 by yoropeza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
LIBFT	= libft

INC		= -I ./ -I $(LIBFT)/inc
LFLAGS	= -L$(LIBFT) -lft
SRC		= push_swap.c radix.c sort.c utils.c moves.c
OBJS	= $(SRC:.c=.o)

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
RM		= rm -rf

BOLD	= \033[1m
RED		= \033[31;1m
GREEN	= \033[32;1m
YELLOW	= \033[33;1m
CYAN	= \033[36;1m
WHITE	= \033[37;1m
RESET	= \033[0m

all: lib $(NAME)

lib:
	@$(MAKE) -C $(LIBFT)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) $(INC) -o $(NAME) &&\
	printf "$(GREEN)$(BOLD)Push_Swap Ready!\n$(RESET)"

%.o : %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(INC) && printf "$(WHITE)$(BOLD)\rCompiling: \
	$(CYAN)$(notdir $@)$(GREEN)\r\e[35C[OK]\n$(RESET)"

clean:
	@$(RM) $(OBJS) && printf "$(GREEN)$(BOLD)Push_swap objects cleaned! :)\n$(RESET)"
	@$(MAKE) -C $(LIBFT) clean

fclean: clean
	@$(RM) $(NAME) && printf "$(YELLOW)$(BOLD)$(NAME) $(GREEN)file cleaned! :)\
	\n$(RESET)"
	@$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY: all bonus clean fclean re
