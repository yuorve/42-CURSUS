NAME = philo

SRC		= philo.c utils.c validations.c actions.c
OBJS	= $(SRC:.c=.o)

CC 		= gcc
CFLAGS	= -Wall -Werror -Wextra -lpthread
RM 		= rm -rf

UNAME	= $(shell uname -s)

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

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) &&\
	printf "$(GREEN)$(BOLD)Philosophers ready!\n$(RESET)"

%.o : %.c
	@$(CC) $(CFLAGS) -o $@ -c $< && printf "$(WHITE)$(BOLD)\rCompiling: \
	$(CYAN)$(notdir $@)$(GREEN)\r\e[35C[OK]\n$(RESET)"	

clean:
	@$(RM) $(OBJS) && printf "$(GREEN)$(BOLD)All objects cleaned! :)\n$(RESET)"

fclean: clean
	@$(RM) $(NAME) && printf "$(YELLOW)$(BOLD)$(NAME) $(GREEN)file cleaned! :)\n$(RESET)"

re: fclean all

.PHONY: all clean fclean re
