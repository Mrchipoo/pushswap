/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mba <mba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 20:03:15 by echoubby          #+#    #+#             */
/*   Updated: 2024/06/01 21:36:01 by mba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# include <stdlib.h>
# include <stdio.h>
# define TEST_H

typedef struct  walo
{
    int data;
    struct walo *next;
}walo;

typedef struct t_lis
{
    int *arr;
    int len;
}   t_lis;

void	ft_push_2a(walo **head_a,walo **head_b);
void	ft_push_2b(walo **head_a,walo **head_b);
void	ft_ra(walo **head_a);
void	ft_rb(walo **head_b);
void	ft_rr(walo **head_a, walo **head_b);
void	ft_swap_a(walo **head_a);
void	ft_swap_b(walo **head_b);
void	ft_swap_both(walo **head_a, walo **head_b);
void    ft_rra(walo **head_a);
void    ft_rrb(walo **head_b);
void    ft_rrr(walo **head_a, walo **head_b);
void    ft_small_sort(walo **head);
void    ft_quicksort(int arr[], int low, int high);
void	ft_check(walo **head_a, walo **head_b);
void	ft_last_loop(walo **head_a, walo **head_b);
t_lis   *ft_array(walo *head);
t_lis   *ft_LIS(int arr[], int n);
walo    *ft_last_node(walo *head);
walo    *ft_last_before(walo *head);
walo	*ft_find_biggest(walo *head);
walo    *ft_find_min(walo *head);
#endif
