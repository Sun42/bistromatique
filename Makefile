##
## makefile for makefile ex2 jour10 in /u/all/sundas_c/cu/rendu/piscine/Jour_10
## 
## Made by christophe sundas
## Login   <sundas_c@epitech.net>
## 
## Started on  Tue Oct 21 18:25:49 2008 christophe sundas
## Last update Mon Nov  3 22:49:04 2008 christophe sundas
##

NAME = calc
SRC = 				main.c \
				eval_expr.c \
				utils.c \
				utils2.c \
				utils3.c \
				utils4.c \
				utils_cleanstr.c \
				parenthesis_mode.c \
				format_expr.c \
				operations.c \
				operations2.c \
				addition.c \
				soustraction.c \
				multiplication.c \
				division.c \
				modulo.c

OBJ = $(SRC:.c=.o)
CFLAGS = -I./lib -I.
INCLUDES = -L./lib -lmy
RM = rm -f
CC = gcc

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(INCLUDES)

all: $(NAME)

clean :
	$(RM) $(OBJ)
	$(RM) *~
	$(RM) $(NAME)

.PHONY: all clean fclean re