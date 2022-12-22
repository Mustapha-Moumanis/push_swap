/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:50:35 by mmoumani          #+#    #+#             */
/*   Updated: 2022/12/22 02:52:49 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_check(const char *str, size_t i, size_t j, va_list args)
{
	if (str[i] == 'c')
		j += ft_putchar(va_arg(args, int));
	if (str[i] == 's')
		j += ft_putstr(va_arg(args, char *));
	if ((str[i] == 'd' || str[i] == 'i'))
		j += ft_putnbr(va_arg(args, int), 1);
	if (str[i] == 'u')
		j += ft_putunbr((va_arg(args, unsigned int)), 1);
	if ((str[i] == 'x') || (str[i] == 'X'))
		j += ft_hexa(va_arg(args, int), 1, str[i]);
	if (str[i] == 'p')
	{
		j += ft_putstr("0x");
		j += ft_address(va_arg(args, size_t), 1);
	}
	if (str[i] == '%')
		j += ft_putchar('%');
	return (j);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '\0')
				break ;
			j = ft_check(str, i, j, args);
			i++;
		}
		else
			j += ft_putchar(str[i++]);
	}
	va_end(args);
	return (j);
}
