/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:11:56 by mmoumani          #+#    #+#             */
/*   Updated: 2022/12/22 02:52:49 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putunbr(unsigned int n, int i)
{
	long	temp;

	if (n < 0)
	{
		ft_putchar('-');
		temp = (-(long) n);
	}
	else
		temp = n;
	if (temp < 10)
		ft_putchar(temp + '0');
	else
	{
		i += ft_putnbr(temp / 10, i);
		ft_putchar(temp % 10 + '0');
	}
	return (i);
}
