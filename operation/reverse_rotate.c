/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoubby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:15:49 by echoubby          #+#    #+#             */
/*   Updated: 2024/05/21 13:58:49 by echoubby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/test.h"

void	ft_rra(walo **head_a)
{
	walo	*temp;
	walo	*last;

	if (*head_a == NULL || (*head_a)->next == NULL)
		return ;
	temp = (*head_a);
	last = ft_last_node(temp);
	ft_last_before(temp)->next = NULL;// last before node poiting to null
	(*head_a) = last;//head now poiting on last node
	last->next = temp;//last node poiting on the first and become first
	printf("rra\n");
}

void	ft_rrb(walo **head_b)
{
	walo	*temp;
	walo	*last;

	if (*head_b == NULL || (*head_b)->next == NULL)
		return ;
	temp = (*head_b);
	last = ft_last_node(temp);
	ft_last_before(temp)->next = NULL;
	(*head_b) = last;
	last->next = temp;
	printf("rrb\n");
}

void	ft_rrr(walo **head_a, walo **head_b)
{
	walo	*temp;
	walo	*last;

	if (*head_b == NULL || (*head_b)->next == NULL
		|| *head_a == NULL || (*head_a)->next == NULL)
		return ;
	else
	{
		temp = (*head_a);
		last = ft_last_node(temp);
		ft_last_before(temp)->next = NULL;
		(*head_a) = last;
		last->next = temp;
		temp = (*head_b);
		last = ft_last_node(temp);
		ft_last_before(temp)->next = NULL;
		(*head_b) = last;
		last->next = temp;
	}
	printf("rrr\n");
}
