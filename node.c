/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mba <mba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:35:10 by echoubby          #+#    #+#             */
/*   Updated: 2024/06/07 16:02:48 by mba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/test.h"

t_walo	*ft_last_node(t_walo *head)
{
	t_walo	*new_node;

	new_node = head;
	while (new_node->next != NULL)
		new_node = new_node->next;
	return (new_node);
}

t_walo	*ft_create_node(int data)
{
	t_walo	*new_node;

	new_node = malloc(sizeof(t_walo));
	if (!new_node)
		return (0);
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

t_walo	*ft_last_before(t_walo *head)
{
	t_walo	*new_node;

	new_node = head;
	while ((new_node->next)->next != NULL)
		new_node = new_node->next;
	return (new_node);
}

int	ft_sorted(t_walo	*head)
{
	t_walo	*tmp;

	tmp = head;
	while (tmp->next != NULL)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_walo	*ft_fill(char	**str)
{
	int		i;
	t_walo	*new_node;
	t_walo	*current;
	t_walo	*first;

	i = 0;
	current = NULL;
	while (str[i])
	{
		new_node = ft_create_node(ft_atoi(str[i]));
		if (current == NULL)
		{
			current = new_node;
			first = current;
		}
		else
			ft_last_node(current)->next = new_node;
		free(str[i]);
		i++;
	}
	free(str);
	if (first)
		ft_check_duplicate(first);
	return (first);
}
