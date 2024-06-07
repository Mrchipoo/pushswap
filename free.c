/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoubby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:34:29 by echoubby          #+#    #+#             */
/*   Updated: 2024/06/06 17:34:33 by echoubby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/test.h"

void	ft_free(walo **head)
{
	walo	*current;

	if (head == NULL || *head == NULL)
		return ;
	while (*head)
	{
		current = (*head)->next;
		free(*head);
		*head = current;
	}
	*head = NULL;
}

void	ft_free_stack(walo **head_a, walo **head_b, int mode)
{
	ft_free(head_a);
	ft_free(head_b);
	if (mode == 0)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	exit(0);
}
