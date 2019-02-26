# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: jadonvez <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/01/07 12:27:42 by jadonvez     #+#   ##    ##    #+#        #
#    Updated: 2019/01/14 16:59:52 by jadonvez    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fdf

CC = gcc

SRC = srcs/main.c srcs/parsing_fdf.c srcs/bresenham.c srcs/display.c srcs/algo_fdf.c \
		srcs/event_fdf.c srcs/color_gradient.c srcs/hud_fdf.c srcs/error_fdf.c

OBJ = $(SRC:.c=.o)

INC_HDR = -I./include -I./libft/include -I./minilibx_macos

INC_LIB = -L./libft -lft -L./minilibx_macos -lmlx \
		  -framework OpenGL -framework AppKit

CFLAGS = -Werror -Wextra -Wall $(INC_HDR)

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C libft
	@$(MAKE) -C minilibx_macos
	@printf "\033[33mFDF\033[0m\t\t\t\t\t\t\t\t[\033[92mCOMPILED\033[39m]\n"
	@$(CC) $(CFLAGS) $(INC_LIB) $(SRC) -o $(NAME)

%.o: %.c include/fdf.h
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@cd libft && $(MAKE) clean

fclean: clean
	@rm -f $(NAME)
	@cd libft && $(MAKE) fclean

re: fclean all
