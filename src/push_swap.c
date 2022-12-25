/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 23:51:35 by mmoumani          #+#    #+#             */
/*   Updated: 2022/12/25 04:56:14 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	all_isdigit(char *str)
{
	int	i;

	i = 0;
	if (str[1] && (str[0] == '+' || str[0] == '-'))
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	exist(t_list *lst, long nb)
{
	if (nb > 2147483647 || nb < -2147483648)
		return (1);
	if (lst)
	{
		while (lst)
		{
			if (nb == lst->content)
				return (1);
			lst = lst->next;
		}
	}
	return (0);
}

t_list	*check_args(int argc, char **argv, int i)
{
	t_list		*head;
	char		**s1;
	int			j;

	head = NULL;
	while (i < argc)
	{
		s1 = ft_split(argv[i], ' ');
		if (!s1)
			return (write(2, "Error\n", 6), head);
		else if (!s1[0])
			return (write(2, "Error\n", 6), free(s1[0]), head);
		j = 0;
		while (s1[j])
		{
			if (!all_isdigit(s1[j]))
				return (write(2, "Error\n", 6), free(s1[j]), head);
			else if (!exist(head, ft_atoi(s1[j])))
				ft_lstadd_back(&head, ft_lstnew(ft_atoi(s1[j])));
			else
				return (write(2, "Error\n", 6), free(s1[j]), head);
			free(s1[j]);
			j++;
		}
		free(s1);
		i++;
	}
	return (head);
}

int	main(int argc, char **argv)
{
	t_list	*a = NULL;
	//t_list	*b = NULL;

	a = check_args(argc, argv, 1);
	//b = check_args(argc, argv, 1);
	rrb(&a);
	// if (a)
	// {
	// 	while (a)
	// 	{
	// 		printf("a => $%d$\n", a->content);
	// 		a = a->next;
	// 	}
	// }
	// if (b)
	// {
	// 	while (b)
	// 	{
	// 		printf("b => $%d$\n", b->content);
	// 		b = b->next;
	// 	}
	// }
	// freeList(a);
	// freeList(b);
	while (1);
	return (0);
}

