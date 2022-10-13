NAME	= get_next_line.a

SRCS	= get_next_line.c get_next_line_utils.c

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -Werror -Wall -Wextra -D BUFFER_SIZE=42

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