/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:09:43 by wtorwold          #+#    #+#             */
/*   Updated: 2019/10/15 14:01:23 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				ft_sort2(t_base *stc, int max, int min, int av)
{
	int				i;
	t_base			*copy;

	i = 0;
	copy = stc;
	while (ft_len(copy->a) > 3)
	{
		if (copy->a->value == av || copy->a->value == min
				|| copy->a->value == max)
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

int					ft_max_r(t_base *stc)
{
	t_stack			*copy;
	int				min;

	copy = stc->b;
	while (copy)
	{
		if (copy->ra > copy->rb)
			copy->max_r = copy->ra;
		else
			copy->max_r = copy->rb;
		copy = copy->next;
	}
	copy = stc->b;
	while (copy)
		copy = copy->next;
	copy = stc->b;
	min = copy->max_r;
	copy = copy->next;
	while (copy)
	{
		if (min > copy->max_r)
			min = copy->max_r;
		copy = copy->next;
	}
	return (min);
}

int					ft_max_rr(t_base *stc)
{
	t_stack			*copy;
	int				min;

	copy = stc->b;
	while (copy)
	{
		if (copy->rra > copy->rrb)
			copy->max_rr = copy->rra;
		else
			copy->max_rr = copy->rrb;
		copy = copy->next;
	}
	copy = stc->b;
	while (copy)
		copy = copy->next;
	copy = stc->b;
	min = copy->max_rr;
	copy = copy->next;
	while (copy)
	{
		if (min > copy->max_rr)
			min = copy->max_rr;
		copy = copy->next;
	}
	return (min);
}
