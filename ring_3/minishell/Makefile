NAME = minishell
SRCDIR	= src
OBJDIR	= obj
LIBFT	= lib/libft

HEADER	= -I ./inc -I $(LIBFT)/inc -I/Users/$(USER)/.brew/opt/readline/include
LFLAGS	= -L$(LIBFT) -lft -L/Users/$(USER)/.brew/opt/readline/lib -lreadline
SRC		:= $(wildcard $(SRCDIR)/*.c)
OBJS	:= $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

CC 		= gcc
CFLAGS	= -Wall -Werror -Wextra -g
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

all: libft $(NAME)

libft:
	@$(MAKE) -C $(LIBFT)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) $(HEADER) -o $(NAME) &&\
	printf "$(GREEN)$(BOLD)Minishell ready!\n$(RESET)"

obj/%.o : src/%.c
	@mkdir -p $(OBJDIR)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADER) && printf "$(WHITE)$(BOLD)\rCompiling: \
	$(CYAN)$(notdir $@)$(GREEN)\r\e[35C[OK]\n$(RESET)"

clean:
	@$(RM) $(OBJDIR) && printf "$(GREEN)$(BOLD)All objects cleaned! :)\n$(RESET)"
	@make -C $(LIBFT) clean

fclean: clean
	@$(RM) $(NAME) && printf "$(YELLOW)$(BOLD)$(NAME) $(GREEN)file cleaned! :)\n$(RESET)"
	@make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
