#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erli <erli@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/22 12:53:22 by erli              #+#    #+#              #
#    Updated: 2019/02/26 16:53:20 by erli             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME			=		test

SRCSDIR			=		srcs

OBJSDIR			=		objs

SRCS			=		main_printfd.c			pfd_add_char.c		pfd_add_str.c	\
						pfd_unload_buf.c		pfd_manage_tag.c	pfd_read_tag.c	\
						pfd_convert.c			\
																					\
						pfd_num_type_size.c		pfd_num_to_str.c	pfd_arg_to_mem.c\
						pfd_arg_to_bin.c		pfd_write_num_to_str.c				\
						pfd_add_width.c			\
						pfd_no_conv.c			pfd_conv_d.c		\
						pfd_print_data.c											\
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
						@make -C libft

$(OBJSDIR)/%.o	:		$(SRCSDIR)/%.c $(HEADER)
						@mkdir -p $(OBJSDIR)
						@echo "Compiling: " $(GREEN) $@ $(DEFAULT)
						$(CC) -c $(CFLAGS) $(INCL) $< -o $@

norm			:		delsav
						make -C libft delsav
						@echo "==== Norme"  $(GREEN) $(SRCSDIR) $(DEFAULT) "===="
						norminette $(SRCSDIR) 
						@echo "==== Norme"  $(GREEN) "includes/" $(DEFAULT) "===="
						norminette includes/
						@echo "==== Norme"  $(GREEN) "libft/includes/" \
						$(DEFAULT) "===="
						norminette libft/includes 
						@echo "==== Norme"  $(GREEN) "libft/srcs/" $(DEFAULT) "===="
						norminette libft/srcs/ 

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
