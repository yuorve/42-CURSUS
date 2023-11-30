# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/09 11:50:56 by yoropeza          #+#    #+#              #
#    Updated: 2023/11/29 19:19:35 by angalsty         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
SRCDIR	= src
OBJDIR	= obj
HEADER	= *.h
INC		= $(addprefix -I, $(HEADER))
SRC		:= $(wildcard $(SRCDIR)/*/*.c)
OBJS	:= $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

CC		:= gcc
CFLAGS	+= -Wall -Werror -Wextra
RM		= rm -rf

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

all : $(NAME)

$(NAME): $(OBJS)
	@ar crs $(NAME) $(OBJS) && printf "$(GREEN)$(BOLD)Libft ready\n$(RESET)"

obj/%.o: src/%.c
	@mkdir -p $(OBJDIR)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@ && printf "$(WHITE)$(BOLD)\rCompiling: $(CYAN)$(notdir $@)$(GREEN)\r\e[35C[OK]\n$(RESET)"

clean :
	@$(RM) $(OBJDIR) && printf "$(GREEN)$(BOLD)Libft objects cleaned! :)\n$(RESET)"
fclean :
	@$(RM) $(NAME) && printf "$(YELLOW)$(BOLD)$(NAME) $(GREEN)file cleaned! :)\n$(RESET)"
re : fclean all

.PHONY: all clean fclean re
