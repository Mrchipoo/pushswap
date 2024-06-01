/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mba <mba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:38:18 by echoubby          #+#    #+#             */
/*   Updated: 2024/06/01 20:16:38 by mba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test.h"

void	ft_small_sort(walo **head)
{
	walo	*biggest_node;

	biggest_node = ft_find_biggest(*head);
	if ((*head) == biggest_node)
		ft_ra(head);
	else if ((*head)->next == biggest_node)
		ft_rra(head);
	if ((*head)->data > ((*head)->next)->data)
		ft_swap_a(head);
}