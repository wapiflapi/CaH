##
## Makefile for send_me_your_secret in /home/ampotos/c@h/rev_50
## 
## Made by 
## Login   <ampotos@epitech.net>
## 
## Started on  Thu Mar 26 15:10:54 2015 
## Last update Mon Mar 30 22:29:30 2015 
##

CC = gcc

CFLAGS = -std=gnu99

ASM = nasm

AFLAGS = -f elf64

SRC = send_me_your_secret.c

ASRC = secret.s

OBJ = $(SRC:.c=.o) $(ASRC:.s=.o)

RM = rm -f

NAME = send_me_your_secret

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)
	strip --strip-unneeded  $(NAME)

%.o : %.s
	$(ASM) $(AFLAGS) $< -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
