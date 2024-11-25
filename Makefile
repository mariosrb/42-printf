CC = cc

CFLAGS = -Wall -Werror -Wextra

SRC = ./ft_printf.c ./ft_ptr.c ./ft_putlstr.c ./ft_putnbr_hex.c ./ft_putnbr_u.c ft_putnbr.c

OBJ = $(SRC:.c=.o)

AR = ar -rcs

NAME = libftprintf.a

$(NAME) : $(OBJ)
	$(AR) $(NAME) $(OBJ)

all : $(NAME)
	$(AR) $(NAME) $(OBJ)
.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re