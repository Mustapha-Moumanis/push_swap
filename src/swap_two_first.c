/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_two_first.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 01:13:05 by mmoumani          #+#    #+#             */
/*   Updated: 2023/01/03 23:54:50 by mmoumani         ###   ########.fr       */
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

void	sa(t_list *stack_a, int print)
{
	if (stack_a && stack_a->next)
	{
		swap_two_first(stack_a);
		if (print == 1)
			write(1, "sa\n", 3);
	}
}

void	sb(t_list *stack_b, int print)
{
	if (stack_b && stack_b->next)
	{
		swap_two_first(stack_b);
		if (print == 1)
			write(1, "sb\n", 3);
	}
}

void	ss(t_list *a, t_list *b, int print)
{
	if ((a && a->next) && (b && a->next))
	{
		swap_two_first(a);
		swap_two_first(b);
		if (print == 1)
			write(1, "ss\n", 3);
	}
}
