# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/05 22:12:35 by qmoricea     #+#   ##    ##    #+#        #
#    Updated: 2018/12/18 11:15:39 by qmoricea    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME    = libftprintf.a

SRC        = ft_printf.c \
			 gestion_flags.c \
			 gestion_length.c \
			 gestion_specifiers_noopt.c \
			 gestion_width.c \
			 printchar.c \
			 printf_char.c \
			 printf_flaghashtag.c \
			 printf_flags.c \
			 printf_flags_plus_space.c \
			 printf_flagzero.c \
			 printf_flagzero_int_octal.c \
			 printf_hexa_octal.c \
			 printf_hh_zero_hasht.c \
			 printf_length_zero_hasht.c \
			 printf_lengthzero.c \
			 printf_nbr.c \
			 printf_spacezero.c \
			 printf_width_hashtag.c \
			 printf_width_hashtag_hh.c \
			 printf_width_hashtag_length.c \
			 printf_width_minus.c \
			 printf_width_minus_int_hexa_octal.c \
			 printf_width_minus_length.c\
			 printf_width_space.c \
			 printf_width_space_int_hexa_octal.c \
			 printf_width_space_length.c \
			 printf_zero_hasht.c \
			 printnbr.c \
			 printunbr.c \
			 specifiers_int.c \
			 specifiersxo_lengthjz.c \
			 utilitaires.c

OBJ        = $(SRC:.c=.o)
.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
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
