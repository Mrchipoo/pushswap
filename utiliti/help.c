/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoubby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:14:38 by echoubby          #+#    #+#             */
/*   Updated: 2024/05/23 10:14:42 by echoubby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/test.h"

walo *ft_biggest_value(walo *head)
{
    walo *current;
    walo *node;
    int max;

    current = head->next;
    node = head;
    max = head->data;
    while (current != NULL)
    {
        if (max > current->data)
            current = current->next;
        else
        {
            max = current->data;
            node = current;
            current = current->next;
        }
    }
    return (node);
}

