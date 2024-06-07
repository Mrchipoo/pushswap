/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoubby <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 20:03:15 by echoubby          #+#    #+#             */
/*   Updated: 2024/06/06 17:53:09 by echoubby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# define TEST_H

typedef struct walo
{
	int			data;
	struct walo	*next;
}	t_walo;

typedef struct t_lis
{
	int	*arr;
	int	len;
}	t_lis;

void	print_list(walo *head, int mode);
void	ft_push_2a(walo **head_a, walo **head_b);
void	ft_action(walo **head_a, walo **head_b, int arr[3]);
void	ft_do_it(walo **head, int rotate, int mode);
void	ft_push_2b(walo **head_a, walo **head_b);
void	ft_rotate(walo **head, int mode);
void	ft_rr(walo **head_a, walo **head_b);
void	ft_swap(walo **head_a, int mode);
void	ft_swap_both(walo **head_a, walo **head_b);
void	ft_reverse(walo **head, int mode);
void	ft_rrr(walo **head_a, walo **head_b);
void	ft_small_sort(walo **head);
void	ft_quicksort(int arr[], int low, int high);
void	ft_check(walo **head_a, walo **head_b);
void	ft_last_loop(walo **head_a, walo **head_b);
void	ft_free_stack(walo **head_a, walo **head_b, int mode);
void	ft_free(walo **head);
void	ft_check_duplicate(walo	*head);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char	*s1, char	*s2);
char	*ft_strdup(char	*s);
int		ft_atoi(char	*nptr);
int		ft_lenght(walo *head, int mode, char	*str);
int		*ft_empty_array(walo *head);
int		ft_sorted(walo	*head);
int		ft_min_ra(int i, int j, int target, int current);
int		ft_min_rb(int i, int j);
long	ft_abs(long x);
walo	*ft_search(int argc, char **argv);
int		ft_calculate_total(int arr[]);
int		median(walo *head);
int		ft_find_target_a(walo *head, walo *node);
walo	*ft_fill(char	**str);
walo	*ft_last_node(walo *head);
walo	*ft_last_before(walo *head);
walo	*ft_find_biggest(walo *head);
walo	*ft_find_min(walo *head);
walo	*ft_diff(walo	*head, walo	*node);
t_lis	*ft_array(walo *head);
t_lis	*ft_main_LIS(int arr[], int n);
#endif
