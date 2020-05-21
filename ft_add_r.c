/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:09:43 by wtorwold          #+#    #+#             */
/*   Updated: 2019/10/15 14:37:45 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_add_rrb(int len1, int len, t_base *stc)
{
	int			ll;
	t_stack		*copy;

	copy = stc->b;
	ll = len1 + len;
	while (len1-- > 0)
	{
		copy->rrb = ll--;
		copy = copy->next;
	}
	while (copy)
	{
		copy->rrb = len--;
		copy = copy->next;
	}
}

void			ft_add_rb(t_base *stc)
{
	t_stack		*copy;
	int			i;
	int			len1;
	int			len;

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
	while (copy)
	{
		copy->rb = i;
		i++;
		copy = copy->next;
	}
	ft_add_rrb(len1, len, stc);
}

void			ft_add_rra(t_base *stc)
{
	t_stack		*copy_b;
	t_stack		*copy_a;
	int			i;
	int			len;

	len = ft_len(stc->a);
	copy_b = stc->b;
	copy_a = stc->a;
	while (copy_b)
	{
		i = 1;
		while (copy_a && copy_a->next)
		{
			if (copy_b->value > copy_a->value
					&& copy_b->value < copy_a->next->value)
				copy_b->rra = len - i;
			copy_a = copy_a->next;
			i++;
		}
		if (copy_b->rra == -1)
			copy_b->rra = 0;
		copy_a = stc->a;
		copy_b = copy_b->next;
	}
}

void			ft_add_ra(t_base *stc)
{
	t_stack		*copy_b;
	t_stack		*copy_a;
	int			i;

	copy_b = stc->b;
	copy_a = stc->a;
	while (copy_b)
	{
		i = 1;
		while (copy_a && copy_a->next)
		{
			if (copy_b->value > copy_a->value &&
					copy_b->value < copy_a->next->value)
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
}
