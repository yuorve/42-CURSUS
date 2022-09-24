NAME	= libft.a

SRCS	= $(shell find . -type f -name "*.c" -exec basename {} \;)

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -Werror -Wall -Wextra

CC	= gcc

all:	$(NAME)

$(NAME):	$(OBJS)
	@$(CC) -c $(CFLAGS) $(SRCS)
	@ar crs $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)

fclean:	clean
		@rm -f $(NAME)

re:	fclean all

.PHONY:	all, clean, fclean, re