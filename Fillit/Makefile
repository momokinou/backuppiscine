# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: nzenzela <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/30 14:01:53 by nzenzela     #+#   ##    ##    #+#        #
#    Updated: 2017/12/06 14:33:06 by qmoricea    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = fillit

OBJS = check.o \
		  out.o \
		  pos.o \
		  resolve.o \
		  main.o

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L libft/ -lft

./%.o: ./%.c
	make -C ./libft
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJS)
	make -C ./libft clean

fclean: clean
	make -C ./libft fclean
	rm -rf $(NAME)
	rm -rf $(OBJS)

re: fclean all

.PHONY: all clean fclean re
