# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mba <mba@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 14:21:06 by echoubby          #+#    #+#              #
#    Updated: 2024/06/05 22:38:06 by mba              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS=-Wall -Werror -Wextra -g3
Src = operation/push.c operation/rotate.c operation/swap.c operation/reverse_rotate.c utiliti/help.c sort/sort.c sort/quicksort.c split.c utiliti/libft.c node.c LIS.c calcul.c action.c free.c test.c
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




