NAME    = push_swap
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
INC     = -I includes/

SRCS    = srcs/main.c \
          srcs/parse.c \
          srcs/operations.c \
          srcs/stack_utils.c \
          srcs/sort_small.c \
          srcs/turk.c

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