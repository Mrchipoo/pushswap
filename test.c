/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mba <mba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 20:27:50 by echoubby          #+#    #+#             */
/*   Updated: 2024/06/05 16:42:41 by mba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/test.h"

void	ft_check_duplicate(walo	*head)
{
	walo	*tmp;
	walo	*tmp2;
	int	i;
	
	tmp = head;
	while(tmp != NULL)
	{
		i = 0;
		tmp2 = head;
		while(tmp2 != NULL)
		{
			if (tmp->data == tmp2->data)
				i++;
			if (i >= 2)
				ft_free_stack(&head, NULL, 0);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

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

void	ft_free_stack(walo	**head_a, walo	**head_b, int	mode)
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
int	ft_search(int	argc, char	**argv)
{
	if (1 == argc || (2 == argc && !argv[1][0]))
		return (-1);
	argv = ft_split(argv[1], 32);
	return (0);
}
	
int	main(int	argc, char	**argv)
{
	walo	*head_a;
	walo	*head_b;

	head_b = NULL;
	head_a = NULL;
	if (argc < 2)
		return (0);
	if (ft_search(argc, argv) == -1)
		write(2, "Error\n", 6);
	head_a = ft_fill(argc, argv);
	if (ft_sorted(head_a))
		ft_free_stack(&head_a, &head_b, 0);
	if (ft_lenght(head_a, 1, NULL) == 2)
		ft_swap(&head_a, 0);
	if (ft_lenght(head_a, 1, NULL) == 3)
		ft_small_sort(&head_a);
	else
		ft_last_loop(&head_a, &head_b);
	ft_free_stack(&head_a, &head_b, 1);
	return (0);
}
