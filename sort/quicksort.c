/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mba <mba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:27:00 by echoubby          #+#    #+#             */
/*   Updated: 2024/06/01 20:16:42 by mba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test.h"

void    ft_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
int ft_partition(int arr[], int low, int high)
{
    int i;
    int j;
    int pivot;

    i = low;
    pivot = arr[low];
    j = high;
    while (i < j)
    {
        while (i <= high && arr[i] <= pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i < j)
            ft_swap(&arr[i], &arr[j]);
    }
    ft_swap(&arr[low], &arr[j]);
    return (j);
}
void ft_quicksort(int arr[], int low, int high)
{
    int pivot;

    if (low < high)
    {
        pivot = ft_partition(arr, low, high);
        ft_quicksort(arr, low, pivot - 1);
        ft_quicksort(arr, pivot + 1 , high);
    }
}

