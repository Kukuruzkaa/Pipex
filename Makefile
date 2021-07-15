# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/15 19:50:00 by ddiakova          #+#    #+#              #
#    Updated: 2021/07/15 19:50:04 by ddiakova         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			= pipex

SRCS 			= pipex.c \

OBJS			= $(SRCS:%.c=%.o)

RM 				= rm -rf

CC 				= clang
CFLAGS 			= -Wall -Werror -Wextra -g -c 
SRCDIR 			= src
OBJDIR 			= objs

OBJS = $(addprefix ${OBJDIR}/,${SRCS:.c=.o})

all:			$(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p ${@D}
	${CC} ${CFLAGS} -I./inc -c $< -o $@

$(NAME):		$(OBJS)
				$(CC) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJDIR)
			
				
fclean:			clean
				$(RM) $(NAME)

re: 			fclean all

.PHONY: 		all clean fclean 