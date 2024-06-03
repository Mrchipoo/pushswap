/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mba <mba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:14:38 by echoubby          #+#    #+#             */
/*   Updated: 2024/06/03 10:54:07 by mba              ###   ########.fr       */
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

int ft_min_ra(int i, int j, int target, int current)
{
	if (i == j)
		return (i);
	if (i > j)//rra
	{
		if (current > target)
			return (-(j + 1));
		return (-j);
	}
	else
	{
		if (current > target)//ra
			return ((i + 1));
		return (i);
	}
}
int ft_min_rb(int i, int j)
{
	if (i == j)
		return (i);
	else if (i > j)
		return (-j);
	return (i);
}
int ft_custom_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}
int	ft_find_target_a(walo *head, walo *node)
{
	int i;
	int len;
	int ra;
	int	min_diff;
	int	current_diff;
	walo	*temp;
	walo	*temp2;
	
	i = 0;
	min_diff = ft_custom_abs(head->data - node->data);
	len = ft_lenght(head, 1);
	temp2 = head;
	temp = head;
	while (head != NULL)
	{
		current_diff = ft_custom_abs(head->data - node->data);
		if (current_diff < min_diff )
		{
			min_diff = current_diff;
			temp = head;
		}
		head = head->next;
	}
	// printf ("b node  = %d\n",node->data);
	// printf ("target node  = %d\n",temp->data);
	// printf ("min = %d\n",min_diff);
	while (temp2 != NULL && temp2->data != temp->data)
	{
		i++;
		temp2 = temp2->next;
	}
	if (temp->next == NULL)
	{
		if (temp->data > node->data)
			return (-1);
		return (0);
	}
	// printf ("position of target node = %d\n",i);
	// printf("len - i = %d\n ",len - 1);
	ra = ft_min_ra(i, len - i, temp->data, node->data);
	// printf ("close diff = %d\n",temp->data);
	// printf ("ra = %d\n",ra);
	return (ra);
}

int	ft_calculate_total(int arr[1][3])
{		
	return (ft_custom_abs(arr[0][0]) + ft_custom_abs(arr[0][1]) + ft_custom_abs(arr[0][2]));
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
	total_curr = -1;
	len = ft_lenght(current2, 1);
	arr[0][0] = ft_find_target_a((*head_a),current2);//ra/rra
	arr[0][1] = ft_min_rb(i, len - i);
	arr[0][2] = 0;
	while (current2 != NULL)
	{
		printf("head_b + 1\n");
		arr[0][0] = ft_find_target_a((*head_a),current2);//ra/rra
		arr[0][1] = ft_min_rb(i, len - i);//rb/rrb
		printf ("rb = %d\n",arr[0][1]);
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
		total_curr = ft_calculate_total(arr);
		// printf ("rb after opt = %d\n",arr[0][1]);
		// printf ("total = %d\n",total_curr);
		if (total == -1 ||  total_curr <= total)//Temp is cheapest 
		{
			Temp[0][0] = arr[0][0]; // ra/rra
			Temp[0][1] = arr[0][1]; // rb/rrb
			Temp[0][2] = arr[0][2]; // rr/rrr
			printf("action = %d\n",Temp[0][0]);
			printf("action = %d\n",Temp[0][1]);
			printf("action = %d\n",Temp[0][2]);
			total = total_curr;
		}
		current2 = current2->next;
		i++;
	}
	// printf("action after he find = %d\n",Temp[0][0]);
	// printf("action  after he find  = %d\n",Temp[0][1]);
	// printf("action   after he find  = %d\n",Temp[0][2]);
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
	len = ft_lenght(*head_a,1);
	current = ft_find_min(*head_a);
	while (temp != NULL &&  current->data != temp->data)
	{
		i++;
		temp = temp->next;
	}
	ra = ft_min_rb(i, len - i);
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
}
void	ft_last_loop(walo **head_a, walo **head_b)
{

	//ft_calculate(head_a,head_b);
	while (*head_b != NULL)
	{
		ft_calculate(head_a,head_b);
		ft_push_2a(head_a,head_b);
		print_list(*head_b,1);
		print_list(*head_a, 0);
	}
	ft_last_rotate(head_a);
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