# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: qmoricea <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/09/14 11:01:32 by qmoricea     #+#   ##    ##    #+#        #
#    Updated: 2018/09/14 11:12:31 by qmoricea    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

# Config de base
NAME		= fdf
CC			= gcc
FLAGS		= -Wall -Wextra -Werror
MKDIR		= mkdir -p
ECHO		= echo -e
QUIET		= @
NORME		= norminette -R CheckForbiddenSourceHeader

# Gestion des librairies
LIBF		= libft
LIBMLX		= minilibx_macos
CLIB		= -framework OpenGL -framework Appkit
LIB			= $(LIBF)/libft.a \	
			  $(LIBMLX)/libmlx.a \
$(CLIB)

# Gestion des Includes/Sources
INCDIR		= inc
INC			= $(INCDIR) \
			  $(LIBF)/$(INCDIR) \
			  $(LIBMLX)
SRCDIR		= src
SRC			= \
OBJDIR		= obj
OBJ			= $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

# Set edit text
END			= \033[0m
BOLD		= \033[1m
UNDER		= \033[4m
REV			= \033[7m

# Couleurs
GREY		= \033[30m
RED			= \033[31m
GREEN		= \033[32m
YELLOW		= \033[33m
BLUE		= \033[34m
PURPLE		= \033[35m
CYAN		= \033[36m
WHITE		= \033[37m
SGREY		= \033[40m
SRED		= \033[41m
SGREEN		= \033[42m
SYELLOW		= \033[43m
SBLUE		= \033[44m
SPURPLE		= \033[45m
SCYAN		= \033[46m
SWHITE		= \033[47m

# Règles
.PHONY: all clen fclean re

all: $(NAME)

$(NAME): $(LIBF)/libft.a $(LIBMLX)/libmlx.a $(OBJDIR) $(OBJ)
         $(QUIET)$(ECHO) "\033[4;31mCréation des executables\033[0m"
		 $(QUIET)$(CC)$(FLAGS)$(LIB)$(OBJ) -o $@
		 $(QUIET)$(ECHO) "\033[4;37mOK\033[0"


$(OBJDIR): $(QUIET)$(MKDIR) $(OBJDIR)
