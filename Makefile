##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC     =	src/main.c							\
			src/clear.c							\
			src/check_env.c						\
			src/creations.c						\
			src/event/event.c					\
			src/central_loop.c					\
			src/draw_entities.c					\
			src/initializations.c				\
			src/free_and_destroy.c				\
			src/set/set_bin.c					\
			src/set/set_tools.c					\
			src/set/set_bucket.c				\
			src/set/set_window.c				\
			src/set/set_shapes.c				\
			src/set/set_thickness.c				\
			src/set/set_drop_menu.c				\
			src/set/set_image_pixel.c			\
			src/event/resize_window.c			\
			src/event/buttons_hover.c			\
			src/event/buttons_clicked.c			\
			src/colors/set_shades.c				\
			src/colors/set_other_colors.c		\
			src/colors/set_blade_colors.c		\
			src/colors/set_primary_colors.c		\
			src/button_actions/help.c			\
			src/button_actions/save_file.c		\
			src/button_actions/fill_drawing.c	\
			src/button_actions/fill_cross.c		\
			src/button_actions/flip_image.c		\
			src/button_actions/import_file.c	\
			src/button_actions/print_login.c	\
			src/update_mouse.c	\
			src/set/set_hammer.c	\

OBJ     =	$(SRC:.c=.o)

NAME    =	paint

LIB		=	lib/libmy.a

CFLAGS	= 	-Wall -Wextra

CPPFLAGS	=	-I./include

LDFLAGS	=	-lmy -lcsfml-system -lcsfml-window -lcsfml-graphics -lcsfml-audio \
-lm

LDLIBS	=	-L./lib

all:    $(NAME)

$(LIB):
	make -C ./lib/my

$(NAME):	$(LIB) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDLIBS) $(LDFLAGS)

debug:	CFLAGS += -g3

debug:	re

clean:
	$(RM) $(OBJ)
	make -C ./lib/my clean

fclean: clean
	$(RM) $(NAME)
	make -C ./lib/my fclean

re:	fclean $(NAME)

.PHONY: all clean fclean re debug
