/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_two_first.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 01:13:05 by mmoumani          #+#    #+#             */
/*   Updated: 2022/12/24 06:43:56 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	void	swap_two_first(t_list *lst)
{
	int	tmp;

	tmp = lst->content;
	lst->content = lst->next->content;
	lst->next->content = tmp;
}

void	sa(t_list *stack_a)
{
	if (stack_a && ft_lstsize(stack_a) > 1)
	{
		swap_two_first(stack_a);
		write(1, "sa\n", 3);
	}
}

void	sb(t_list *stack_b)
{
	if (stack_b && ft_lstsize(stack_b) > 1)
	{
		swap_two_first(stack_b);
		write(1, "sb\n", 3);
	}
}

void	ss(t_list *a, t_list *b)
{
	if ((a && ft_lstsize(a) > 1) && (b && ft_lstsize(b) > 1))
	{
		swap_two_first(a);
		swap_two_first(b);
		write(1, "ss\n", 3);
	}
}
