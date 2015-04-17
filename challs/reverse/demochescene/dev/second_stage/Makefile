##
## Makefile for clean in /home/ampotos/c@h/cq-ctf/challs/reverse/demochescene/dev/clean
## 
## Made by 
## Login   <ampotos@epitech.net>
## 
## Started on  Mon Apr 13 21:08:42 2015 
## Last update Wed Apr 15 20:08:49 2015 
##

CC = gcc

CFLAGS += -std=gnu99 -shared

RM = rm -f

SRC = second.c

OBJ = $(SRC:.c=.o)

NAME = second

all: $(OBJ)
	objcopy --dump-section .text=$(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re : fclean all
