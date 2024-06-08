/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mba <mba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:14:38 by echoubby          #+#    #+#             */
/*   Updated: 2024/06/08 00:51:59 by echoubby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/test.h"

void	ft_condition(t_lis *lis, t_walo **head_a, t_walo **head_b, int mid)
{
	int	i;
	int	j;
	int	size;

	size = ft_lenght(*head_a, 1, NULL);
	i = 0;
	j = 0;
	while (i < size - lis->max)
	{
		if (j != lis->max && (*head_a)->data == lis->arr[j])
		{
			ft_rotate(head_a, 0);
			j++;
		}
		else
		{
			ft_push_2b(head_a, head_b);
			if (mid >= (*head_b)->data)
				ft_rotate(head_b, 1);
			i++;
		}
	}
}

void	ft_check(t_walo **head_a, t_walo **head_b)
{
	t_lis	*lis;
	int		mid;

	mid = median(*head_a);
	lis = ft_array(*head_a);
	ft_condition(lis, head_a, head_b, mid);
	free(lis->arr);
	free(lis);
}

void	ft_calculate(t_walo **head_a, t_walo **head_b)
{
	t_walo	*current2;
	int		arr[3];
	int		temp[3];
	int		i;
	int		total;

	current2 = *head_b;
	i = 0;
	total = -1;
	arr[0] = ft_find_target_a((*head_a), current2);
	arr[1] = ft_min_rb(i, ft_lenght(*head_b, 1, NULL) - i);
	while (current2 != NULL)
	{
		arr[0] = ft_find_target_a((*head_a), current2);
		ft_before_cal(arr, i, (ft_lenght(*head_b, 1, NULL)));
		if (total == -1 || ft_calculate_total(arr) <= total)
			total = ft_after_cal(arr, temp);
		current2 = current2->next;
		i++;
	}
	ft_action(head_a, head_b, temp);
}

void	ft_last_rotate(t_walo **head_a)
{
	t_walo	*current;
	int		i;
	int		len;
	int		ra;
	t_walo	*temp;

	i = 0;
	temp = *head_a;
	len = ft_lenght(*head_a, 1, NULL);
	current = ft_find_min(*head_a);
	while (temp != NULL && current->data != temp->data)
	{
		i++;
		temp = temp->next;
	}
	ra = ft_min_rb(i, len - i);
	ft_do_it(head_a, ra, 0);
}

void	ft_last_loop(t_walo **head_a, t_walo **head_b)
{
	ft_check(head_a, head_b);
	while (*head_b != NULL)
	{
		ft_calculate(head_a, head_b);
		ft_push_2a(head_a, head_b);
	}
	ft_last_rotate(head_a);
}
