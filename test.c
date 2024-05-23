/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoubby <marvin@42.fr>                   +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 20:27:50 by echoubby               #+#    #+#        */
/*   Updated: 2024/05/21 15:22:04 by echoubby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/test.h"

void	print_list(walo *head)
{
	while (head != NULL)
	{
		printf("%d -> ", head->data);
		head = head->next;
	}
	printf("NULL\n");
}

walo	*ft_last_node(walo *head)
{
	walo	*new_node;

	new_node = head;
	while (new_node->next != NULL)
		new_node = new_node->next;
	return (new_node);
}

walo	*ft_create_node(int data)
{
	walo	*new_node;

	new_node = malloc(sizeof(walo));
	if (!new_node)
		return (0);
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

walo	*ft_last_before(walo *head)
{
	walo *new_node;

	new_node = head;
	while ((new_node->next)->next != NULL)
		new_node = new_node->next;
	return (new_node);
}

int	main(int argc, char **argv)
{
	int	i;
	walo	*head_a;
	walo	*head_b;
	walo	*new_node;

	i = 1;
	head_b = NULL;
	head_a = NULL;
	if (argc < 2)
		return (1);
	while (i < argc)
	{
		new_node = ft_create_node(atoi(argv[i]));
		if (head_a == NULL)
			head_a = new_node;
		else
			ft_last_node(head_a)->next = new_node;
		i++;
	}
	print_list(head_a);
	ft_array(head_a);
	// new_node = ft_find_min(head_a);
	// printf("min = %d\n",new_node->data);
	// print_list(head_a);
	return (0);
}
