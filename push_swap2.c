/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:09:43 by wtorwold          #+#    #+#             */
/*   Updated: 2019/09/30 18:03:25 by wtorwold         ###   ########.fr       */
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
/*	while(len > i)
	{
		printf("tab = %d\n", tab[i]);
		i++;
	}*/
	return(ft_help_av(len, tab));
}

void	ft_sort_3(t_base *stc)
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

/*void	ft_sort2(int max, int  min, t_base *stc, int len)
{
	int	av;
	int	i;
	t_base *copy;
	int a;
	int mi;

	i = 0;
	a = -1;
	mi = -1;
	av = ft_average(stc);
	printf("\nmin = %d max = %d av = %d %d\n", min, max, av, len);
	while(len > i++)
	{
		copy = stc;
		printf("test %d min %d\n", copy->a->value, min);
		if (copy->a->value == min)
			exucute_ra(copy);
		else if (copy->a->value == max)
				exucute_ra(copy);
		else if (copy->a->value == av)
		{
			exucute_ra(copy);
			a++;
		}
		else
			exucute_pb(copy);
	}
	printf("test\n");
	ft_sort_3(stc);
}*/

void    ft_sort_4(t_base *stc)
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

int ft_average_b(t_base *stc)
{
	int len;
	int *tab;
	int i;
	
	i = 0;
	len = ft_len(stc->b);
	tab = ft_mas(stc->b, len);
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
//	i = 0;
/*  while(len > i)
				134     {
				135         printf("tab = %d\n", tab[i]);
				136         i++;
				137     }*/
	return(ft_help_av(len, tab));
}

void	ft_sort_big_b(t_base	*stc)
{
	int av;
	int i;
	t_base *copy;
	int len;
	int count = 0;

	len = ft_len(stc->b);
	i = 0;
	av = ft_average_b(stc);
	while(len > i++)
	{
		copy = stc;
		if (copy->b->value >= av)
		{
			exucute_pa(copy);
			ft_putstr("pa\n");
			count ++;
		}
		else
		{
			exucute_rb(copy);
			ft_putstr("rb\n");
		}
	}
	while (count > 0)
	{
		exucute_pb(copy);
		ft_putstr("pb\n");
		count--;
	}
}

void	ft_sort_max(t_base *stc, int max)
{
	int i;
	t_stack *temp;
	static int ii = 0;
	

	if( ii++ <  4) 
		return ;
//	ft_print(stc);
	i = 0;
	temp = stc->b;
	printf("max %d\n", max);
	while(temp)
	{
		i++;
		if(temp -> value == max)
			break ;
		temp = temp->next;
	}
	temp = stc->b;
	if((ft_len(stc->b)/2) < i)
	{
		while(i-- > 0)
		{
//			exucute_rrb(stc);
			ft_putstr("rrb\n");
		}
	}
	ft_print(stc);
}

void	ft_sort_b(t_base *stc, int *tab, int l)
{
	int i;
	t_base *copy = stc;
	int max;
	
	i = 0;
//	if (ft_len(stc->b) == tab[l] && tab[l] > 20)
//		ft_sort_big_b(copy);
	max = ft_max(stc->b);
	ft_sort_max(stc, max);
/*	if (stc->b != NULL && stc->a->value > stc->a->next->value && stc->b->value < stc->b->next->value)
	{
		exucute_ss(stc);
		ft_putstr("ss\n");
	}*/
	if (stc->b != NULL && stc->b->value < stc->a->value)
	{
		exucute_pa(stc);
		ft_putstr("pa\n");
	}
	else if (stc->b != NULL && stc->b->value > stc->a->value)
	{
	while (stc->b->value > stc->a->value)
	{
		exucute_ra(stc);
		ft_putstr("ra\n");
		i++;
	}
	exucute_pa(stc);
	ft_putstr("pa\n");
	while (i-- > 0)
	{
		exucute_rra(stc);
		ft_putstr("rra\n");
	}
	}
//	ft_print(stc);
}

/*void	ft_sort_5(t_base *stc, int *tab, int i)
{
	int m;
//	t_stack *temp;
	t_base	*copy;

//	temp = stc->b;
	m = 0;
	while(stc->b)
	{
		copy = stc;
		while(i >= m)
			ft_sort_b(copy, tab[m++]); 
	}

}*/

//void    ft_sortbb(t_base *stc)
//{

//}

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
		ft_sort_3(stc);
	else if (len == 2)
		ft_sort_4(stc);
//	int help = 0;
//	temp = 0;
	while(stc->b)
			ft_sort_b(stc, tab, i++);
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
