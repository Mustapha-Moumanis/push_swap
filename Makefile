# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/21 21:42:38 by mmoumani          #+#    #+#              #
#    Updated: 2022/12/22 21:53:04 by mmoumani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

FILES = push_swap.c ft_printf.c ft_strlen.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putunbr.c ft_hexa.c ft_address.c ft_atoi.c ft_split.c ft_calloc.c ft_bzero.c ft_isdigit.c \
		ft_lstnew.c ft_lstadd_back.c ft_lstlast.c\

OBJS = $(FILES:.c=.o)

all: $(NAME)

$(OBJS) : $(FILES)
	@echo "compilation FILES ..."
	@cc -Wall -Wextra -Werror -c $(FILES)

$(NAME): $(OBJS)
	@echo "Archive OBJS in file.a"
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	@echo "cleaning OBJS files"
	#@echo "cleaning OBJS and bonus OBJS files"
	@rm -f $(OBJS)

fclean: clean
	@echo "cleaning .a file"
	@rm -f $(NAME)

re: fclean all
