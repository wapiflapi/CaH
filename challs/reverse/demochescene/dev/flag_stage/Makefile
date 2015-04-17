##
## Makefile for  in /home/eax/dev/demoscenne/test
## 
## Made by eax
## Login   <soules_k@epitech.net>
## 
## Started on  Mon Mar 30 23:51:52 2015 eax
## Last update Wed Apr 15 19:50:43 2015 
##

CXX	=	g++
CXXFLAGS=	-W -Wall -Wextra -O3

LDFLAGS	=	-lGL -lGLU -lglut -lpthread -lm

SRC	=	main.cpp
OBJ	=	$(SRC:.cpp=.o)

NAME	=	demochescene

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
