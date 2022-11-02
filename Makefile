CC		= gcc

LIFBT	= ./libft

# CFLAGS	= -Wall -Wextra -Werror -I$(LIFBT)
#CFLAGS	= -g -fsanitize=address #delete later

SRCS	= main.c push_swap.c operator.c

NAME	= push_swap

OBJS	= ${SRCS:%.c=%.o}

$(NAME): $(OBJS)
	make -C $(LIFBT)
	$(CC) $(CFLAGS) $(OBJS) $(LIFBT)/libft.a -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)
	make clean -C $(LIFBT)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIFBT)/libft.a

re: fclean all

.PHONY: all clean fclean re
