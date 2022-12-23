/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 23:51:35 by mmoumani          #+#    #+#             */
/*   Updated: 2022/12/23 01:29:05 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int all_isdigit(char *str)
{
    int i;

    i = 0;
    if (((str[0] == '+') && str[1]) || ((str[0] == '-') && str[1]))
        i++;
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

int exist(t_list *lst, int nb)
{
    if (lst)
	{
		while (lst)
		{
            if (nb == lst->content)
                return (1);
			lst = lst->next;
		}
	}
    return (0);
}

t_list *check_args(int argc, char **argv)
{
    int         nb;
    int         i;
    int         j;
    char	    **s1;
    t_list      *head;

    i = 1;
    while (i < argc)
    {
        s1 = ft_split(argv[i], ' ');
        j = 0;
        while (s1[j])
        {
            if (!all_isdigit(s1[j]))
            {
                write(2, "Error", 5);
                return (head);
            }
            nb = ft_atoi(s1[j]);
            if(!exist(head, nb))
            {
                ft_lstadd_back(&head, ft_lstnew(ft_atoi(s1[j])));
                ft_printf("%d\n", ft_lstlast(head)->content);
            }
            else
            {
                write(2, "Error", 5);
                return (head);
            }
            j++;
        }
        i++;
    }
    return (head);
}

int main(int argc, char **argv)
{
    t_list  *a;
    a = check_args(argc, argv);
    
    return (0);
}