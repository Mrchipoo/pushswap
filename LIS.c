
#include "includes/test.h"

void	ft_fill_LIS(int	**LIS, int **prev, int	n)
{
	int	i;

	i = 0;
	*LIS = malloc(sizeof(int) * n);
	*prev = malloc(sizeof(int) * n);
	if (*prev == NULL || *LIS == NULL)
		return ;
	while (i < n)
	{
		(*LIS)[i] = 1;
		(*prev)[i] = -1;
		i++;
	}
}

void ft_fill_LIS2(int arr[], int *LIS, int	*prev, int	n)
{
	int	i;
	int	j;

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
}

void	ft_fill_LIS3(int	**squence, int	pos, int	index, int	arr[], int	prev[])
{
	*squence = malloc(sizeof(int) * (pos + 1));
	if (*squence == NULL)
		return ;
	while (index != -1)
	{
		(*squence)[pos] = arr[index];
		pos--;
		index  = prev[index];
	}
}

t_lis	*ft_fill_LIS4(int	*squence, int	max)
{
	t_lis	*lis;

	lis = NULL;
	lis = malloc(sizeof(t_lis));
	if (lis == NULL)
		return (NULL);
	lis->arr = squence;
	lis->len= max;
	return (lis);
}

t_lis	*ft_main_LIS(int arr[], int n)
{
	int	i;
	int	*LIS;
	int	index;
	int	*prev;
	int	*squence;
	int	max;
	
	max = 0;
	ft_fill_LIS(&LIS, &prev, n);
	if (LIS == NULL || prev == NULL)
		return (NULL);
	ft_fill_LIS2(arr, LIS, prev, n);
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
	ft_fill_LIS3(&squence, max - 1, index, arr, prev);
	if (squence == NULL)
		return (NULL);
	free(LIS);
	free(prev);
	return (ft_fill_LIS4(squence, max));
}
