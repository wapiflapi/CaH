##
## Makefile for clean in /home/ampotos/c@h/cq-ctf/challs/reverse/demochescene/dev/clean
## 
## Made by 
## Login   <ampotos@epitech.net>
## 
## Started on  Mon Apr 13 21:08:42 2015 
## Last update Wed Apr 15 15:55:50 2015 eax
##

CC = gcc

CFLAGS += -std=gnu99

LDFLAGS = -lrt

RM = rm -f

SRC = setup.c

OBJ = $(SRC:.c=.o)

NAME = demochescene

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re : fclean all
