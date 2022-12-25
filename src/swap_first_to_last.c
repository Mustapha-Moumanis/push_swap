/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_first_to_last.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 00:02:19 by mmoumani          #+#    #+#             */
/*   Updated: 2022/12/25 04:31:34 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	stacks_reverse(t_list **stack)
{
	t_list	*tmp;
	
	tmp = ft_lstlast(*stack);
	tmp->next = (*stack);
	*stack = (*stack)->next;
	tmp->next->next = NULL;
}

void	ra(t_list **stack_a)
{
	if (*stack_a)
	{
		stacks_reverse(stack_a);
		write(1, "ra\n", 3);
	}
}

void	rb(t_list **stack_b)
{
	if (*stack_b)
	{
		stacks_reverse(stack_b);
		write(1, "rb\n", 3);
	}
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a && *stack_b)
	{
		stacks_reverse(stack_a);
		stacks_reverse(stack_b);
		write(1, "rr\n", 3);
	}
}
