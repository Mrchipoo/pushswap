/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mba <mba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 20:03:15 by echoubby          #+#    #+#             */
/*   Updated: 2024/06/03 19:44:02 by mba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
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
void	print_list(walo *head, int mode);
void	ft_push_2b(walo **head_a,walo **head_b);
void	ft_rotate(walo **head, int mode);
void	ft_rr(walo **head_a, walo **head_b);
void	ft_swap(walo **head_a, int mode);
void	ft_swap_both(walo **head_a, walo **head_b);
void    ft_reverse(walo **head, int mode);
void    ft_rrr(walo **head_a, walo **head_b);
void    ft_small_sort(walo **head);
void    ft_quicksort(int arr[], int low, int high);
void	ft_check(walo **head_a, walo **head_b);
void	ft_last_loop(walo **head_a, walo **head_b);
void	ft_free_stack(walo	**head_a, walo	**head_b, int	mode);
char	**ft_split(char const *s, char c);
int     ft_search(int	argc, char	**argv);
int     ft_atoi(char *nptr);
int     ft_lenght(walo *head, int mode, char	*str);
int     *ft_empty_array(walo *head);
int     ft_sorted(walo	*head);
walo	*ft_fill(int	argc, char	**argv);
t_lis   *ft_array(walo *head);
t_lis   *ft_LIS(int arr[], int n);
walo    *ft_last_node(walo *head);
walo    *ft_last_before(walo *head);
walo	*ft_find_biggest(walo *head);
walo    *ft_find_min(walo *head);
#endif
