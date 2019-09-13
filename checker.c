/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:09:43 by wtorwold          #+#    #+#             */
/*   Updated: 2019/09/13 18:26:26 by wtorwold         ###   ########.fr       */
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

void	exucute_sa(t_base *stc)
{
	int temp;

	if (stc->a == NULL || stc->a->next == NULL)
		return ;
	temp = stc->a->value;
	stc->a->value = stc->a->next->value;
	stc->a->next->value = temp;
}

void    exucute_rb(t_base *stc)
{
	int temp;
	t_stack *help;

	if (stc->b == NULL)
		return ;
	help = stc->b;
	temp = help->value;
	while(help)
	{
		if (help->next != NULL)
			help->value = help->next->value;
		if (help->next == NULL)
			break ;
		help = help->next;
	}
	help->value = temp;
}

void    exucute_ra(t_base *stc)
{
	int temp;
	t_stack *help;

	if (stc->a == NULL)
		return ;
	help = stc->a;
	temp = help->value;
	while(help)
	{
		if (help->next != NULL)
			help->value = help->next->value;
		if (help->next == NULL)
			break ;
		help = help->next;
	}
	help->value = temp;
}

void    exucute_rra(t_base *stc)
{
	int temp;
	int tt;
	t_stack *help;
	t_stack *copy;

	help = stc->a;
	copy = help;
	temp = help->value;
	while(help)
	{
		if (help->next != NULL)
		{
			tt = help->next->value;
			help->next->value = temp;
			temp = tt;
		}
		if (help->next == NULL)
			break ;
		help = help->next;
	}
	copy->value = temp;
}

void    exucute_rrb(t_base *stc)
{
	int temp;
	int tt;
	t_stack *help;
	t_stack *copy;

	help = stc->b;
	copy = help;
	temp = help->value;
	while(help)
	{
		if (help->next != NULL)
		{
			tt = help->next->value;
			help->next->value = temp;
			temp = tt;
		}
		if (help->next == NULL)
			break ;
		help = help->next;
	}
	copy->value = temp;
}

void    exucute_pb(t_base *stc)
{
	t_stack *list;
	t_stack *new;

	if (stc->a == NULL)
		return ;
	new = (t_stack *)malloc(sizeof(t_stack));
	new->value = stc->a->value;
	new->next = NULL;
	if (stc->b == NULL)
		stc->b = new;
	else
	{
		new->next = stc->b;
		stc->b = new;
	}
	list = stc->a->next;
	free(stc->a);
	stc->a = NULL;
	stc->a = list;
//	if (stc->a == NULL)
//		printf("NULL\n");
//	printf("test %p\n", stc->a); если все элементы передам в стэк б и выполню sa то сегается
}

void    exucute_sb(t_base *stc)
{
	int temp;

	if (stc->b == NULL || stc->b->next == NULL)
		return ;
	temp = stc->b->value;
	stc->b->value = stc->b->next->value;
	stc->b->next->value = temp;
}

void    exucute_pa(t_base *stc)
{
	t_stack *new;
	t_stack *list;

	if (stc->b == NULL)
		return ;
	new = (t_stack *)malloc(sizeof(t_stack));
	new->value = stc->b->value;
	new->next = NULL;
	if (stc->a == NULL)
		stc->a = new;
	else
	{
		new->next = stc->a;
		stc->a = new;
	}
	list = stc->b->next;
	free(stc->b);
	stc->b = list;
}

void    exucute_rr(t_base *stc)
{
	exucute_ra(stc);
	exucute_rb(stc);
}

void    exucute_rrr(t_base *stc)
{
	exucute_rra(stc);
	exucute_rrb(stc);
}

void    exucute_ss(t_base *stc)
{
	exucute_sa(stc);
	exucute_sb(stc);
}

int	check_valid(char *line, t_base *stc)
{
	int	i;
	
	i = 0;
	int m;
/*	if(ft_strcmp(line, "sa") == 0)
	{
		exucute_sa(stc);
		return(1);
	}*/
//	m = (ft_strcmp(line, "sa")); 
	(m = ft_strcmp(line, "sa")) == 0 ? exucute_sa(stc) : i++;
//	printf("%d\n", i);
	
	if (ft_strcmp(line, "ra") == 0)
	{
		exucute_ra(stc);
		return(1);
	}
	if (ft_strcmp(line, "rra") == 0)
	{
		exucute_rra(stc);
		return(1);
	}
	if (ft_strcmp(line, "pb") == 0)
	{
		exucute_pb(stc);
		return(1);
	}
	if (ft_strcmp(line, "sb") == 0)
	{
		exucute_sb(stc);
		return(1);
	}
	if (ft_strcmp(line, "pa") == 0)
	{
		exucute_pa(stc);
		return(1);
	}
	if (ft_strcmp(line, "rb") == 0)
	{
		exucute_rb(stc);
		return(1);
	}
	if (ft_strcmp(line, "rrb") == 0)
	{
		exucute_rrb(stc);
		return(1);
	}
	if (ft_strcmp(line, "rr") == 0)
	{
		exucute_rr(stc);
		return(1);
	}
	if (ft_strcmp(line, "rrr") == 0) 
	{
		exucute_rrr(stc);
		return(1);
	}
	if (ft_strcmp(line, "ss") == 0)
	{
		exucute_ss(stc);
		return(1);
	}
		return(i);
}

int		check_sort(t_base *stc)
{
	t_stack		*temp;
	if (stc->b != NULL)
		return(0);
	if (stc->a == NULL)
		return(0);
	temp = stc->a;
	while(temp)
	{
		if(temp->next)
			if(temp->value > temp->next->value)
				return(0);
		temp = temp->next;
	}
	return(1);
}

int		main(int ac, char **av)
{
	t_base		stc;
	char		*line;

	if(ac < 2)
		return(0);
	stc.a = fill_stack(ac, av);
	while(get_next_line(0, &line) > 0)
	{
		if(check_valid(line, &stc)!=0)
		{
			printf("error");
			return(0);
		}
		free(line);
	}
	if (check_sort(&stc))
		printf("OK\n");
	else
		printf("KO\n");

//	if (stc.a == NULL)
//		printf("1 NULL\n");
	while (stc.a)
	{
		printf("value a = %d\n", stc.a->value);
		stc.a = stc.a->next;
	}
	while (stc.b)
	{
		printf("value b = %d\n", stc.b->value);
		stc.b = stc.b->next;
	}
}
