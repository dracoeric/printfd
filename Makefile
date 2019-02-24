#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erli <erli@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/22 12:53:22 by erli              #+#    #+#              #
#    Updated: 2019/02/24 18:14:44 by erli             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME			=		test

SRCSDIR			=		srcs

OBJSDIR			=		objs

SRCS			=		main_printfd.c			pfd_add_char.c		pfd_unload_buf.c\
						pfd_manage_tag.c		pfd_read_tag.c		pfd_convert.c	\
																					\
						main.c

OBJS			=		$(addprefix $(OBJSDIR)/, $(SRCS:.c=.o))

HEADER			=		includes/ft_printfd.h libft/includes

CC				=		gcc -g

CFLAGS			=		-Wall -Werror -Wextra

INCL			=		-I includes/ -I libft/includes

RM				=		rm -f

ADDLIB			=		-L libft/ -lft

LIB				=		libft/libft.a

GREEN			=		"\x1B[32m"

DEFAULT			=		"\x1B[0m"

all				:		libft $(NAME)

$(NAME)			:		$(OBJS) $(LIB) $(HEADER)
						@echo "Compiling: " $(GREEN) $(NAME) $(DEFAULT)
						$(CC) $(CFLAGS) $(INCL) $(OBJS) $(ADDLIB) -o $(NAME)

libft			:
						@echo "Compiling: " $(GREEN) $(LIB) $(DEFAULT)
						@make -C libft

$(OBJSDIR)/%.o	:		$(SRCSDIR)/%.c $(HEADER)
						@mkdir -p $(OBJSDIR)
						$(CC) -c $(CFLAGS) $(INCL) $< -o $@

norm			:		delsav
						norminette $(SRCDIR) includes/ libft/srcs libft/includes

delsav			:
						$(RM) *~
						$(RM) */*~
						$(RM) \#*\#
						$(RM) */\#*\#

clean			:
						$(RM) $(OBJS)

fclean			:		clean
						$(RM) $(NAME)

re				:		fclean
						@make all

reset			:		delsav
						@make fclean
						@make -C libft reset

.PHONY			:		delsav clean fclean re reset libft
