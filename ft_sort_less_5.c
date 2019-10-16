/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_less_5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:43:47 by wtorwold          #+#    #+#             */
/*   Updated: 2019/10/15 14:45:38 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_sort_b(t_base *stc, int l)
{
	if (l == 5)
		if (stc->b->value < stc->b->next->value)
		{
			exucute_sb(stc);
			ft_putstr("sb\n");
		}
	while (stc->b)
	{
		exucute_pa(stc);
		ft_putstr("pa\n");
	}
}

void			ft_sort_less_5(t_base *stc, int av)
{
	t_stack			*copy;
	int				len;
	int				l;

	copy = stc->a;
	l = ft_len(stc->a);
	len = ft_len(stc->a);
	while (len-- > 0)
	{
		copy = stc->a;
		if (copy->value >= av)
		{
			exucute_ra(stc);
			ft_putstr("ra\n");
		}
		else
		{
			exucute_pb(stc);
			ft_putstr("pb\n");
		}
	}
	ft_sort_three(stc);
	ft_sort_b(stc, l);
}
