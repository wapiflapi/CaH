CC	=	gcc
CCCFLAGS=	-W -Wall -Wextra

LDFLAGS	=	-lm

SRC	=	chall.c
OBJ	=	$(SRC:.c=.o)

NAME	=	bipolar

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)
	strip -s $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
