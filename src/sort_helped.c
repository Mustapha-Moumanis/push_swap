/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helped.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 06:33:10 by mmoumani          #+#    #+#             */
/*   Updated: 2023/01/03 23:46:46 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	maximum(t_list	*stack)
{
	int	max;

	max = stack->content;
	while (stack)
	{
		if (stack->content > max)
			max = stack->content;
		stack = stack->next;
	}
	return (max);
}

int	minimum(t_list	*stack)
{
	int	min;

	min = stack->content;
	while (stack)
	{
		if (stack->content < min)
			min = stack->content;
		stack = stack->next;
	}
	return (min);
}

int	is_sorted(t_list *stack)
{
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	max_index_place(t_list	*stack, int max)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->content == max)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}

int	in_range(int content, int *arr, int start, int end)
{
	int	i;

	i = 0;
	while (i <= end - start)
	{
		if (content == arr[start + i])
			return (i);
		i++;
	}
	return (-1);
}
