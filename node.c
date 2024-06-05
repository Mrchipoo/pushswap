
#include "includes/test.h"

walo	*ft_last_node(walo *head)
{
	walo	*new_node;

	new_node = head;
	while (new_node->next != NULL)
		new_node = new_node->next;
	return (new_node);
}

walo	*ft_create_node(int data)
{
	walo	*new_node;

	new_node = malloc(sizeof(walo));
	if (!new_node)
		return (0);
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

walo	*ft_last_before(walo *head)
{
	walo *new_node;

	new_node = head;
	while ((new_node->next)->next != NULL)
		new_node = new_node->next;
	return (new_node);
}

int	ft_sorted(walo	*head)
{
	walo	*tmp;
	
	tmp = head;
	while (tmp->next != NULL)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
walo	*ft_fill(int	argc, char	**argv)
{
	int	i;
	walo	*new_node;
	walo	*current;
	walo	*first;
	
	i = 1;
	current = NULL;
	while (i < argc)
	{
		new_node = ft_create_node(ft_atoi(argv[i]));
		if (current == NULL)
		{
			current = new_node;
			first = current;
		}
		else
			ft_last_node(current)->next = new_node;
		i++;
	}
	if (!first)
		ft_check_duplicate(first);
	return (first);
}
