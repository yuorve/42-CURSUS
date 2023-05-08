NAME	= ft_printf.a

SRCS	= ft_printf.c ft_printf_utils.c

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -Werror -Wall -Wextra

CC	= gcc

RM	= rm -f

$(NAME) :
	$(CC) -c $(CFLAGS) $(SRCS)
	ar cr $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re