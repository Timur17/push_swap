/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:09:43 by wtorwold          #+#    #+#             */
/*   Updated: 2019/09/22 19:26:08 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void    ft_print(t_base *stc);

void	ft_sort_3(t_base *stc)
{
	int first;
	int	second;
	int third;

	first = stc->a->value;
	second = stc->a->next->value;
	third = stc->a->next->next->value;
	if( first > second && second < third && first < third)
		exucute_sa(stc);
	else if( first > second && second > third && first > third)
	{
		exucute_sa(stc);
		exucute_rra(stc);
	}
	else if( first > second && second < third && first > third)
		exucute_ra(stc);
	else if( first < second && second > third && first < third)
	{
		exucute_sa(stc);
		exucute_ra(stc);
	}
	else if( first < second && second > third && first > third)
		exucute_rra(stc);

}	

void	ft_sort2(int max, int  min, t_base *stc, int len)
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
}


void	ft_sort(t_base *stc)
{
	int max = -1;
	int	min = -1;
	int	len;

	len = ft_len(stc->a);
	max = ft_max(stc->a);
	min = ft_min(stc->a);
	ft_sort2(max, min, stc, len);
}

void	ft_print(t_base *base)
{
	t_base *stc;

	stc = base;
	while (stc->a)
	{
		printf("value a = %d\n", stc->a->value);
		stc->a = stc->a->next;
	}
	while (stc->b)
	{
		printf("value b = %d\n", stc->b->value);
		stc->b = stc->b->next;
	}
}

int		main(int ac, char **av)
{
	t_base		stc;

	if(ac < 2)
		return(0);
	if (ft_valid1(av, ac) == 0)
		ft_putstr("Error1\n");
	stc.a = fill_stack(ac, av);
	if (ft_valid2(stc.a) == 0)
		ft_putstr("Error2\n");
	ft_sort(&stc);
	ft_print(&stc);
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
