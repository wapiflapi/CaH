##
## Makefile for clean in /home/ampotos/c@h/cq-ctf/challs/reverse/demochescene/dev/clean
## 
## Made by 
## Login   <ampotos@epitech.net>
## 
## Started on  Mon Apr 13 21:08:42 2015 
## Last update Fri Apr 17 22:29:38 2015 
##

CC = gcc

CFLAGS += -std=gnu99 -shared -fno-stack-protector

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
