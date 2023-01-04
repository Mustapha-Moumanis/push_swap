NAME = push_swap
B_NAME = checker

FILES = push_swap.c ft_strlen.c ft_atoi.c ft_split.c ft_calloc.c ft_bzero.c ft_isdigit.c \
		ft_lstnew.c ft_lstadd_back.c ft_lstlast.c ft_lstsize.c \
		check_args.c swap_two_first.c stack_to_stack.c swap_last_to_first.c swap_first_to_last.c  \
		sort_helped.c less_five_sort.c array.c larg_sort.c

FILES := $(addprefix src/, $(FILES))

B_FILES = bonus.c ft_strlen.c get_next_line.c get_next_line_utils.c ft_memcmp.c\
		sort_helped.c ft_lstnew.c ft_lstadd_back.c ft_lstlast.c ft_lstsize.c \
		ft_atoi.c ft_split.c ft_calloc.c ft_bzero.c ft_isdigit.c \
		check_args.c swap_two_first.c stack_to_stack.c swap_last_to_first.c swap_first_to_last.c  \

B_FILES := $(addprefix src/, $(B_FILES))


FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(FILES)
	cc $(FLAGS) $(FILES) -o $(NAME)

bonus: $(B_NAME)

$(B_NAME): $(B_FILES)
	cc $(FLAGS) $(B_FILES) -o $(B_NAME)

clean:
	rm -rf $(NAME) $(B_NAME)

fclean: clean

re: fclean all
