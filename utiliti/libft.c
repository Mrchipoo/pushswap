/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mba <mba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:38:57 by echoubby          #+#    #+#             */
/*   Updated: 2024/06/07 16:01:34 by mba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/test.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(char *nptr)
{
	int		sign;
	long	res;

	sign = 1;
	res = 0;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr && ft_isdigit(*nptr))
	{
		res = res * 10 +(*nptr - 48);
		if ((res * sign) > 2147483647 || (res * sign) < -2147483648)
			ft_free_stack(NULL, NULL, 0);
		nptr++;
	}
	if (*nptr != '\0' && !ft_isdigit(*nptr))
		ft_free_stack(NULL, NULL, 0);
	return (res * sign);
}

int	ft_lenght(t_walo *head, int mode, char	*str)
{
	int		i;
	t_walo	*current;

	i = 0;
	current = head;
	if (mode == 1)
	{
		while (current != NULL)
		{
			current = current->next;
			i++;
		}
	}
	else if (mode == 2)
	{
		while (str[i])
			i++;
	}
	return (i);
}

char	*ft_strjoin(char	*s1, char	*s2)
{
	int		i;
	int		tol;
	int		j;
	char	*b;

	i = 0;
	j = 0;
	if (!s2)
		return (NULL);
	tol = ft_lenght(NULL, 2, s1) + ft_lenght(NULL, 2, s2) + 1;
	b = malloc((tol + 1) * sizeof(char));
	if (b == NULL)
		return (0);
	while (s1[i] && i < tol)
	{
		b[i] = s1[i];
		i++;
	}
	b[i++] = ' ';
	while (s2[j] && i < tol)
		b[i++] = s2[j++];
	b[i] = '\0';
	return (b);
}

char	*ft_strdup(char	*s)
{
	char	*pt;
	int		i;

	i = 0;
	pt = malloc(sizeof(char) * (ft_lenght(NULL, 2, s) + 1));
	if (pt == NULL)
		return (NULL);
	while (s[i])
	{
		pt[i] = s[i];
		i++;
	}
	pt[i] = '\0';
	return (pt);
}
