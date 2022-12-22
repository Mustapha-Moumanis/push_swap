/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 23:52:07 by mmoumani          #+#    #+#             */
/*   Updated: 2022/12/22 02:52:49 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_hexa(unsigned int arg, size_t i, char c)
{
	if (arg >= 16)
	{
		i += ft_hexa(arg / 16, i, c);
		ft_hexa(arg % 16, i, c);
	}
	else if (arg < 10)
		ft_putchar((arg % 16) + 48);
	else if ((arg >= 10) && (c == 'X'))
		ft_putchar((arg % 16) + 55);
	else if ((arg >= 10) && (c == 'x'))
		ft_putchar((arg % 16) + 87);
	return (i);
}
