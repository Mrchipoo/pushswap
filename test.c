/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echoubby <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 20:27:50 by echoubby          #+#    #+#             */
/*   Updated: 2024/06/06 17:34:07 by echoubby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/test.h"

void	ft_check_duplicate(walo	*head)
{
	walo	*tmp;
	walo	*tmp2;
	int	i;
	
	tmp = head;
	while(tmp != NULL)
	{
		i = 0;
		tmp2 = head;
		while(tmp2 != NULL)
		{
			if (tmp->data == tmp2->data)
				i++;
			if (i >= 2)
				ft_free_stack(&head, NULL, 0);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

walo	*ft_anti_error(int argc, char **argv)
{
	walo	*current;

	current = NULL;
	if (1 == argc || (2 == argc && !argv[1][0]))
		ft_free_stack(NULL, NULL, 0);
	current = ft_search(argc,argv);
	return (current);
}
walo	*ft_search(int	argc, char	**argv)
{
	char	*s1;
	int		i;
	char	**str;
	walo	*current;
	char	*temp;
	
	i = 1;
	s1 = ft_strdup("");
	if (!s1)
		return(NULL);
	while (i < argc)
	{
		temp = ft_strjoin(s1,argv[i]);
		if (!temp)
			return (NULL);
		free(s1);
		s1 = temp;
		i++;
	}
	str = ft_split(s1, 32);
	free(s1);
	if (!str)
		return (NULL);
	current = ft_fill(str);
	return (current);
}
	
int	main(int	argc, char	**argv)
{
	walo	*head_a;
	walo	*head_b;

	head_b = NULL;
	head_a = NULL;
	if (argc < 2)
		return (0);
	head_a = ft_anti_error(argc, argv);
	if (head_a == NULL)
		ft_free_stack(&head_a, NULL, 1);
	if (ft_sorted(head_a))
		ft_free_stack(&head_a, &head_b, 1);
	if (ft_lenght(head_a, 1, NULL) == 2)
		ft_swap(&head_a, 0);
	if (ft_lenght(head_a, 1, NULL) == 3)
		ft_small_sort(&head_a);
	else
		ft_last_loop(&head_a, &head_b);
	ft_free_stack(&head_a, &head_b, 1);
	return (0);
}
