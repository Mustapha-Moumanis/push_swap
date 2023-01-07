/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 22:08:51 by mmoumani          #+#    #+#             */
/*   Updated: 2023/01/06 00:29:36 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	bonus_checker(t_list **a, t_list **b, char *s)
{
	if (ft_memcmp(s, "rra\n", 4) == 0)
		rra(a, 0);
	else if (ft_memcmp(s, "rrb\n", 4) == 0)
		rrb(b, 0);
	else if (ft_memcmp(s, "rrr\n", 4) == 0)
		rrr(a, b, 0);
	else if (ft_memcmp(s, "ra\n", 3) == 0)
		ra(a, 0);
	else if (ft_memcmp(s, "rb\n", 3) == 0)
		rb(b, 0);
	else if (ft_memcmp(s, "rr\n", 3) == 0)
		rr(a, b, 0);
	else if (ft_memcmp(s, "sa\n", 3) == 0)
		sa(*a, 0);
	else if (ft_memcmp(s, "sb\n", 3) == 0)
		sb(*b, 0);
	else if (ft_memcmp(s, "ss\n", 3) == 0)
		ss(*a, *b, 0);
	else if (ft_memcmp(s, "pa\n", 3) == 0)
		pa(a, b, 0);
	else if (ft_memcmp(s, "pb\n", 3) == 0)
		pb(a, b, 0);
	else
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	*s;

	if (argc <= 1)
		return (0);
	a = check_all(argc, argv, 1);
	b = NULL;
	while (1)
	{
		s = get_next_line(0);
		if (!s)
			break ;
		if (bonus_checker(&a, &b, s) == 0)
			ft_error();
	}
	if (is_sorted(a) == 1 && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
