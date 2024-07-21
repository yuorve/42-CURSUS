# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/21 12:38:14 by yoropeza          #+#    #+#              #
#    Updated: 2024/07/21 14:22:34 by yoropeza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= harlFilter
SRC		= main.cpp Harl.cpp
OBJS	= $(SRC:.cpp=.o)

CC 		= g++
CFLAGS	= -Wall -Werror -Wextra -std=c++98
RM 		= rm -rf

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

all: $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) $(LIBS) $(HEADER) -o $(NAME) &&\
	printf "$(GREEN)$(BOLD)\rCompilation completed!\n$(RESET)"

obj/%.o : src/%.cpp
	@$(CC) $(CFLAGS) -o $@ -c $< && printf "$(WHITE)$(BOLD)\rCompiling: \
	$(CYAN)$(notdir $@)$(GREEN)\r\e[35C[OK]\n$(RESET)"

clean:
	@$(RM) $(OBJS) && printf "$(YELLOW)$(BOLD)All objects cleaned! :)\n$(RESET)"

fclean: clean
	@$(RM) $(NAME) && printf "$(YELLOW)$(BOLD)$(NAME) $(GREEN)file cleaned! :)\n$(RESET)"

re: fclean all

.PHONY: all clean fclean re
