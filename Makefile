##
## Makefile for  in /home/groulef/Documents/Projet_Easter
## 
## Made by GROULEZ Florian
## Login   <groule_f@etna-alternance.net>
## 
## Started on  Thu Apr  2 10:58:51 2015 GROULEZ Florian
## Last update Wed Apr  8 08:52:33 2015 GROULEZ Florian
##

CC	=		gcc `sdl-config --cflags`

CC2	=		gcc `sdl-config --libs`

NAME	=		back_to_midgar

SRC	=		$(wildcard *.c)

OBJ	=		$(SRC:%.c=%.o)

RM	=		rm -f

DFLAGS	=		-Wall -Werror -W -pedantic

$(NAME):
			$(CC) $(DFLAGS) -c $(SRC)
			$(CC2) -lSDL_image -lSDL_ttf -o $(NAME) $(OBJ)

all:			$(NAME)

clean:
			$(RM) *.o

fclean:			clean
			$(RM) $(NAME)

re:			fclean all