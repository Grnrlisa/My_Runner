##
## EPITECH PROJECT, 2021
## B-CPE-110-REN-1-1-BSQ-lisa.garnier
## File description:
## Makefile
##

## Sources of the prog
SRC	=	sources/my_runner.c 		\
		sources/utils/my_putchar.c	\
		sources/utils/my_putstr.c	\
		sources/utils/my_itoa.c		\
		sources/utils/my_strlen.c	\
		sources/utils/my_atoi.c		\
		sources/main_funct.c		\
		sources/display_fnct.c		\
		sources/bob.c				\
		sources/parallax.c			\
		sources/parallax_start.c 	\
		sources/events.c			\
		sources/menu.c				\
		sources/menu_button.c		\
		sources/score.c				\
		sources/events_bob.c		\
		sources/music_gest.c		\
		sources/music_gest_annex.c 	\
		sources/obj_animate.c		\
		sources/map_obj.c			\
		sources/hitbox.c			\
		sources/game_over.c			\
		sources/bonus_lvl2.c

OBJ = $(SRC:.c=.o)

NAME =	my_runner

INCLUDE = -I include/

SMFL_FLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

## Compilation flags (auto pick-up)
CFLAGS = -Wall -W $(INCLUDE) $(SMFL_FLAGS)

## Make commande
all:	 $(OBJ)
	gcc -g -o $(NAME) $(SRC) $(INCLUDE) $(SMFL_FLAGS)

## clean commande : rm files object
clean:
	rm -f $(OBJ)


## fclean commande : rm binary
fclean:
	rm -f $(NAME)
	make clean


## re commande : remake after cleaning
re:
	make fclean
	make all


.PHONY: clean, fclean, re, all