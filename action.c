/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mba <mba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:34:14 by echoubby          #+#    #+#             */
/*   Updated: 2024/06/07 16:02:23 by mba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/test.h"

t_walo	*ft_diff(t_walo	*head, t_walo	*node)
{
	long	min;
	long	current;
	t_walo	*target;
	t_walo	*check;

	target = head;
	check = ft_find_min(head);
	if (node->data == -2147483648)
		return (check);
	min = ft_abs((long)head->data - (long)node->data);
	while (head != NULL)
	{
		current = ft_abs((long)head->data - (long)node->data);
		if (current <= min)
		{
			min = current;
			target = head;
		}
		head = head->next;
	}
	return (target);
}

t_lis	*ft_array(t_walo *head)
{
	int		*arr;
	int		count;
	t_lis	*lis;

	count = ft_lenght(head, 1, NULL);
	arr = ft_empty_array(head);
	lis = ft_main_lis(arr, count);
	free(arr);
	if (lis == NULL)
		return (NULL);
	return (lis);
}

int	ft_find_target_a(t_walo *head, t_walo *node)
{
	int		i;
	int		len;
	int		ra;
	t_walo	*target;
	t_walo	*temp2;

	i = 0;
	len = ft_lenght(head, 1, NULL);
	temp2 = head;
	target = ft_diff(head, node);
	while (temp2 != NULL && temp2->data != target->data)
	{
		i++;
		temp2 = temp2->next;
	}
	if (target->next == NULL)
	{
		if (target->data > node->data)
			return (-1);
		return (0);
	}
	ra = ft_min_ra(i, len - i, target->data, node->data);
	return (ra);
}

void	ft_do_it(t_walo **head, int rotate, int mode)
{
	while (rotate != 0)
	{
		if (rotate > 0)
		{
			if (mode == 0)
				ft_rotate(head, mode);
			else if (mode == 1)
				ft_rotate(head, mode);
			rotate--;
		}
		if (rotate < 0)
		{
			if (mode == 0)
				ft_reverse(head, mode);
			else if (mode == 1)
				ft_reverse(head, mode);
			rotate++;
		}
	}
}

void	ft_action(t_walo **head_a, t_walo **head_b, int arr[3])
{
	int	ra;
	int	rb;
	int	rall;

	ra = arr[0];
	rb = arr[1];
	rall = arr[2];
	ft_do_it(head_a, ra, 0);
	ft_do_it(head_b, rb, 1);
	while (rall != 0)
	{
		if (rall > 0)
		{
			ft_rr(head_a, head_b);
			rall--;
		}
		if (rall < 0)
		{
			ft_rrr(head_a, head_b);
			rall++;
		}
	}
}
