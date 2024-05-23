/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoubby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:27:00 by echoubby          #+#    #+#             */
/*   Updated: 2024/05/23 14:27:31 by echoubby         ###   ########.fr       */
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
void partition(int arr[], int low, int high)
{
    int i;
    int j;
    int pivot;

    i = low;
    pivot = arr[low];
    j = high;
    while (i < j)
    {
        while (arr[i] <= pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i < j)
            ft_swap(&arr[i], &arr[j]);
    }
    ft_swap(&arr[low],&arr[j]);
}
void ft_quicksort(int arr[], int length)
{
    
}
