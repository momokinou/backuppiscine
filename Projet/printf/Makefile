# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/05 22:12:35 by qmoricea     #+#   ##    ##    #+#        #
#    Updated: 2018/11/20 08:28:27 by qmoricea    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME    = libftprintf.a

SRC        = ft_printf.c \
			 intlen.c \
			 printchar.c \
			 printfchar2.c \
			 printhexa.c \
			 printlong.c \
			 printnbr.c \
			 printoctal.c \
			 printshort.c \
			 printunbr.c \
			 checkspec.c \
			 spechar.c \
			 specjz.c \
			 specxo.c \
			 speint.c \
			 printnoopt.c \
			 checkflags.c \
			 printflags.c \
			 printflagszero.c \
			 gestwidth.c \
			 funcforwidth.c \
			 printf_width.c

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
