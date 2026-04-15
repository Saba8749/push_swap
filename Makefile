NAME    = push_swap
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g
INC     = -I .
OBJ_DIR	= obj

SRCS    = push_swap.c \
		  parse.c \
		  validate.c \
		  free.c \
		  ft_utils.c \
		  Split.c \
		  algo_utils.c \
		  push_ops.c \
		  rotate_ops.c \
		  swap_ops.c \
		  rev_rotate_ops.c \
		  ksort.c \
		  stack_utils.c \
		  small_sort.c \
		  sort_stack.c

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