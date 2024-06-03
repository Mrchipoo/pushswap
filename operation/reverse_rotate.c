/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mba <mba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:15:49 by echoubby          #+#    #+#             */
/*   Updated: 2024/06/03 19:43:27 by mba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test.h"

void	ft_reverse(walo **head, int mode )
{
	walo	*temp;
	walo	*last;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	temp = (*head);
	last = ft_last_node(temp);
	ft_last_before(temp)->next = NULL;
	(*head) = last;
	last->next = temp;
	if (mode == 0)
		write(2, "rra\n", 4);
	if (mode == 1)
		write(2, "rrb\n", 4);
}

void	ft_rrr(walo **head_a, walo **head_b)
{
	ft_reverse(head_a, 2);
	ft_reverse(head_b, 2);
	write(2, "rrr\n", 4);
}
