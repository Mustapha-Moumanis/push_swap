/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:11:54 by mmoumani          #+#    #+#             */
/*   Updated: 2022/12/22 02:52:49 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	if (s)
	{
		while (s[i])
		{
			ft_putchar(s[i]);
			i++;
		}
	}
	return (i);
}
