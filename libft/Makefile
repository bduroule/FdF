# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: beduroul <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/04 12:26:16 by beduroul     #+#   ##    ##    #+#        #
#    Updated: 2018/10/24 22:31:25 by beduroul    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

#Color
GREEN 	= \e[92m
END 	= \e[97m
END2	= \e[0m
GREEN2	= \e[92;7m

#Compil
CC 		= gcc
CFLAGS 	= -Wall -Werror -Wextra -I./include

#Dir
OBJ_PATH = ./obj
SRC_PATH = ./src
INC_PATH = ./include

#File
NAME = libft.a
INC_NAME = libft.h get_next_line.h
SRC_NAME =	ft_atoi.c			ft_strcmp.c			ft_strcpy.c 		\
			ft_strlen.c			ft_strncmp.c		ft_strncpy.c 		\
			ft_memcpy.c			ft_memset.c			ft_bzero.c			\
 	  		ft_memccpy.c		ft_memmove.c		ft_memchr.c			\
 	  		ft_memcmp.c			ft_strdup.c			ft_strcat.c			\
 	 		ft_strncat.c 		ft_strlcat.c		ft_strchr.c			\
 	  		ft_isalpha.c		ft_isdigit.c		ft_isalnum.c		\
 	  		ft_strrchr.c		ft_strstr.c			ft_isascii.c 		\
 	  		ft_isprint.c		ft_toupper.c		ft_tolower.c		\
 	  		ft_putchar.c		ft_putstr.c 		ft_strnstr.c		\
 	  		ft_strclr.c			ft_putnbr.c			ft_putendl.c		\
 	  		ft_striter.c		ft_striteri.c		ft_memdel.c			\
 	  		ft_strnew.c 		ft_memalloc.c		ft_putchar_fd.c		\
 	  		ft_putendl_fd.c		ft_putnbr_fd.c 		ft_putstr_fd.c		\
 	  		ft_strdel.c			ft_strmap.c			ft_strmapi.c 		\
 	 	 	ft_strequ.c			ft_strnequ.c		ft_strsub.c			\
 	 	 	ft_strjoin.c		ft_strtrim.c		ft_strsplit.c		\
 	 	 	ft_itoa.c			ft_lstnew.c			ft_intsize.c		\
 	  		ft_lstdelone.c		ft_lstdel.c			ft_lstadd.c 		\
 	 	 	ft_lstiter.c		ft_lstmap.c			ft_strrev.c			\
 	  		ft_foreach.c		ft_factorial.c		ft_power.c			\
 	  		ft_is_prime.c		ft_swap.c			ft_range.c 			\
 		  	ft_intsize.c 		get_next_line.c		ft_sqrt.c			\
			ft_strcchr.c

INC = $(addprefix $(INC_PATH)/, $(INC_NAME))  	
OBJ	= $(addprefix $(OBJ_PATH)/, $(SRC_NAME:.c=.o))
SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

all: obj $(NAME)

$(NAME): $(OBJ)
	@ar -rcs $(NAME) $?
	@printf "\nlibft built.................................................... \
	$(GREEN)[ok]$(END)\n"

obj:
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(GREEN2) $(END2)"

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_PATH)
	@printf "remove obect................................................... \
	$(GREEN)[ok]$(END)\n"

fclean: clean
	@rm -f $(NAME)
	@printf "remove libft................................................... \
	$(GREEN)[ok]$(END)\n"

re: fclean all
