CC		= gcc

LIFBT	= ./libft

CFLAGS	= -Wall -Wextra -Werror -I$(LIFBT)

SRCS	= push_swap.c

NAME	= push_swap.a

OBJS	= ${SRCS:%.c=%.o}

$(NAME): $(OBJS)
	make -C $(LIFBT)
	cp $(LIFBT)/libft.a $(NAME)
	ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)
	make clean -C $(LIFBT)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIFBT)/libft.a

re: fclean all

.PHONY: all clean fclean re
