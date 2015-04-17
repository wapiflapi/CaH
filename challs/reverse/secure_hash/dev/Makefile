CC	=	gcc
CFLAGS	=	-W -Wall -Wextra

SRC	=	main.c \
		md5.c
OBJ	=	$(SRC:.c=.o)

NAME	=	secure_hash

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
