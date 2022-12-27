/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 23:51:35 by mmoumani          #+#    #+#             */
/*   Updated: 2022/12/27 07:26:52 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// void	less_100_sorted(t_list	**stack, int len, int min, int max)
// {
// 	t_list	*tmp;
// 	int	i;

// 	i = 1;
// 	(void)max;
// 	(void)len;
// 	tmp = *stack;
// 	while (tmp)
// 	{
// 		if (min == tmp->content)
// 			break;
// 		tmp = tmp->next;
// 		i++;
// 	}
// 	printf("min in : %d\n", i);
// 	printf("len/2 : %d\n", len/2);
// }

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = check_all(argc, argv, 1);
	// b = check_all(argc, argv, 1);
	b = NULL;
	less_five_sort(&a, &b);
	// if (a)
	// {
	// 	while (a)
	// 	{
	// 		printf("a => $%d$\n", a->content);
	// 		a = a->next;
	// 	}
	// }
	// while (1);
	return (0);
}
