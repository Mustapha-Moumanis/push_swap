/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 01:47:53 by mmoumani          #+#    #+#             */
/*   Updated: 2023/01/06 00:16:18 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <stdint.h>
# include <fcntl.h>

// libft function :

size_t	ft_strlen(const char *str);
long	ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
int		ft_isdigit(int c);

typedef struct range_data
{
	int		len;
	int		max;
	int		mid;
	int		offset;
	int		start;
	int		end;
	int		down;
}		t_data;

// linked list :

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);

// checked args and create stack

t_list	*check_all(int argc, char **argv, int i);
int		exist(t_list *lst, long nb);
void	ft_error(void);

// Rules :

void	sa(t_list *stack_a, int print);
void	sb(t_list *stack_b, int print);
void	ss(t_list *stack_a, t_list *stack_b, int print);
void	pa(t_list **stack_a, t_list **stack_b, int print);
void	pb(t_list **stack_a, t_list **stack_b, int print);
void	ra(t_list **stack_a, int print);
void	rb(t_list **stack_b, int print);
void	rr(t_list **stack_a, t_list **stack_b, int print);
void	rra(t_list **stack_a, int print);
void	rrb(t_list **stack_b, int print);
void	rrr(t_list **stack_a, t_list **stack_b, int print);

// sort :

void	two_sorted(t_list	**stack);
void	tree_sorted(t_list	**stack);
void	five_sorted(t_list	**a, t_list **b, int len, int min);
void	less_five_sort(t_list **stack_a, t_list **stack_b);
int		maximum(t_list	*stack);
int		minimum(t_list	*stack);
int		is_sorted(t_list *stack);
int		*to_arr(t_list	*stack, int len);
int		max_index_place(t_list	*stack, int max);
int		in_range(int content, int *arr, int start, int end);
void	larg_sort(t_list **stack_a, t_list **stack_b, int len);

//  Bonus :

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_first_str(const char *buf);
char	*ft_reserve(char *re, char *line);
char	*ft_strdup(const char *s1);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

#endif