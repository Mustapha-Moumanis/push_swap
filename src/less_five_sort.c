/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_five_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 06:29:59 by mmoumani          #+#    #+#             */
/*   Updated: 2023/01/04 00:01:58 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	two_sorted(t_list	**stack)
{
	int	min;

	min = minimum(*stack);
	if (min != (*stack)->content)
		sa(*stack, 1);
}

void	tree_sorted(t_list	**stack)
{
	int	min;
	int	max;

	min = minimum(*stack);
	max = maximum(*stack);
	while (min != (*stack)->content || max != (*stack)->next->next->content)
	{
		if (min == (*stack)->next->next->content)
			rra(stack, 1);
		else if (max == (*stack)->content)
			ra(stack, 1);
		else
			sa(*stack, 1);
	}
}

void	five_sorted(t_list	**a, t_list **b, int len, int min)
{
	while (!is_sorted(*a))
	{
		if (len == 3)
		{
			tree_sorted(a);
			while (*b)
				pa(a, b, 1);
		}
		else if ((*a)->content == min)
		{
			pb(a, b, 1);
			min = minimum(*a);
			len--;
		}
		else if (ft_lstlast((*a))->content == min)
			rra(a, 1);
		else
			ra(a, 1);
	}
	if (len == 4)
		pa(a, b, 1);
}

void	less_five_sort(t_list **stack_a, t_list **stack_b)
{
	int		min;
	int		len;

	min = minimum(*stack_a);
	len = ft_lstsize(*stack_a);
	if (len == 2)
		two_sorted(stack_a);
	else if (len == 3)
		tree_sorted(stack_a);
	else if (len <= 5)
		five_sorted(stack_a, stack_b, len, min);
}
