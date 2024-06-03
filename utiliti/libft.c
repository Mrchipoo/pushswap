
#include "../includes/test.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(char *nptr)
{
	int	sign;
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

int	ft_lenght(walo *head, int mode, char	*str)
{
	int i;
	walo	*current;

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

