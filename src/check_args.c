/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 03:18:30 by mmoumani          #+#    #+#             */
/*   Updated: 2022/12/28 14:22:46 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	int	all_isdigit(char *str)
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

static	int	exist(t_list *lst, long nb)
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

static	t_list	*check_args(char **s1, t_list **head)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (!all_isdigit(s1[i]))
			return (write(2, "Error\n", 6), free(s1[i]), (*head));
		else if (!exist((*head), ft_atoi(s1[i])))
			ft_lstadd_back(head, ft_lstnew(ft_atoi(s1[i])));
		else
			return (write(2, "Error\n", 6), free(s1[i]), (*head));
		free(s1[i]);
		i++;
	}
	return (*head);
}

t_list	*check_all(int argc, char **argv, int i)
{
	t_list		*head;
	char		**s1;

	head = NULL;
	while (i < argc)
	{
		s1 = ft_split(argv[i], ' ');
		if (!s1)
			return (write(2, "Error\n", 6), head);
		else if (!s1[0])
			return (write(2, "Error\n", 6), free(s1[0]), head);
		check_args(s1, &head);
		free(s1);
		i++;
	}
	return (head);
}
