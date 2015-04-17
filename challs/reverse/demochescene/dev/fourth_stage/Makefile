##
## Makefile for clean in /home/ampotos/c@h/cq-ctf/challs/reverse/demochescene/dev/clean
## 
## Made by 
## Login   <ampotos@epitech.net>
## 
## Started on  Mon Apr 13 21:08:42 2015 
## Last update Fri Apr 17 22:28:38 2015 
##

CC = gcc

CFLAGS += -std=gnu99 -shared -fno-stack-protector

RM = rm -f

SRC = fourth.c

OBJ = $(SRC:.c=.o)

NAME = fourth

all: $(OBJ)
	objcopy --dump-section .text=$(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re : fclean all
