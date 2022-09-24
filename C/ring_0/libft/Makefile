TARGET	= libft.a

SRCS	= $(shell find . -name "*.c")

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -Werror -Wall -Wextra

CC	= gcc

$(TARGET):	$(OBJS)
	$(CC) -c $(CFLAGS) $(SRCS)
	ar crs $(TARGET) $(OBJS)

all:	$(TARGET)

clean:
	@rm -f $(OBJS)

fclean:	clean
		@rm -f $(TARGET)

re:	fclean all

.PHONY:	all, clean, fclean, re