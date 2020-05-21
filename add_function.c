/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:09:43 by wtorwold          #+#    #+#             */
/*   Updated: 2019/10/15 14:26:29 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				ft_len(t_stack *a)
{
	t_stack		*temp;
	int			len;

	len = 0;
	temp = a;
	while (temp)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}

int				*ft_mas(t_stack *a, int len)
{
	int			*tab;
	t_stack		*temp;
	int			i;

	i = 0;
	temp = a;
	tab = (int	*)malloc(sizeof(tab) * (len));
	while (i < len)
	{
		tab[i] = temp->value;
		temp = temp->next;
		i++;
	}
	return (tab);
}

int				ft_max(t_stack *a)
{
	int			max;
	t_stack		*temp;

	max = a->value;
	temp = a->next;
	while (temp)
	{
		if (max < temp->value)
			max = temp->value;
		temp = temp->next;
	}
	return (max);
}

int				ft_min(t_stack *a)
{
	int			min;
	t_stack		*temp;

	min = a->value;
	temp = a->next;
	while (temp)
	{
		if (min > temp->value)
			min = temp->value;
		temp = temp->next;
	}
	return (min);
}

void			ft_sort_three(t_base *stc)
{
	int			first;
	int			second;
	int			third;

	first = stc->a->value;
	second = stc->a->next->value;
	third = stc->a->next->next->value;
	if (first > second && second < third && first < third)
		exucute_sa_print(stc);
	else if (first > second && second > third && first > third)
		exucute_sa_rra(stc);
	else if (first > second && second < third && first > third)
	{
		exucute_ra(stc);
		ft_putstr("ra\n");
	}
	else if (first < second && second > third && first < third)
		exucute_sa_ra(stc);
	else if (first < second && second > third && first > third)
	{
		exucute_rra(stc);
		ft_putstr("rra\n");
	}
}
