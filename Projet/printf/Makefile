# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/05 22:12:35 by qmoricea     #+#   ##    ##    #+#        #
#    Updated: 2018/11/05 22:36:50 by qmoricea    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

CC = gcc

NAME = libftprintf.a

SOURCES = ft_putchar.c\
		  ft_putnbr.c\
		  ft_putstr.c\
		  ft_strlen.c\
		  ft_intlen.c\
		  ft_printc.c\
		  ft_printl.c\
		  ft_printnbr.c\
		  ft_printstr.c\
		  ft_printf.c

OBJECT = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECT)
	ar rcs $(NAME) $(OBJECT)

./%.o: ./%.c
	$(CC) $(FLAGS) -o $@ -c $<

all: $(NAME)

clean:
	rm -rf $(OBJECT)

fclean: clean
	rm -fr $(NAME)

re: fclean all
