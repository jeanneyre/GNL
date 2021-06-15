NAME		=	get_next_line.a

CFLAGS		=	-Wall -Wextra -Werror -c

CC			=	gcc

SRCS        =    ft_get_next_line.c / ft_get_next_line_utils.c

SRCS_BONUS	=		

OBJS        =   $(SRCS:.c=.o)

OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)

all		:	$(NAME)

$(NAME)	:	 $(OBJS)
		ar crs $@ $(OBJS)

%.o 	:	%.c
		$(CC) $(CFLAGS) $< -o $@

bonus 	:	$(OBJS) $(OBJS_BONUS)
		ar rcs $(NAME) $^
		ranlib $(NAME)

clean	:
		rm -rf $(OBJS)
		rm -rf $(OBJS_BONUS)

fclean	:	clean
		rm -f $(NAME)

re		:	fclean all

#.PHONY	:	all re clean fclean bonus
