CC	=	gcc
CFLAGS	=	-W -Wall -Wextra

SRC	=	c.c
OBJ	=	$(SRC:.c=.o)

NAME	=	ex42

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
