NAME	= libft.a

SRCS	= $(shell find . -type f \( -name "*.c" ! -name "ft_lst*.c" \) -exec basename {} \;)

B_SRCS	= $(shell find . -type f -name "ft_lst*.c" -exec basename {} \;)

OBJS	= $(SRCS:.c=.o)

B_OBJS	= $(B_SRCS:.c=.o)

CFLAGS	= -Werror -Wall -Wextra

CC	= gcc

all:	$(NAME)

$(NAME):	$(OBJS)
	@$(CC) -c $(CFLAGS) $(SRCS)
	@ar crs $(NAME) $(OBJS)

bonus:		$(B_OBJS) $(OBJS)	
	ar cr $(NAME) $(B_OBJS) $(OBJS)

clean:
	@rm -f $(OBJS)

fclean:	clean
		@rm -f $(NAME)

re:	fclean all

.PHONY:	all, clean, fclean, re, bonus