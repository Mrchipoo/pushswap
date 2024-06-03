/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mba <mba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:59:40 by echoubby          #+#    #+#             */
/*   Updated: 2024/06/03 19:34:50 by mba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test.h"

void	ft_push_2a(walo **head_a, walo **head_b)
{
	walo	*temp;

	if (*head_b == NULL)
		return ;
	else
	{
		temp = *head_b;
		*head_b = (*head_b)->next;
		temp->next = *head_a;
		*head_a = temp;
	}
	write(2, "pa\n", 3);
}

void	ft_push_2b(walo **head_a, walo **head_b)
{
	walo	*temp;

	if (*head_a == NULL)
		return ;
	else
	{
		temp = *head_a;
		*head_a = (*head_a)->next;
		temp->next = *head_b;
		*head_b = temp;
	}
	write(2, "pb\n", 3);
}
