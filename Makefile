# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mba <mba@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 14:21:06 by echoubby          #+#    #+#              #
#    Updated: 2024/06/01 21:36:04 by mba              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS=-Wall -Werror -Wextra -g3
Src = operation/push.c operation/rotate.c operation/swap.c operation/reverse_rotate.c utiliti/help.c sort/sort.c sort/quicksort.c test.c
object = $(Src:.c=.o)
NAME = push_swap

all: $(NAME)

$(NAME):$(object)
	$(CC) $(CFLAGS) $(object) -Iincludes  -g3  -o $(NAME)
clean:
	rm -f $(object)
fclean:clean
	rm -f $(NAME)
re:fclean all




