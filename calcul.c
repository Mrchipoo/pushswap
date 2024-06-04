
#include "includes/test.h"

int ft_min_ra(int i, int j, int target, int current)
{
	if (i > j)//rra
	{
		if (current > target)
			return (-(j - 1));
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

int	ft_calculate_total(int arr[1][3])
{		
	return (ft_custom_abs(arr[0][0]) + ft_custom_abs(arr[0][1]) + ft_custom_abs(arr[0][2]));
}

int median (walo *head)
{
	int *arr;
	int count;
	
	count = ft_lenght(head, 1, NULL);
	arr = ft_empty_array(head);
	if (arr == NULL)
		return (-1);
	ft_quicksort(arr, 0, count - 1);
	return (arr[count / 2]);
}
