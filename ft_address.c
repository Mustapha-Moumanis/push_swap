/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_address.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:24:38 by mmoumani          #+#    #+#             */
/*   Updated: 2022/12/22 02:52:49 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_address(size_t arg, size_t i)
{
	if (arg >= 16)
	{
		i += ft_address(arg / 16, i);
		ft_address(arg % 16, i);
	}
	else if (arg < 10)
		ft_putchar((arg % 16) + 48);
	else if (arg >= 10)
		ft_putchar((arg % 16) + 87);
	return (i);
}
