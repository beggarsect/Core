NAME	=		libftprintf.a

CFLAGS	=		-Wall -Werror -Wextra

CC		=		cc

RM		=		rm -f

SRC		=		??????????????????????????????

OBJS	=		$(SRC:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

%.o: %.c
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@$(RM) $(OBJS)

fclean:	clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY: all, clean, fclean, re