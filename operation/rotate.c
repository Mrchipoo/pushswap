/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoubby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:59:31 by echoubby          #+#    #+#             */
/*   Updated: 2024/05/21 10:59:34 by echoubby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../test.h"

void ft_rotate_a(walo **head_a)
{
    walo *temp;

    if (*head_a == NULL || (*head_a)->next == NULL)
        return ;
    temp = (*head_a);
    (*head_a) = (*head_a)->next;
    ft_last_node((temp))->next = temp;
    temp->next = NULL;
    printf("ra\n");
}

void ft_rotate_b(walo **head_b)
{
    walo *temp;

    if (*head_b == NULL || (*head_b)->next == NULL)
        return ;
    temp = (*head_b);
    (*head_b) = (*head_b)->next;
    ft_last_node((temp))->next = temp;
    temp->next = NULL;
    printf("rb\n");
}

void ft_rr(walo **head_a, walo **head_b)
{
    walo *temp;

    if (*head_b == NULL  || *head_a == NULL|| (*head_a)->next == NULL 
        || (*head_b)->next == NULL)
        return ;
    else
    {
        temp = (*head_b);
        (*head_b) = (*head_b)->next;
        ft_last_node((temp))->next = temp;
        temp->next = NULL;
        temp = (*head_a);
        (*head_a) = (*head_a)->next;
        ft_last_node((temp))->next = temp;
        temp->next = NULL;
    }
    printf("rr\n");
}