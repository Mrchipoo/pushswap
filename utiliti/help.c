/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mba <mba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:14:38 by echoubby          #+#    #+#             */
/*   Updated: 2024/06/05 13:19:57 by mba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test.h"

void	ft_check(walo **head_a, walo **head_b)
{
	t_lis *lis;
	int	i;
	int size_a;
	int	j;
	int mid;
	
	mid = median(*head_a);
	size_a = ft_lenght(*head_a, 1, NULL);
	lis = ft_array(*head_a);
	i = 0;
	j = 0;
	while (i < size_a - lis->len)
	{
		if (j != lis->len && (*head_a)->data == lis->arr[j])
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

void	ft_calculate(walo **head_a, walo **head_b)
{
	walo	*current2;
	int	arr[1][3];
	int	Temp[1][3];
	int i;
	int len;
	int total;
	int total_curr;
	
	current2 = *head_b;
	i = 0;
	total = -1;
	len = ft_lenght(*head_b, 1, NULL);
	arr[0][0] = ft_find_target_a((*head_a),current2);
	arr[0][1] = ft_min_rb(i, len - i);
	arr[0][2] = 0;
	while (current2 != NULL)
	{
		arr[0][0] = ft_find_target_a((*head_a),current2);
		arr[0][1] = ft_min_rb(i, len - i);
		if (arr[0][0] >= 0 && arr[0][1] >= 0)
		{
			if (arr[0][0] >= arr[0][1])
			{
				arr[0][2] = arr[0][1];
				arr[0][0] = arr[0][0] - arr[0][1];
				arr[0][1] = 0;
			}
			else if (arr[0][0] <  arr[0][1])
			{
				arr[0][2] = arr[0][0];
				arr[0][1] = arr[0][1] - arr[0][0];
				arr[0][0] = 0;
			}
		}
		else if (arr[0][0] < 0 && arr[0][1] < 0)
		{
			if (arr[0][0] >= arr[0][1])
			{
				arr[0][2] = arr[0][0];
				arr[0][1] = arr[0][1] - arr[0][0];
				arr[0][0] = 0;
			}
			else if (arr[0][0] <=  arr[0][1])
			{
				arr[0][2] = arr[0][1];
				arr[0][0] = arr[0][0] - arr[0][1];
				arr[0][1] = 0;
			}
		}
		else//if one of ra or rb have diffrent sign because i dont enter if above so i change value for rrr/rr
			arr[0][2] = 0;
		total_curr = ft_calculate_total(arr);
		if (total == -1 ||  total_curr <= total)//Temp is cheapest 
		{
			Temp[0][0] = arr[0][0]; // ra/rra
			Temp[0][1] = arr[0][1]; // rb/rrb
			Temp[0][2] = arr[0][2]; // rr/rrr
			total = total_curr;
		}
		current2 = current2->next;
		i++;
	}
	ft_action(head_a, head_b,Temp);
}

void ft_last_rotate(walo **head_a)
{
	walo *current;
	int	i;
	int	len;
	int	ra;
	walo *temp;

	i = 0;
	temp = *head_a;
	len = ft_lenght(*head_a, 1, NULL);
	current = ft_find_min(*head_a);
	while (temp != NULL &&  current->data != temp->data)
	{
		i++;
		temp = temp->next;
	}
	ra = ft_min_rb(i, len - i);
	ft_do_it(head_a, ra, 0);
}

void	ft_last_loop(walo **head_a, walo **head_b)
{

	ft_check(head_a,head_b);
	while (*head_b != NULL)
	{
		ft_calculate(head_a,head_b);
		ft_push_2a(head_a,head_b);
	}
	ft_last_rotate(head_a);
}
