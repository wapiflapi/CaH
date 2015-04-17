##
## Makefile for clean in /home/ampotos/c@h/cq-ctf/challs/reverse/demochescene/dev/clean
## 
## Made by 
## Login   <ampotos@epitech.net>
## 
## Started on  Mon Apr 13 21:08:42 2015 
## Last update Wed Apr 15 20:09:11 2015 
##

CC = gcc

CFLAGS += -std=gnu99 -shared

RM = rm -f

SRC = third.c

OBJ = $(SRC:.c=.o)

NAME = third

all: $(OBJ)
	objcopy --dump-section .text=$(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re : fclean all
