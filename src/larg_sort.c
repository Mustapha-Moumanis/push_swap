/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   larg_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 23:24:24 by mmoumani          #+#    #+#             */
/*   Updated: 2023/01/04 00:00:56 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	int	change_offset(t_list **lst)
{
	int	len;

	len = ft_lstsize(*lst);
	if (len <= 8)
		return (2);
	else if (len <= 50)
		return (6);
	else if (len <= 100)
		return (12);
	else if (len <= 200)
		return (20);
	else if (len <= 300)
		return (25);
	return (30);
}

void	sort_to_stack_b(t_list **a, t_list **b, int *arr, t_data *data)
{
	if (in_range((*a)->content, arr, data->start, data->end) >= 0)
	{
		pb(a, b, 1);
		if ((*b)->content < arr[data->mid])
			rb(b, 1);
		if (ft_lstlast(*b)->content > arr[data->mid])
			rrb(b, 1);
		if (ft_lstsize(*a) <= 300)
			data->offset = change_offset(a);
	}
	else
		ra(a, 1);
	if (ft_lstsize(*b) == data->end - data->start + 1)
	{
		data->start -= data->offset;
		data->end += data->offset;
	}
}

void	optimize(t_list **a, t_list **b, t_data *data)
{
	if ((ft_lstlast(*b))->content == data->max)
	{
		rrb(b, 1);
		pa(a, b, 1);
		data->len--;
	}
	else if (data->down == 0 || (*a && (*b)->content > ft_lstlast(*a)->content))
	{
		pa(a, b, 1);
		ra(a, 1);
		data->down++;
	}
	else
	{
		if (max_index_place(*b, data->max) >= data->len / 2)
			rrb(b, 1);
		else
			rb(b, 1);
	}
}

void	sort_to_stack_a(t_list **a, t_list **b, int *arr, t_data *data)
{
	data->max = arr[data->len - 1];
	if (exist(*b, data->max))
	{
		if ((*b)->content == data->max)
		{
			pa(a, b, 1);
			data->len--;
		}
		else if ((*b)->next->content == data->max)
		{
			sb(*b, 1);
			pa(a, b, 1);
			data->len--;
		}
		else
			optimize(a, b, data);
	}
	else
	{
		rra(a, 1);
		data->down--;
		data->len--;
	}
}

void	larg_sort(t_list **stack_a, t_list **stack_b, int len)
{
	int		*arr;
	t_data	data;

	arr = to_arr((*stack_a), ft_lstsize((*stack_a)));
	data.mid = len / 2;
	data.offset = 30;
	data.start = data.mid - data.offset;
	data.end = data.mid + data.offset;
	data.len = ft_lstsize(*stack_a);
	data.max = 0;
	data.down = 0;
	while (*stack_a)
		sort_to_stack_b(stack_a, stack_b, arr, &data);
	data.len = ft_lstsize(*stack_b);
	data.mid = 0;
	while (*stack_b || data.len > 0)
		sort_to_stack_a(stack_a, stack_b, arr, &data);
	free(arr);
}
