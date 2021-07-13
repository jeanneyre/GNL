NAME		=	get_next_line.a

CFLAGS		=	-Wall -Wextra -Werror -c

CC			=	gcc

SRCS        =    get_next_line.c get_next_line_utils.c \

OBJS        =   $(SRCS:.c=.o)

all		:	$(NAME)

$(NAME)	:	 $(OBJS)
		ar crs $@ $(OBJS)

%.o 	:	%.c
		$(CC) $(CFLAGS) $< -o $@

clean	:
		rm -rf $(OBJS)

fclean	:	clean
		rm -f $(NAME)

re		:	fclean all

#.PHONY	:	all re clean fclean
