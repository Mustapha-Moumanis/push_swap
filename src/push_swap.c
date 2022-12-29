/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 23:51:35 by mmoumani          #+#    #+#             */
/*   Updated: 2022/12/29 19:00:35 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


// void	print_array(int *arr, int len)
// {
// 	int	i;

// 	i = 0;
// 	while (i < len)
// 	{
// 		// printf("arr[%d] = %d\n", i, arr[i]);
// 		i++;
// 	}
// }

int	in_range(int content, int *arr, int start, int end)
{
	int i;

	i = 0;
	while (i <= end - start)
	{
		if (content == arr[start + i])
			return (i);
		i++;
	}
	return(-1);
}

void	sort_range(t_list **stack_a, t_list **stack_b, int *arr, int len)
{
	int		i;
	int		mid;
	int		offset;
	int		start;
	int		end;

	i = 0;
	mid = len/2 - 1;
 
	if (len <= 8)
		offset = 1;
	else if (len <= 100)
		offset = len / 8;
	else
		offset = len / 18;
	start = mid - offset;
	end = mid + offset;
	while (*stack_a)
	{
		i = in_range((*stack_a)->content, arr, start, end);
		if (i >= 0)
		{
			pb(stack_a,stack_b);
			if ((*stack_b)->content < mid)
				rb(stack_b);
			if (*stack_b && ((*stack_b)->next) && 
			((*stack_b)->content < (*stack_b)->next->content))
				sb(*stack_b);
			len--;
		}
		else if (i <= len / 2)
		{
			ra(stack_a);
		}
		else
			rra(stack_a);
		if (ft_lstsize(*stack_b) == end - start + 1)
		{
			start -= offset;
			if (start < 0)
				start = 0;
			end += offset;
			if (end > len)
				start = 0;
		}
	}


	
	// while (*stack_b)
	// {
	// 	if ((*stack_b)->content == arr[len - i])
	// 	{
	// 		pa(stack_a, stack_b);
	// 		i++;
	// 	}
	// 	else if ((*stack_b)->next->content == arr[len - i])
	// 	{
	// 		sb(*stack_b);
	// 		pa(stack_a, stack_a);
	// 		i++;
	// 	}
	// 	else
	// 	{
	// 		pa(stack_a, stack_b);
	// 		ra(stack_b);
	// 		pa(stack_a, stack_b);
	// 		rra(stack_a);
	// 		i += 2;
	// 	}
	// 	// printf("last elemnt in arr = %d\n", arr[len - i]);
	// }
	
	// if (!is_sorted(*stack_a) )
	// 	sort_range(stack_a, stack_b, arr, len);
	
	
	// else if (ft_lstsize(*stack_a) == 3)
	// {
	// 	tree_sorted(stack_a);
	// 	while (stack_b)
	// 		pa(stack_a, stack_b);
	// }
}

void	larg_sort(t_list **stack_a, t_list **stack_b, int len)
{
	int		*arr;

	arr = to_arr((*stack_a), ft_lstsize((*stack_a)));
	sort_range(stack_a, stack_b, arr, len);
	// print_array(arr, len);
	free(arr);
}



int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;


	a = check_all(argc, argv, 1);
	b = NULL;
	// arr = to_arr(a, ft_lstsize(a));
	larg_sort(&a, &b, ft_lstsize(a));
	

	// b = check_all(argc, argv, 1);
	// less_five_sort(&a, &b);

	
	// if (a)
	// {
	// 	while (a)
	// 	{
	// 		printf("a => $%d$\n", a->content);
	// 		a = a->next;
	// 	}
	// }
	// if (b)
	// {
	// 	while (b)
	// 	{
	// 		printf("b => $%d$\n", b->content);
	// 		b = b->next;
	// 	}
	// }
	// free(arr);
	// while (1);
	return (0);
}
/// 4 0 1 5 6 2 3 9 8 7 /// 0 1 2 3 4 5 6 7 8 9
/// 3 ----- 7 >>>> (i >= 0) >>>>>> index < size / 2 ra else rra (i == -1) >>> upgrade start && end