/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoubby <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:59:31 by echoubby          #+#    #+#             */
/*   Updated: 2024/06/06 17:48:53 by echoubby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test.h"

void	ft_rotate(walo **head, int mode)
{
	walo	*temp;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	temp = (*head);
	(*head) = (*head)->next;
	ft_last_node((temp))->next = temp;
	temp->next = NULL;
	if (mode == 0)
		write(1, "ra\n", 3);
	if (mode == 1)
		write(1, "rb\n", 3);
}

void	ft_rr(walo **head_a, walo **head_b)
{
	ft_rotate(head_a, 2);
	ft_rotate(head_b, 2);
	write(1, "rr\n", 3);
}
