/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:09:43 by wtorwold          #+#    #+#             */
/*   Updated: 2019/09/10 20:16:51 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct	s_stack
{
	int	value;
	struct s_stack *next;
}				t_stack;

typedef struct    s_stacks
{
	t_stack		*a;
	t_stack		*b;
//	int			status;
}				t_base;

t_stack	*fill_stack(int ac, char **av)
{
	int		i;
	t_stack *temp;
	t_stack *test;
	t_stack	*copy;

	i = 1;
	test = (t_stack *)malloc(sizeof(t_stack));
	test->next = NULL;
	temp = test;
	while(ac > i)
	{
		if (temp->next != NULL)
			temp = temp->next;
		temp->value = atoi(av[i]);
		copy = (t_stack *)malloc(sizeof(t_stack));
		temp->next = copy;
		i++;
	}
	free(copy);
	temp->next = NULL;
	return(test);
}

int	check_valid(char *line)
{
	if(ft_strcmp(line, "sa") || ft_strcmp(line, "sb")) 
//			|| ft_strcmp(line, "ss")
//		|| ft_strcmp(line, "pa") || ft_strcmp(line, "pb"))
	{
		printf("test");
		return(1);
	}
	else
	{
		return(0);
	}
}

int		main(int ac, char **av)
{
	t_base		stc;
	t_stack		*a;
	t_stack     *b;
	char		*line;

	b = NULL;
	if(ac < 2)
		return(0);
	a = fill_stack(ac, av);
	stc.a = a;
	printf("%d", stc.a->next->value);

	while(get_next_line(0, &line) > 0)
	{
		if(check_valid(line)==0)
		{
			printf("error");
			return(0);
		}
		printf("%s", line);
		free(line);
	}


/*	while (a)
	{
		printf("%d\n", a->value);
		a = a->next;
	}*/
}
