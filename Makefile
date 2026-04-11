NAME    = push_swap
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g
INC     = -I .
OBJ_DIR	= obj

SRCS    = push_swap.c \
          parse.c \
          push_ops.c \
		  rotate_ops.c \
		  swap_ops.c \
		  rev_rotate_ops.c \
		  utils.c \
		  sort.c \
          stack_utils.c \
		  utils2.c

OBJS    = $(SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re