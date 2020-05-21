# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcutjack <lcutjack@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/20 15:52:49 by lcutjack          #+#    #+#              #
#    Updated: 2019/10/16 15:46:27 by wtorwold         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = get_next_line.c stack.c valid.c execute3.c execute2.c execute.c free.c checksort.c ft_sort_less_5.c add_function.c sort.c ft_add_r.c solution.c sort2.c ft_print.c exucute2.c
SRCM = push_swap.c checker.c
OBJ = $(SRC:.c=.o)
OBJM = $(SRCM:.c=.o)
INC = push_swap.h

all: game

game: $(OBJ) $(OBJM)
	@make -C libft/
	@gcc $(OBJ) checker.o -I $(INC) -L. libft/libft.a -o checker
	@gcc $(OBJ) push_swap.o -I $(INC) -L. libft/libft.a -o push_swap

clean:
	@make fclean -C libft/
	@rm -rf *.o

fclean: clean
	@rm -rf ./checker ./push_swap

re: fclean all
