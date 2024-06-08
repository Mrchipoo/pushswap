/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mba <mba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 20:03:15 by echoubby          #+#    #+#             */
/*   Updated: 2024/06/08 00:40:45 by echoubby         ###   ########.fr       */
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
	int	max;
	int	index;
}	t_lis;

void	ft_push_2a(t_walo **head_a, t_walo **head_b);
void	ft_negative(int *arr);
void	ft_positive(int *arr);
void	ft_action(t_walo **head_a, t_walo **head_b, int arr[3]);
void	ft_do_it(t_walo **head, int rotate, int mode);
void	ft_push_2b(t_walo **head_a, t_walo **head_b);
void	ft_rotate(t_walo **head, int mode);
void	ft_rr(t_walo **head_a, t_walo **head_b);
void	ft_swap(t_walo **head_a, int mode);
void	ft_swap_both(t_walo **head_a, t_walo **head_b);
void	ft_reverse(t_walo **head, int mode);
void	ft_rrr(t_walo **head_a, t_walo **head_b);
void	ft_small_sort(t_walo **head);
void	ft_quicksort(int arr[], int low, int high);
void	ft_check(t_walo **head_a, t_walo **head_b);
void	ft_last_loop(t_walo **head_a, t_walo **head_b);
void	ft_free_stack(t_walo **head_a, t_walo **head_b, int mode);
void	ft_free(t_walo **head);
void	ft_check_duplicate(t_walo	*head);
void	ft_before_cal(int *arr, int n, int len);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char	*s1, char	*s2);
char	*ft_strdup(char	*s);
int		ft_atoi(char	*nptr);
int		ft_lenght(t_walo *head, int mode, char	*str);
int		ft_after_cal(int *arr, int *temp);
int		*ft_empty_array(t_walo *head);
int		ft_sorted(t_walo	*head);
int		ft_min_ra(int i, int j, int target, int current);
int		ft_min_rb(int i, int j);
long	ft_abs(long x);
t_walo	*ft_search(int argc, char **argv);
int		ft_calculate_total(int arr[3]);
int		median(t_walo *head);
int		ft_find_target_a(t_walo *head, t_walo *node);
t_walo	*ft_fill(char	**str);
t_walo	*ft_last_node(t_walo *head);
t_walo	*ft_last_before(t_walo *head);
t_walo	*ft_find_biggest(t_walo *head);
t_walo	*ft_find_min(t_walo *head);
t_walo	*ft_diff(t_walo	*head, t_walo	*node);
t_lis	*ft_array(t_walo *head);
t_lis	*ft_main_lis(int arr[], int n);
t_lis	*ft_fill_lis5(t_lis **liss, int *squence);
#endif
