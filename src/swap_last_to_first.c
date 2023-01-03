/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_last_to_first.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 00:26:37 by mmoumani          #+#    #+#             */
/*   Updated: 2023/01/03 23:57:36 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap_last_to_first(t_list **stack)
{
	t_list	*tmp;

	tmp = (*stack);
	while (tmp->next && tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = (*stack);
	(*stack) = tmp->next;
	tmp->next = NULL;
}

void	rra(t_list **stack_a, int print)
{
	if ((*stack_a) && (*stack_a)->next)
	{
		swap_last_to_first(stack_a);
		if (print == 1)
			write(1, "rra\n", 4);
	}
}

void	rrb(t_list **stack_b, int print)
{
	if ((*stack_b) && (*stack_b)->next)
	{
		swap_last_to_first(stack_b);
		if (print == 1)
			write(1, "rrb\n", 4);
	}
}

void	rrr(t_list **stack_a, t_list **stack_b, int print)
{
	if (((*stack_a) && (*stack_a)->next) && ((*stack_b) && (*stack_b)->next))
	{
		swap_last_to_first(stack_a);
		swap_last_to_first(stack_b);
		if (print == 1)
			write(1, "rrr\n", 4);
	}
}
