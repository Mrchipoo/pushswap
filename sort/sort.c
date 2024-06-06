/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoubby <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:38:18 by echoubby          #+#    #+#             */
/*   Updated: 2024/06/03 19:44:13 by mba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test.h"

void	ft_small_sort(walo **head)
{
	walo	*biggest_node;

	biggest_node = ft_find_biggest(*head);
	if ((*head) == biggest_node)
		ft_rotate(head, 0);
	else if ((*head)->next == biggest_node)
		ft_reverse(head, 0);
	if ((*head)->data > ((*head)->next)->data)
		ft_swap(head, 0);
}
walo *ft_find_min(walo *head)
{
	int min;
	walo *node_min;

	min = head->data;
	node_min = head;
	while (head != NULL)
	{
		if (min > head->data)
		{
			min = head->data;
			node_min = head;
			head = head->next;
		}
		else
			head = head->next;
	}
	return (node_min);
}
walo	*ft_find_biggest(walo *head)
{
	walo	*current;
	walo	*node;
	int	max;

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
int *ft_empty_array(walo *head)
{
	int	*arr;
	int i;
	int count;

	i = 0;
	count = ft_lenght(head, 1, NULL);
	arr = malloc(count * sizeof(int));
	if (arr == NULL)
		return NULL;
	while (head != NULL)
	{
		arr[i] = head->data;
		head = head->next;
		i++;
	}
	return (arr);
}
