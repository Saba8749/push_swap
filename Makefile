NAME    = push_swap
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
INC     = -I .

SRCS    = push_swap.c \
          parse.c \
          operations.c \
          stack_utils.c 

OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re