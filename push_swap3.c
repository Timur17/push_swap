/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:09:43 by wtorwold          #+#    #+#             */
/*   Updated: 2019/10/08 13:14:18 by wtorwold         ###   ########.fr       */
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

void  ft_sort2(t_base *stc, int len)
{
	int av;
	int	i;
	t_base *copy;

	i = 0;
	av = ft_average(stc);
	printf("av = %d\n", av);
	while(len > i++)
	{
		copy = stc;
		if (copy->a->value >= av)
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

int ft_average_b(t_base *stc, int len, char c)
{
	int *tab;
	int i;
	t_stack *copy;
	
	if (c == 'a')
		copy = stc->a;
	else
		copy = stc->b;

	i = 0;
	tab = ft_mas(copy, len);
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
/*	while(len > i)
	{
		printf("tab = %d\n", tab[i]);
		i++;
	}*/
	return(ft_help_av(len, tab));
}

void	ft_sort_b(t_base *stc, int *len)
{
	int		av;
	t_base	*copy;
	int		pa;
	int		rb;

	copy = stc;
	pa = rb = 0;
	av = ft_average_b(stc, *len, 'b');
	while(*len > 0)
	{
		if(copy->b->value > av)
		{
			exucute_pa(copy);
			ft_putstr("pa\n");
			pa++;
		}
		else
		{
			exucute_rb(copy);
			ft_putstr("rb\n");
			rb++;
		}
		*len = *len - 1;
	}
	*len = rb;
	while(rb-- > 0)
	{
		exucute_rrb(copy);
		ft_putstr("rrb\n");
	}
}

int    ft_sort_a(t_base *stc, int len)
{
	int     av;
	t_base  *copy;
	int     ra;
	int     i;

	i = 0;
	copy = stc;
	ra = 0;
	av = ft_average_b(stc, len, 'a');
	while(len-- > 0)
	{
		if(copy->a->value > av)
		{
			exucute_ra(copy);
			ft_putstr("ra\n");
			ra++;
			i++;
		}
		else
		{
			exucute_pb(copy);
			ft_putstr("pb\n");
		}
	}
	while(ra-- > 0)
	{
		exucute_rra(copy);
		ft_putstr("rra\n");
	}
	return(i);
}

void	ft_sort_finish(t_base *stc, int *len)
{
	int i;
	int l;
	t_stack *temp;

	temp = stc->b;
	i = *len;
	l = 1;
	while(i-- > 0)
	{
		temp->m = l++;
		temp = temp->next;
	}
	i = *len;
	temp = stc->b;
	while(i-- > 0)
	{
		printf("%d\n", temp->m);
		temp = temp->next;
	}

}


void    ft_sort_qb(t_base *stc, int *tab, int i)
{
	int *len;
	int len_a;
	int temp;
	int main;

	temp = tab[0];
	len = &tab[0];
	main = tab[0];
	while (*len >= 5)
		ft_sort_b(stc, len);
	len_a = temp - *len;
	printf("len_a %d\n", len_a);
	while(len_a > 5)
		len_a = ft_sort_a(stc, len_a);
	printf("len_a %d\n", len_a);
	main = main - len_a;
	len = &main;
	ft_sort_finish(stc, len);
}

void	ft_sort(t_base *stc)
{
	int	len;
	int *tab;
	int	i;
	int	temp;

	temp = 0;
	i = -1;
	len = ft_len(stc->a);
	tab = (int *)malloc(sizeof(tab) * len/2);
	while((len = ft_len(stc->a)) > 3)
	{
		ft_sort2(stc, len);
		if(ft_len(stc->b) > 0)
		{
			temp = ft_len(stc->b) - temp;
			tab[++i] = temp;
			temp = ft_len(stc->b);
		}
	}
	if (len == 3)
		ft_sort_three(stc);
	else if (len == 2)
		ft_sort_two(stc);
	temp = 6;
	tab[0] = 10;
	if(stc->b)
	ft_sort_qb(stc, tab, 0);
//	int help = 6;
//	ft_sort_b(stc, &help );
//	temp = 0;
//	while(i >= temp)
//		printf("tab = %d\n", tab[temp++]);
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
	if (check_sort(&stc) == 0)
		ft_sort(&stc);
//	ft_print(&stc);
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
