/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoubby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:34:29 by echoubby          #+#    #+#             */
/*   Updated: 2024/06/08 00:40:21 by echoubby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/test.h"

void	ft_free(t_walo **head)
{
	t_walo	*current;

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

void	ft_free_stack(t_walo **head_a, t_walo **head_b, int mode)
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

t_lis	*ft_fill_lis5(t_lis **liss, int *squence)
{
	(*liss)->arr = squence;
	return (*liss);
}

void	ft_positive(int *arr)
{
	if (arr[0] >= arr[1])
	{
		arr[2] = arr[1];
		arr[0] = arr[0] - arr[1];
		arr[1] = 0;
	}
	else if (arr[0] < arr[1])
	{
		arr[2] = arr[0];
		arr[1] = arr[1] - arr[0];
		arr[0] = 0;
	}
}

void	ft_negative(int *arr)
{
	if (arr[0] >= arr[1])
	{
		arr[2] = arr[0];
		arr[1] = arr[1] - arr[0];
		arr[0] = 0;
	}
	else if (arr[0] <= arr[1])
	{
		arr[2] = arr[1];
		arr[0] = arr[0] - arr[1];
		arr[1] = 0;
	}
}
