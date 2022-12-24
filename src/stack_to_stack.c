/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_to_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 06:43:41 by mmoumani          #+#    #+#             */
/*   Updated: 2022/12/24 07:22:09 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// void	pb(t_list *stack_a, t_list *stack_b)
// {
// 	t_list	*tmp;

// 	ft_lstadd_front(stack_b, ft_lstnew(stack_a->content));
// 	tmp = stack_a->next;
// 	free(stack_a);
// 	stack_a = tmp;
// }


void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	ft_lstadd_front(stack_b, ft_lstnew((*stack_a)->content));
	tmp = (*stack_a)->next;
	free((*stack_a));
	(*stack_a) = tmp;
}
