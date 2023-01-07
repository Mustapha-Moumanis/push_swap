/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 23:51:35 by mmoumani          #+#    #+#             */
/*   Updated: 2023/01/06 19:33:39 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		len;

	if (argc <= 1)
		return (0);
	a = check_all(argc, argv, 1);
	b = NULL;
	if (is_sorted(a))
		exit(0);
	len = ft_lstsize(a);
	if (len <= 5)
		less_five_sort(&a, &b);
	else
		larg_sort(&a, &b, ft_lstsize(a));
	return (0);
}
