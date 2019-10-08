/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:09:43 by wtorwold          #+#    #+#             */
/*   Updated: 2019/10/08 15:22:21 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

 void    ft_print(t_base *base);

/*void	ft_swap(int	*tab, int i)
{
	int	temp;

	temp = tab[i];
	tab[i] = tab[i + 1];
	tab[i + 1] = temp;
}*/

/*int	ft_help_av(int len, int *tab)
{
	int av;

	if(len % 2 == 0)
	{
		len = len / 2;
		len--;
		av = (tab[len]);
		return(av);
	}
	else
	{
		len = (len - 1) / 2;
		len--;
		av = (tab[len + 1]);
		return(av);
	}
}*/

/*int	ft_average(t_base *stc)
{
	int len;
	int *tab;
	int	i;

	i = 0;
	len = ft_len(stc->a);
	tab = ft_mas(stc->a, len);
	while(len > i + 1)
	{
		if(tab[i] > tab[i + 1])
		{
			ft_swap(tab, i);
			if (i - 1 >= 0) 
				i--;
			else
				i = 0;
		}
		else
			i++;
	}
	i = 0;
	return(ft_help_av(len, tab));
}*/

/*void    ft_sort_two(t_base *stc)
{
	int first;
	int second;

	first = stc->a->value;
	second = stc->a->next->value;

	if (first > second)
	{
		exucute_ra(stc);
		ft_putstr("ra\n");
	}
}*/

void  ft_sort2(t_base *stc, int max, int min, int av)
{
	int	i;
	t_base *copy;

	i = 0;
	copy = stc;
	while(ft_len(copy->a) > 3)
	{
		if (copy->a->value == av || copy->a->value == min || copy->a->value == max)
		{
			exucute_ra(copy);
			ft_putstr("ra\n");
		}
		else
		{
			exucute_pb(copy);
			ft_putstr("pb\n");
		}
	}
}

void	ft_add_rrb(int len1, int len, t_base *stc)
{
	int ll;
	t_stack *copy;
	
	copy = stc->b;
	ll = len1 + len;
	while(len1-- > 0)
	{
		copy->rrb = ll--;
		copy = copy->next;
	}
	while(copy)
	{
		copy->rrb = len--;
		copy = copy->next;
	}

}

void ft_add_rb(t_base *stc)
{
	t_stack *copy;
	int	i;
	int len1;
	int len;

	len = ft_len(stc->b);
	if (len % 2 == 0)
	{
		len1 = len / 2;
		len = len / 2;
	}
	else
	{
		len1 = (len / 2) + 1;
		len = (len / 2);
	}
	i = 0;
	copy = stc->b;
	while(copy)
	{
		copy->rb = i;
		i++;
		copy = copy->next;
	}
	ft_add_rrb(len1, len, stc);
	while(copy)
	{
		printf("rrb = %d\n", copy->rrb);
		copy = copy->next;
	}
}

void ft_add_rra(t_base *stc)
{
	t_stack *copy_b;
	t_stack *copy_a;
	int i;
	int len;

	i = 1;
	len = ft_len(stc->a);
	copy_b = stc->b;
	copy_a = stc->a;
	while(copy_b)
	{
		i = 1;
		while(copy_a && copy_a->next)
		{
			if(copy_b->value > copy_a->value && copy_b->value < copy_a->next->value)
			{
				copy_b->rra = len - i;
				break ;
			}
			copy_a = copy_a->next;
			i++;
		}
		if (copy_b->rra == -1)
		{
			copy_b->rra = 0;
		}
		copy_a = stc->a;
		copy_b = copy_b->next;
	}
}

void ft_add_ra(t_base *stc)
{
	t_stack *copy_b;
	t_stack *copy_a;
	int i;

	i = 1;
	copy_b = stc->b;
	copy_a = stc->a;
	while(copy_b)
	{
		i = 1;
		while(copy_a && copy_a->next)
		{
			if(copy_b->value > copy_a->value && copy_b->value < copy_a->next->value)
			{
				copy_b->ra = i;
				break ;
			}
			copy_a = copy_a->next;
			i++;
		}
		if (copy_b->ra == -1)
				copy_b->ra = 0;
		copy_a = stc->a;
		copy_b = copy_b->next;
	}
	ft_add_rra(stc);
}

void    ft_solution(t_base *stc);

void ft_bzero_stc(t_stack *copy)
{
	t_stack *temp;

	temp = copy;
	while(temp)
	{
		temp->ra = -1;
		temp->rb = -1;
		temp->rra = -1;
		temp->rrb = -1;
		temp->rr = -1;
		temp->rrr = -1;
		temp = temp->next;
	}
}

void  ft_sort3(t_base *stc)
{
	t_stack *copy;
	t_stack *copy_a;

	copy_a = stc->a;
	copy = stc->b;
	while (stc->b)
	{
		ft_bzero_stc(stc->b);
		ft_add_rb(stc);
		ft_add_ra(stc);
		ft_solution(stc);
	}
}

void ft_sol_rr(t_stack *copy, t_base *stc)
{
	int rr;

	if(copy->ra > copy->rb)
	{
		rr = copy->rb;
		copy->ra = copy->ra - rr;
		copy->rb = copy->rb -rr;
	}
	else
	{
		rr = copy->ra;
		copy->ra = copy->ra - rr;
		copy->rb = copy->rb -rr;
	}
	while(rr-- > 0)
	{
		exucute_rr(stc);
		ft_putstr("rr\n");
	}
}

void ft_sol_rrr(t_stack *copy, t_base *stc)
{
	int rrr;

	if(copy->rra > copy->rrb)
	{
		rrr = copy->rrb;
		copy->rra = copy->rra - rrr;
		copy->rrb = copy->rrb -rrr;
	}
	else
	{
		rrr = copy->rra;
		copy->rra = copy->rra - rrr;
		copy->rrb = copy->rrb - rrr;
	}
	while(rrr-- > 0)
	{
		exucute_rrr(stc);
		ft_putstr("rrr\n");
	}
}

void	ft_solution_rarb(t_base *stc, int min)
{
	t_stack *copy;

	copy = stc->b;
	while(copy->max_r != min)
		copy = copy->next;
	if (copy->ra > 0 && copy->rb > 0)
		ft_sol_rr(copy, stc);
	while(copy->ra-- > 0)
	{
		exucute_ra(stc);
		ft_putstr("ra\n");
	}
	while(copy->rb-- > 0)
	{
		exucute_rb(stc);
		ft_putstr("rb\n");
	}
	exucute_pa(stc);
	ft_putstr("pa\n");
}

void    ft_solution_rrarrb(t_base *stc, int min)
{
	t_stack *copy;

	copy = stc->b;
	while(copy->max_rr != min)
		copy = copy->next;
	if (copy->rra > 0 && copy->rrb > 0)
		ft_sol_rrr(copy, stc);
	while(copy->rra-- > 0)
	{
		exucute_rra(stc);
		ft_putstr("rra\n");
	}
	while(copy->rrb-- > 0)
	{
		exucute_rrb(stc);
		ft_putstr("rrb\n");
	}
	exucute_pa(stc);
	ft_putstr("pa\n");
}

int		ft_max_r(t_base *stc)
{
	t_stack *copy;
	int	min;

	copy = stc->b;
	while(copy)
	{
		if (copy->ra > copy->rb)
			copy->max_r = copy->ra;
		else
			copy->max_r = copy->rb;	
		copy = copy->next;
	}
	copy = stc->b;
	while(copy)
		copy = copy->next;
	copy = stc->b;
	min = copy->max_r;
	copy = copy->next;
	while(copy)
	{
		if (min > copy->max_r)
			min = copy->max_r;
		copy = copy->next;
	}
	return(min);
}

int     ft_max_rr(t_base *stc)
{
	t_stack *copy;
	int min;

	copy = stc->b;
	while(copy)
	{
		if (copy->rra > copy->rrb)
			copy->max_rr = copy->rra;
		else
			copy->max_rr = copy->rrb;
		copy = copy->next;
	}
	copy = stc->b;
	while(copy)
		copy = copy->next;
	copy = stc->b;
	min = copy->max_rr;
	copy = copy->next;
	while(copy)
	{
		if (min > copy->max_rr)
			min = copy->max_rr;
		copy = copy->next;
	}
	return(min);
}

void	ft_solution(t_base *stc)
{
	int	min_r;
	int min_rr;
	t_stack *copy;

	copy = stc->b;
	min_r = ft_max_r(stc);
	min_rr = ft_max_rr(stc);
	if (min_r > min_rr)
		ft_solution_rrarrb(stc, min_rr);
	else
		ft_solution_rarb(stc, min_r);
}

void	ft_sort(t_base *stc)
{
	int	len;
	int	min;
	int	max;
	int av;
	
	max = ft_max(stc->a);
	min = ft_min(stc->a);
	av = ft_average(stc);
	len = ft_len(stc->a);
	if (len > 3 && len <= 5)
	{
		ft_sort_less_5(stc, av);
		return;
	}
	if (len == 2)
	{
		ft_sort_two(stc);
		return ;
	}
	ft_sort2(stc, max, min, av);
	ft_sort_three(stc);
	ft_sort3(stc);
	ft_sort4(stc, min, len);
}

void	ft_print(t_base *base)
{
	t_base *copy;

	copy = base;
	while (copy->a)
	{
		printf("value a = %d\n", copy->a->value);
		copy->a = copy->a->next;
	}
	while (copy->b)
	{
		printf("value b = %d\n", copy->b->value);
		copy->b = copy->b->next;
	}
}

int		main(int ac, char **av)
{
	t_base		stc;

	if(ac < 2)
		return(0);
	if (ft_valid1(av, ac) == 0)
	{
		ft_putstr("Error\n");
		return(1);
	}
	stc.a = fill_stack(ac, av);
	if (ft_valid2(stc.a) == 0)
	{
		ft_putstr("Error\n");
		return(1);
	}
	int len = 5;
	if (check_sort(&stc) == 0)
		ft_sort(&stc);
/*	while (stc.a)
	{
		printf("value a = %d\n", stc.a->value);
		stc.a = stc.a->next;
	}
	while (stc.b)
	{
		printf("value b = %d\n", stc.b->value);
		stc.b = stc.b->next;
	}*/
	ft_free(&stc);
}
