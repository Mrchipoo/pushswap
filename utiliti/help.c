/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mba <mba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:14:38 by echoubby          #+#    #+#             */
/*   Updated: 2024/06/01 22:57:00 by mba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test.h"

int	ft_lenght(walo *head, int mode)
{
	int i;
	walo	*current;

	i = 0;
	current = head;
	if (mode == 1)
	{
		while (current != NULL)
		{
			current = current->next;
			i++;
		}
	}
	return (i);
}

int *ft_empty_array(walo *head)
{
	int	*arr;
	int i;
	int count;

	i = 0;
	count = ft_lenght(head,1);
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

walo *ft_find_min(walo *head)
{
	int min;
	walo *node_min;

	min = head->data;
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

int median (walo *head)
{
	int *arr;
	int count;
	
	count = ft_lenght(head,1);
	arr = ft_empty_array(head);
	if (arr == NULL)
		return (-1);
	ft_quicksort(arr, 0, count - 1);
	return (arr[count / 2]);
}


t_lis *ft_array(walo *head)
{
	int	*arr;
	int count;
	t_lis *lis;

	count = ft_lenght(head,1);
	arr = ft_empty_array(head);
	lis = ft_LIS(arr,count);
		// if (squence == NULL)
		// 	return (NULL);
	return (lis);
}

t_lis *ft_LIS(int arr[], int n)
{
	int	i;
	int	j;
	int	*LIS;
	int	index;
	int	*prev;
	int	pos;
	int	*squence;
	int	max;
	t_lis *lis;
	
	max = 0;
	i = 0;
	index = 0;
	lis = NULL;
	LIS = malloc(sizeof(int) * n);
	prev = malloc(sizeof(int) * n);
	if (LIS == NULL || prev == NULL)
		return NULL;
	while (i < n)
	{
		LIS[i] = 1;
		prev[i] = -1;
		i++;
	}
	i = 1;
	while(i < n)
	{
		j = 0;
		while (j < i)
		{
			if (arr[j] < arr[i] && LIS[j] + 1 > LIS[i])
			{
				LIS[i] = LIS[j] + 1;
				prev[i] = j;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < n)
	{
		if (max < LIS[i])
		{
			max = LIS[i];
			index = i;
		}
		i++;
	}
	squence = malloc(sizeof(int) * max);
	if (squence == NULL)
		return NULL;
	pos = max - 1;
	while (index != -1)
	{
		squence[pos] = arr[index];
		pos--;
		index  = prev[index];
	}
	lis = malloc(sizeof(t_lis));
	lis->arr = squence;
	lis->len= max;
	return (lis);
}

void	ft_check(walo **head_a, walo **head_b)
{
	t_lis *lis;
	int	i;
	int size_a;
	int	j;
	int mid;
	
	mid = median(*head_a);
	size_a = ft_lenght(*head_a, 1);
	lis = ft_array(*head_a);
	i = 0;
	j = 0;
	while (i < size_a - lis->len)
	{
		if (j != lis->len && (*head_a)->data == lis->arr[j])
		{
			ft_ra(head_a);
			j++;
		}
		else
		{
			ft_push_2b(head_a, head_b);
			if (mid >= (*head_b)->data)
				ft_rb(head_b);
			i++;
		}
	}
}

int ft_min(int i, int j)
{
	if (i == j)
		return (i);
	else if (i > j)
		return (-j);
	return (i);
}
int ft_custom_abs(int x)
{
	if (x > 0)
		return (x);
	return (-x);
}
int	ft_find_target_a(walo *head, walo *node)
{
	int i;
	int len;
	int ra;
	int	min;
	walo	*temp;
	walo	*temp2;
	
	i = 0;
	min = (node->data - head->data);
	len = ft_lenght(head, 1);
	temp2 = head;
	temp = head;
	while (head != NULL)
	{
		if ((node->data - head->data) < min )
		{
			min = (node->data - head->data);
			temp = head;
		}
		head = head->next;
	}
	while (temp2 != NULL && temp2->data != temp->data)
	{
		i++;
		temp2 = temp2->next;
	}
	ra = ft_min(i, len - i);
	return (ra);
}

int	ft_calculate_total(int arr[1][3])
{
	int max;
		
	max = arr[0][0] + arr[0][1] + arr[0][2];
	if (max >= 0)
		return (max);
	return (-max);
}

void ft_action(walo **head_a, walo **head_b,int arr[1][3])
{
	int ra;
	int	rb;
	int rall;

	ra = arr[0][0];
	rb = arr[0][1];
	rall = arr[0][2];
	while (rb != 0)
	{
		if (rb > 0)
		{
			ft_rb(head_b);
			rb--;
		}
		if (rb < 0)
		{
			ft_rrb(head_b);
			rb++;
		}
	}
	while (ra != 0)
	{
		if (ra > 0)
		{
			ft_ra(head_a);
			ra--;
		}
		if (ra < 0)
		{
			ft_rra(head_a);
			ra++;
		}
	}
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

void	ft_calculate(walo **head_a, walo **head_b)
{
	walo	*current2;
	int	arr[1][3];
	int i;
	int len;
	int total;
	int total_curr;
	int	Temp[1][3];
	
	current2 = *head_b;
	i = 0;
	total = -1;
	len = ft_lenght(current2, 1);
	while (current2 != NULL)
	{
		arr[0][0] = ft_find_target_a((*head_a),current2);//ra/rra
		arr[0][1] = ft_min(i, len - i);//rb/rrb
		if (arr[0][0] >= 0 && arr[0][1] >= 0)
		{
			if (arr[0][0] >= arr[0][1])
			{
				arr[0][2] = arr[0][1];
				arr[0][0] = arr[0][0] - arr[0][1];
				arr[0][1] = 0;
			}
			else if (arr[0][0] <=  arr[0][1])
			{
				arr[0][2] = arr[0][0];
				arr[0][0] = arr[0][1] - arr[0][0];
				arr[0][0] = 0;
			}
		}
		if (arr[0][0] < 0 && arr[0][1] < 0)
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
		printf("test %d\n",arr[0][0]);
		total_curr = ft_calculate_total(arr);
		if (total == -1 || ft_calculate_total(Temp) - total_curr > 0)//Temp is cheapest 
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
void	ft_last_loop(walo **head_a, walo **head_b)
{
	walo	*current;

	current = *head_b;
	while (current != NULL)
	{
		ft_calculate(head_a,head_b);
		ft_push_2a(head_a,head_b);
		current = current->next;
	}
}

// /* 
//  -- For each node in b -- 
// 1- from current position b : return moves in b rb or rrb
// 2- Calculate target:
// 	2.a- diff between the node (in b) and each element in a: return the element in a with the smallest diff
// 	2.b- calculate target position in a: if the a element returned is small the target pos: pos_a + 1 else pos: pos_a
// 3- from target position calculate the number of moves in a : ra or rra
// 4- optimize : return the rr and rrr moves
// 5- calcute total cost :total = vabs(ra/rra) +  vabs(rb/rrb) + vabs(rr/rrr)
// */