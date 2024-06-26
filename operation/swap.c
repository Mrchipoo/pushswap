/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mba <mba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:59:24 by echoubby          #+#    #+#             */
/*   Updated: 2024/06/07 16:00:51 by mba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test.h"

void	ft_swap(t_walo **head, int mode)
{
	t_walo	*temp;
	t_walo	*temp1;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return ;
	temp = (*head);
	temp1 = (*head)->next;
	(temp->next) = temp1->next;
	(*head) = temp1;
	temp1->next = temp;
	if (mode == 0)
		write(1, "sa\n", 3);
	else if (mode == 1)
		write(1, "sb\n", 3);
}

void	ft_swap_both(t_walo **head_a, t_walo **head_b)
{
	ft_swap(head_a, 2);
	ft_swap(head_b, 2);
	write(1, "ss\n", 3);
}
