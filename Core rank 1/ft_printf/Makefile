NAME	=		libftprintf.a

CFLAGS	=		-Wall -Werror -Wextra

CC		=		cc

RM		=		rm -f

SRC		=		ft_character.c ft_hexadecimal.c \
				ft_number.c 					\
				ft_pointer.c ft_printf.c		\
				ft_string.c ft_unsigned.c 		\

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