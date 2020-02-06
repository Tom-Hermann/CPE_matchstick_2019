##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## make
##

SRC				=	src/my_put.c\
					src/my_put_nbr.c\
					src/my_getnbr.c\
					src/init.c\
					src/game.c\
					src/usefull.c\
					src/error_turn.c\
					src/read_keybord.c\
					src/set_option.c\
					src/info.c\
					src/key_word.c\
					src/restore.c\
					src/ia/ia_turn.c\
					src/ia/level_5/last_turn.c\
					src/ia/level_5/end_game.c\
					src/ia/level_5/other_turn.c\
					src/ia/level_5/sppr_line.c\
					src/ia/level_5/turn_total.c\
					src/ia/level_1/random_ai.c\
					src/ia/level_2/basic_ai.c\
					src/ia/level_3/normal_ai.c

SRC_M			=	src/main.c

SRC_UT			=	tests/*.c

OBJ				=	$(SRC:.c=.o)

OBJ_M			=	$(SRC_M:.c=.o)

INCLUDE			=	-I./include

NAME			=	matchstick

NAME_UT			=	unit_test

CFLAGS			=	-W -Werror -Wall -Wextra -g -I./include

CFLAGS_UT		=	-lcriterion --coverage

RM				=	rm -rf


all:		$(NAME)

$(NAME):	$(OBJ_M) $(OBJ)
		gcc -o $(NAME) $(OBJ) $(OBJ_M) $(INCLUDE) $(CFLAGS)

tests_run:
		gcc -o $(NAME_UT) $(SRC) $(SRC_UT) $(INCLUDE) $(CFLAGS_UT)
		./$(NAME_UT)

clean:
		$(RM) $(OBJ) $(OBJ_UT) $(OBJ_M)

fclean:		clean fclean_ut
		$(RM) $(NAME)
		$(RM) *.gcda *.gcno

fclean_ut:	clean
		$(RM) $(NAME_UT)
		$(RM) *.gcda *.gcno

re:		fclean all
