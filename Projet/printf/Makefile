# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/05 22:12:35 by qmoricea     #+#   ##    ##    #+#        #
#    Updated: 2018/11/13 13:55:51 by qmoricea    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME    = libftprintf

SRC        = ft_printf.c \
			 intlen.c \
			 printchar.c \
			 printhexa.c \
			 printlong.c \
			 printnbr.c \
			 printoctal.c \
			 printshort.c \
			 printunbr \
			 main.c

OBJ        = $(patsubst src/%.c,obj/%.o,$(SRC))
.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	gcc  $(SRC) -o $(NAME)
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Create Fractol"

obj/%.o: src/%.c
	mkdir -p obj
	gcc -Wall -Wextra -Werror -c $< -o $@
	printf '\033[0m[ ✔ ] %s\n\033[0m' "$<"

clean:
	/bin/rm -rf obj/
	make -C libft/ clean
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Clean Libprintf"

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft/ fclean
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Fclean Libprintf"

re: fclean all

test: re
	printf '\033[32m%s\n\033[0m' "-------------------------------------"
	./fdf

all: $(NAME)
	.PHONY: clean fclean re all
