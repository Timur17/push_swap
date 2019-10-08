/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:09:43 by wtorwold          #+#    #+#             */
/*   Updated: 2019/10/08 13:12:26 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

 void    ft_print(t_base *base);

int		ft_len(t_stack	*a)
{
	t_stack *temp;
	int len;

	len = 0;
	temp = a;
	while(temp)
	{
		len++;
		temp = temp->next;
	}
	return(len);
}

int		*ft_mas(t_stack  *a, int len)
{
	int	*tab;
	t_stack *temp;
	int	i;

	i = 0;
	temp = a;
	tab = (int	*)malloc(sizeof(tab) * (len));
	while(i < len)
	{
		tab[i] = temp->value;
		temp = temp->next;
		i++;
	}

	return(tab);
}

int		ft_max(t_stack *a)
{
	int max;
	t_stack *temp;

	max = a->value;
	temp = a->next;
	while(temp)
	{
		if (max < temp->value)
			max = temp->value;
		temp = temp->next;
	}
	return(max);
}

int     ft_min(t_stack *a)
{
	int min;
	t_stack *temp;

	min = a->value;
	temp = a->next;
	while(temp)
	{
		if (min > temp->value)
			min = temp->value;
		temp = temp->next;
	}
	return(min);
}

void	ft_swap(int	*tab, int i)
{
	int	temp;

	temp = tab[i];
	tab[i] = tab[i + 1];
	tab[i + 1] = temp;
}

int	ft_help_av(int len, int *tab)
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
}

int	ft_average(t_base *stc)
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
}

void	ft_sort_three(t_base *stc)
{
	int first;
	int	second;
	int third;

	first = stc->a->value;
	second = stc->a->next->value;
	third = stc->a->next->next->value;
	if( first > second && second < third && first < third)
	{
		exucute_sa(stc);
		ft_putstr("sa\n");
	}
	else if( first > second && second > third && first > third)
	{
		exucute_sa(stc);
		exucute_rra(stc);
		ft_putstr("sa\nrra\n");
	}
	else if( first > second && second < third && first > third)
	{
		exucute_ra(stc);
		ft_putstr("ra\n");
	}
	else if( first < second && second > third && first < third)
	{
		exucute_sa(stc);
		exucute_ra(stc);
		ft_putstr("sa\nra\n");
	}
	else if( first < second && second > third && first > third)
	{
		exucute_rra(stc);
		ft_putstr("rra\n");
	}

}

void    ft_sort_three_b(t_base *stc)
{
	int first;
	int second;
	int third;
	
	first = stc->b->value;
	second = stc->b->next->value;
	third = stc->b->next->next->value;
	if( first > second && second < third && first < third)
	{
		exucute_sa(stc);
		ft_putstr("sa\n");
	}
	else if( first > second && second > third && first > third)
	{
		exucute_sa(stc);
		exucute_rra(stc);
		ft_putstr("sa\nrra\n");
	}
	else if( first > second && second < third && first > third)
	{
		exucute_ra(stc);
		ft_putstr("ra\n");
	}
	else if( first < second && second > third && first < third)
	{
		exucute_sa(stc);
		exucute_ra(stc);
		ft_putstr("sa\nra\n");
	}
	else if( first < second && second > third && first > third)
	{
		exucute_rra(stc);
		ft_putstr("rra\n");
	}
}

void    ft_sort_two(t_base *stc)
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
}

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
	printf("len1 = %d len2 = %d\n", len1, len); 
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
//		printf("rb = %d\n", copy->rb);
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
		while(copy_b->value > copy_a->value)
		{
			if(copy_b->value < copy_a->next->value)
				copy_b->rra = len - i++;
			copy_a = copy_a->next;
			i++;
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
		while(copy_b->value > copy_a->value)
		{
			if(copy_b->value < copy_a->next->value)
				copy_b->ra = i++;
			copy_a = copy_a->next;
			i++;
		}	
		copy_a = stc->a;
		copy_b = copy_b->next;
	}
	ft_add_rra(stc);
}

void    ft_solution(t_base *stc);

void  ft_sort3(t_base *stc, int max, int min, int av)
{
	t_stack *copy;
	t_stack *copy_a;

	copy_a = stc->a;
	copy = stc->b;
	ft_add_rb(stc);
	ft_add_ra(stc);
	while(copy)
	{
		printf("rb = %d\n", copy->rb);
		copy = copy->next;
	}
	copy = stc->b;
	while(copy)
	{
		printf("rrb = %d\n", copy->rrb);
		copy = copy->next;
	}
	copy = stc->b;
	while(copy)
	{
		printf("ra = %d\n", copy->ra);
		copy = copy->next;
	}
	copy = stc->b;
	while(copy)
	{
		printf("rra = %d\n", copy->rra);
		copy = copy->next;
	}
	ft_solution(stc);
}

void	ft_solution(t_base *stc)
{
	int	min;
	t_stack *copy;

	copy = stc->b;
	min = copy->ra + copy->rb; 
	while(copy)
	{
		if (min > copy->ra + copy->rb)
			min = copy->ra + copy->rb;
		copy = copy->next;
	}
	printf("solut %d\n", min);
	copy = stc->b;
	while(copy->ra + copy->rb != min)
		copy = copy->next;
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
	ft_sort2(stc, max, min, av);
	ft_sort_three(stc);
	ft_sort3(stc, max, min, av);
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
	ft_free(&stc);
}
