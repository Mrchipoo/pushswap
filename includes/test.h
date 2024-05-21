/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoubby <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 20:03:15 by echoubby                #+#    #+#             */
/*   Updated: 2024/05/21 11:10:52 by echoubby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
#include <stdlib.h>
#include <stdio.h>
#define TEST_H
typedef struct  walo
{
    int data;
    struct walo *next;
}walo;

void	ft_push_2a(walo **head_a,walo **head_b);
void	ft_push_2b(walo **head_a,walo **head_b);
void	ft_rotate_a(walo **head_a);
void	ft_rotate_b(walo **head_b);
void	ft_rr(walo **head_a, walo **head_b);
void	ft_swap_a(walo **head_a);
void	ft_swap_b(walo **head_b);
void	ft_swap_both(walo **head_a, walo **head_b);
void    ft_rra(walo **head_a);
void    ft_rrb(walo **head_b);
void    ft_rrr(walo **head_a, walo **head_b);
walo    *ft_last_node(walo *head);
walo    *ft_last_before(walo *head);
#endif
