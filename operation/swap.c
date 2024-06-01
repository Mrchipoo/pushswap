/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mba <mba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:59:24 by echoubby          #+#    #+#             */
/*   Updated: 2024/06/01 20:09:40 by mba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test.h"

void	ft_swap_a(walo **head_a)
{
	walo	*temp;
	walo	*temp1;

	if (*head_a == NULL ||(*head_a)->next == NULL)
		return ;
    temp = (*head_a);
    temp1 = (*head_a)->next;
    (temp->next) = temp1->next;//first node poiting on the next of second node
    (*head_a) = temp1;//head poiting on second node
    temp1->next = temp;//second node poiting on first node 
    printf("sa\n");
}

void ft_swap_b(walo **head_b)
{
    walo *temp;
    walo *temp1;

    if (*head_b == NULL ||(*head_b)->next == NULL)
        return ;
    temp = (*head_b);
    temp1 = (*head_b)->next;
    (temp->next) = temp1->next;
    (*head_b) = temp1;
    temp1->next = temp;
    printf("sb\n");
}

void ft_swap_both(walo **head_a, walo **head_b)
{
    walo *temp;
    walo *temp1;
    if (*head_b == NULL ||(*head_b)->next == NULL
        || *head_a == NULL ||(*head_a)->next == NULL)
        return ;
    else
    {
        temp = (*head_b);
        temp1 = (*head_b)->next;
        (temp->next) = temp1->next;
        (*head_b) = temp1;
        temp1->next = temp;
        temp = (*head_a);
        temp1 = (*head_a)->next;
        (temp->next) = temp1->next;
        (*head_a) = temp1;
        temp1->next = temp;
    }
    printf("ss\n");
}
