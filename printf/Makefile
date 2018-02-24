# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/02/19 09:55:37 by qmoricea     #+#   ##    ##    #+#        #
#    Updated: 2018/02/19 09:56:57 by qmoricea    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

C = gcc

FLAGS = -Wall -Wextra -Werror

NAME = libftprint.a

SOURCES =

OBJECT = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECT)
	ar rcs $(NAME) $(OBJECT)

./%.o: ./%.c
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJECT)

fclean: clean
	rm -fr $(NAME)

re: fclean all
