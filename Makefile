NAME = get_next_line.out

SRCS = get_next_line_utils.c \
get_next_line.c

OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -Wall -Werror -Wextra -I.

%.o: %.c
		$(CC) -o $@ -c $^ $(CFLAGS) -g

$(NAME): $(OBJS)

all: $(NAME)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
