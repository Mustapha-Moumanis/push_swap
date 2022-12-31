/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_five_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 06:29:59 by mmoumani          #+#    #+#             */
/*   Updated: 2022/12/27 07:29:03 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	two_sorted(t_list	**stack)
{
	int	min;

	min = minimum(*stack);
	if (min != (*stack)->content)
		sa(*stack);
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
			rra(stack);
		else if (max == (*stack)->content)
			ra(stack);
		else
			sa(*stack);
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
				pa(a, b);
		}
		else if ((*a)->content == min)
		{
			pb(a, b);
			min = minimum(*a);
			len--;
		}
		else if (ft_lstlast((*a))->content == min)
			rra(a);
		else
			ra(a);
	}
	if (len == 4)
		pa(a, b);
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
