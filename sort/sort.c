/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mba <mba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:38:18 by echoubby          #+#    #+#             */
/*   Updated: 2024/06/07 16:01:09 by mba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test.h"

void	ft_small_sort(t_walo **head)
{
	t_walo	*biggest_node;

	biggest_node = ft_find_biggest(*head);
	if ((*head) == biggest_node)
		ft_rotate(head, 0);
	else if ((*head)->next == biggest_node)
		ft_reverse(head, 0);
	if ((*head)->data > ((*head)->next)->data)
		ft_swap(head, 0);
}

t_walo	*ft_find_min(t_walo *head)
{
	int		min;
	t_walo	*node_min;

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

t_walo	*ft_find_biggest(t_walo *head)
{
	t_walo	*current;
	t_walo	*node;
	int		max;

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

int	*ft_empty_array(t_walo *head)
{
	int	*arr;
	int	i;
	int	count;

	i = 0;
	count = ft_lenght(head, 1, NULL);
	arr = malloc(count * sizeof(int));
	if (arr == NULL)
		return (NULL);
	while (head != NULL)
	{
		arr[i] = head->data;
		head = head->next;
		i++;
	}
	return (arr);
}
