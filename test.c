/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mba <mba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 20:27:50 by echoubby          #+#    #+#             */
/*   Updated: 2024/05/23 22:33:08 by mba              ###   ########.fr       */
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
void ft_push(walo **head_a, int mid, walo **head_b)
{
	walo	*current;
//	walo	*temp;	

	current = *head_a;
	while (current != NULL)
	{
		printf("%d  \n",current->data);
		if (current->data < mid)
			ft_push_2b(head_a, head_b);
		else
			ft_rotate_a(head_a);
		current = *head_a;
	}
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
	i = ft_array(head_a);
	printf("%d\n",i);
	ft_push(&head_a, i, &head_b);
	print_list(head_a);
	print_list(head_b);
	// new_node = ft_find_min(head_a);
	// printf("min = %d\n",new_node->data);
	// print_list(head_a);
	return (0);
}
