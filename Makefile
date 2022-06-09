##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## FINALLY
##

OBJ			=	$(SRC:.c=.o)

SRC_FILE	= src_file

PARTIE_1	= src_file/partie1

PARTIE_2	= src_file/partie2

NAME		=	SBMLparser

CPPFLAGS	=	-I./include

LIBNAME		=	libmy.a

DEBUG		=	-g3

CFLAGS		=	-Wall -Wextra

LDFLAGS		=	-L./lib -lmy

SRC	=	$(SRC_FILE)/main.c 							\
		$(SRC_FILE)/requirement.c 					\
		$(SRC_FILE)/display_way.c 					\
		$(SRC_FILE)/get_compartment_array.c 		\
		$(SRC_FILE)/get_tagsattributes.c			\
		$(PARTIE_1)/get_alphabetic_order_tab.c		\
		$(PARTIE_1)/get_display.c					\
		$(PARTIE_1)/get_display2.c					\
		$(PARTIE_1)/alpha_arg_tri.c					\
		$(PARTIE_2)/detect_name.c					\
		$(PARTIE_2)/filter_array.c					\
		$(PARTIE_2)/void_function.c					\
		$(PARTIE_2)/display_cat.c					\

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my/
		gcc -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)


clean:
		$(RM) $(OBJ)

fclean:		clean
		make fclean -C lib/my
		$(RM) $(NAME)
		$(RM) lib/$(LIBNAME)

debug:		CFLAGS+=$(DEBUG)
debug: 		fclean $(NAME)
			valgrind ./SBMLparser sbml/1A.sbml -i r

re:		fclean all

LDFLAGS += -lcriterion --coverage

tests_run:
		make -C lib/my/;
		gcc tests/test.c $(SRC_TEST) $(CPPFLAGS) $(LDFLAGS)

.PHONY:		all clean fclean re
