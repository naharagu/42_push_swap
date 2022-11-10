CC		=	gcc
LIFBT	= 	./libft
CFLAGS	=	-Wall -Wextra -Werror -I$(LIFBT) -g -fsanitize=address
SRCS	= 	main.c \
			check_errors.c \
			convert_input.c \
			push_swap.c \
			operate_s_p.c \
			operate_r.c \
			operate_rr.c \
			sort.c \
			put_result.c \
			validate_input.c \
			ft_split_and_count.c

NAME	=	push_swap

OBJS	=	${SRCS:%.c=%.o}

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
