/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:30:31 by mmoumani          #+#    #+#             */
/*   Updated: 2023/01/03 23:45:22 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(int	*a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sort_array(int *arr, int len)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	if (arr)
	{
		while (i < len)
		{
			min = i;
			j = i + 1;
			while (j < len)
			{
				if (arr[j] < arr[min])
					min = j;
				j++;
			}
			ft_swap(&arr[i], &arr[min]);
			i++;
		}
	}
}

int	*to_arr(t_list	*stack, int len)
{
	int	*arr;
	int	i;

	i = 0;
	arr = malloc (len * sizeof(int));
	if (!arr)
		return (NULL);
	while (i < len)
	{
		arr[i] = stack->content;
		stack = stack->next;
		i++;
	}
	sort_array(arr, len);
	return (arr);
}
