/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoubby <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:27:00 by echoubby          #+#    #+#             */
/*   Updated: 2024/06/03 16:20:11 by mba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test.h"

void    ft_change(int *a, int *b)
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
            ft_change(&arr[i], &arr[j]);
    }
    ft_change(&arr[low], &arr[j]);
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

