# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/19 10:25:07 by qmoricea     #+#   ##    ##    #+#        #
#    Updated: 2018/11/19 10:27:35 by qmoricea    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME    = libftprintf.a

SRC        =

OBJ        = $(SRC:.c=.o)
.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(SRC) -o $(NAME)
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Create Printf"

./%.o: ./%.c
	gcc -Wall -Wextra -Werror -c $< -o $@
	printf '\033[0m[ ✔ ] %s\n\033[0m' "$<"

clean:
	rm -rf $(OBJ)
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Clean Libprintf"

fclean: clean
	rm -f $(NAME)
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Fclean Libprintf"

re: fclean all

.PHONY: clean fclean re all
