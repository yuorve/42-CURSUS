# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 08:02:41 by yoropeza          #+#    #+#              #
#    Updated: 2023/05/11 08:13:58 by yoropeza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minitalk
LIBFT	= libft

INC		= -I ./ -I $(LIBFT)/inc
LFLAGS	= -L$(LIBFT) -lft
SRC		= client.c
SRCSV	= server.c
OBJS	= $(SRC:.c=.o)
OBJSSV	= $(SRCSV:.c=.o)

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

all: lib $(NAME) $(NAMESV)

lib:
	@$(MAKE) -C $(LIBFT)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) $(INC) -o $(NAME) &&\
	printf "$(GREEN)$(BOLD)Client\n$(RESET)"

$(NAMESV) : $(OBJSSV)
	@$(CC) $(CFLAGS) $(OBJSSV) $(LFLAGS) $(INC) -o $(NAMESV) &&\
	printf "$(GREEN)$(BOLD)Server\n$(RESET)"
	
%.o : %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(INC) && printf "$(WHITE)$(BOLD)\rCompiling: \
	$(CYAN)$(notdir $@)$(GREEN)\r\e[35C[OK]\n$(RESET)"

clean:
	@$(RM) $(OBJS) && printf "$(GREEN)$(BOLD)Minitalk objects cleaned! :)\n$(RESET)"
	@$(MAKE) -C $(LIBFT) clean

fclean: clean
	@$(RM) $(NAME) && printf "$(YELLOW)$(BOLD)$(NAME) $(GREEN)file cleaned! :)\
	\n$(RESET)"
	@$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY: all bonus clean fclean re