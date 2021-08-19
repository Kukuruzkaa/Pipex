# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/24 13:57:56 by ddiakova          #+#    #+#              #
#    Updated: 2021/01/30 15:41:31 by ddiakova         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a

SRCS 			= ft_atoi.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_itoa.c \
				ft_memccpy.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_split.c\
				ft_strchr.c \
				ft_strdup.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strmapi.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strtrim.c \
				ft_substr.c \
				ft_tolower.c \
				ft_toupper.c

OBJS			= $(SRCS:.c=.o)

BONUS			= ft_lstnew.c \
			  	ft_lstadd_front.c \
			  	ft_lstlast.c \
			  	ft_lstadd_back.c \
			  	ft_lstdelone.c \
			  	ft_lstclear.c \
			  	ft_lstsize.c \
			  	ft_lstiter.c \
				ft_lstmap.c

BONUS_OBJS		= $(BONUS:.c=.o)

RM 				= rm -f

CFLAGS 			= -Wall -Werror -Wextra -c -g

CC				= clang

INCLUDE 		= \
		  		libft.h

all:			$(NAME)

$(NAME):		$(OBJS) $(INCLUDE)
					ar rcs $(NAME) $(OBJS)

$(OBJS):		$(SRCS)
				$(CC) $(CFLAGS) $(SRCS) -I $(INCLUDE)

$(BONUS_OBJS): $(BONUS)
				$(CC) $(CFLAGS) $(BONUS) -I $(INCLUDE)

bonus:			fclean $(OBJS) $(BONUS_OBJS)
					ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re: 			fclean all

.PHONY: 		all clean fclean re bonus
