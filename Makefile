CC		=	gcc
LIFBT	= 	./libft
CFLAGS	=	-Wall -Wextra -Werror -I$(LIFBT)
# CFLAGS	= -g -fsanitize=address #delete later
SRCS	= 	main.c \
			check_errors.c \
			convert_input.c \
			push_swap.c \
			operate_s_p.c \
			operate_r.c \
			operate_rr.c \
			sort.c \
			quick_sort.c \
			put_result.c \
			validate_input.c

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
