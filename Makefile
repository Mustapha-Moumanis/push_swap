# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/21 21:42:38 by mmoumani          #+#    #+#              #
#    Updated: 2022/12/28 12:06:09 by mmoumani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

# FILES = src/*c

FILES = push_swap.c ft_strlen.c ft_atoi.c ft_split.c ft_calloc.c ft_bzero.c ft_isdigit.c \
		ft_lstnew.c ft_lstadd_front.c ft_lstadd_back.c ft_lstlast.c ft_lstsize.c ft_lstdelone.c \
		check_args.c swap_two_first.c stack_to_stack.c swap_last_to_first.c swap_first_to_last.c  \
		sort_helped.c less_five_sort.c array.c

FILES := $(addprefix src/, $(FILES))


FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(FILES)
	cc $(FLAGS) $(FILES) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
