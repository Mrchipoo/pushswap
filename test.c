/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mba <mba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 20:27:50 by mba               #+#    #+#             */
/*   Updated: 2024/05/20 21:19:19 by mba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void print_list(walo* node) 
{
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

walo *ft_last_node(walo *head)
{
    walo *new_node;
    new_node = head;
    while (new_node->next!=NULL)
        new_node =  new_node->next;
    return(new_node);
}

walo *ft_create_node(int data)
{
    walo *new_node;

    new_node = malloc(sizeof(walo));
    if (!new_node)
        return (0);
    new_node->data = data;
    new_node->next = NULL;
    return (new_node);
}

void ft_push_2a(walo **head_a,walo **head_b)
{
    walo *temp;
    
    if (*head_b == NULL)
        return;
    else
    {
        temp = *head_b;
        *head_b = (*head_b)->next;
        temp->next = *head_a;
        *head_a = temp;
    }
    printf("pa\n");
}

void ft_push_2b(walo **head_a,walo **head_b)
{
    walo *temp;
    
    if (*head_a == NULL)
        return;
    else
    {
        temp  = *head_a;
        *head_a = (*head_a)->next;
        temp->next = *head_b;
        *head_b = temp;
    }
    printf("pb\n");
}

void ft_rotate_a(walo **head_a)
{
    walo *temp;

    if ((*head_a)->next == NULL)
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

    if ((*head_b)->next == NULL)
        return ;
    temp = (*head_b);
    (*head_b) = (*head_b)->next;
    ft_last_node((temp))->next = temp;
    temp->next = NULL;
    printf("rb\n");
}

int main(int argc, char **argv)
{
    int i;

    i = 1;
    walo* head_a;
    walo *head_b;
    walo *new_node;

    head_b = NULL;
    head_a = NULL;
    if (argc < 2)
        return (1);
    while (i < argc)
    {
        new_node = ft_create_node(atoi(argv[i]));
        if (head_a == NULL)
            head_a=new_node;
        else
            ft_last_node(head_a)->next = new_node;
        i++;    
    }
    print_list(head_a);
    ft_push_2b(&head_a,&head_b);
    ft_push_2b(&head_a,&head_b);
    print_list(head_a);
    print_list(head_b);
    ft_push_2a(&head_a, &head_b);
    print_list(head_a);
    print_list(head_b);
    ft_rotate_a(&head_a);
    print_list(head_a);
    ft_rotate_a(&head_a);
    print_list(head_a);
    print_list(head_b);
    return (0);
}