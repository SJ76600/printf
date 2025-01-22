# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjupille <sjupille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 16:01:34 by sjupille          #+#    #+#              #
#    Updated: 2024/11/18 15:56:06 by sjupille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
RM = rm -f

SOURCES =	ft_printf_utils.c \
			ft_printf_utils2.c\
			ft_printf.c

OBJETS = $(SOURCES:.c=.o)

all : $(NAME)

$(NAME):  $(OBJETS)
		ar -rcs $(NAME) $(OBJETS)
		ranlib $(NAME)
clean : 
		$(RM) $(OBJETS)

fclean : clean
		$(RM) $(NAME)

re : fclean all

%.o: %.c 
		 $(CC) -Wall -Wextra -Werror -c -g $< -o $@

.PHONY: all clean fclean re 
