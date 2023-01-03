/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_to_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 06:43:41 by mmoumani          #+#    #+#             */
/*   Updated: 2023/01/03 23:57:52 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	void	stack_to_stack(t_list **stack_1, t_list **stack_2)
{
	t_list	*tmp;

	tmp = (*stack_1);
	(*stack_1) = (*stack_1)->next;
	tmp->next = (*stack_2);
	(*stack_2) = tmp;
}

void	pa(t_list **stack_a, t_list **stack_b, int print)
{
	if (*stack_b)
	{
		stack_to_stack(stack_b, stack_a);
		if (print == 1)
			write(1, "pa\n", 3);
	}
}

void	pb(t_list **stack_a, t_list **stack_b, int print)
{
	if (*stack_a)
	{
		stack_to_stack(stack_a, stack_b);
		if (print == 1)
			write(1, "pb\n", 3);
	}
}
