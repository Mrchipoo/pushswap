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
Src = operation/push.c operation/rotate.c operation/swap.c operation/reverse_rotate.c  test.c
object = $(Src:.c=.o)
NAME = push_swap

all: $(NAME)

$(NAME):$(object)
	$(cc) $(Cflag) $(object) -Iincludes -o $(NAME)
clean:
	rm -f $(object)
fclean:clean
	rm -f $(NAME)
re:fclean all




