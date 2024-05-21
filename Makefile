# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: echoubby <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 14:21:06 by echoubby          #+#    #+#              #
#    Updated: 2024/05/21 14:21:09 by echoubby         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
cc=cc
Cflag=-Wall -Werror -Wextra
Src = operation/*.c  test.c
NAME = push_swap

all: $(NAME)

$(NAME):
	$(cc) $(Cflag) $(Src) -Iincludes -o $(NAME)
clean:
	rm -f operation/*.o test.o
fclean:clean
	rm -f $(NAME)
re:fclean all




