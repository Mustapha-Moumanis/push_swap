/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_last_to_first.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 00:26:37 by mmoumani          #+#    #+#             */
/*   Updated: 2022/12/25 04:26:08 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void swap_last_to_first(t_list **stack)
{
	t_list	*tmp;

	tmp = (*stack);
	while (tmp->next && tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = (*stack);
	(*stack) = tmp->next;
	tmp->next = NULL;
}

void	rra(t_list **stack_a)
{
	if ((*stack_a) && (*stack_a)->next)
	{
		swap_last_to_first(stack_a);
		write(1, "rra\n", 4);
	}
}

void	rrb(t_list **stack_b)
{
	if ((*stack_b) && (*stack_b)->next)
	{
		swap_last_to_first(stack_b);
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	if (((*stack_a) && (*stack_a)->next) && ((*stack_b) && (*stack_b)->next))
	{
		swap_last_to_first(stack_a);
		swap_last_to_first(stack_b);
		write(1, "rrr\n", 4);
	}
}
