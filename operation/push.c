/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mba <mba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:59:40 by echoubby          #+#    #+#             */
/*   Updated: 2024/06/07 16:00:33 by mba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test.h"

void	ft_push_2a(t_walo **head_a, t_walo **head_b)
{
	t_walo	*temp;

	if (*head_b == NULL)
		return ;
	else
	{
		temp = *head_b;
		*head_b = (*head_b)->next;
		temp->next = *head_a;
		*head_a = temp;
	}
	write(1, "pa\n", 3);
}

void	ft_push_2b(t_walo **head_a, t_walo **head_b)
{
	t_walo	*temp;

	if (*head_a == NULL)
		return ;
	else
	{
		temp = *head_a;
		*head_a = (*head_a)->next;
		temp->next = *head_b;
		*head_b = temp;
	}
	write(1, "pb\n", 3);
}
