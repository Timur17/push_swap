/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:09:43 by wtorwold          #+#    #+#             */
/*   Updated: 2019/10/10 22:37:14 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_bzero_stc(t_stack *copy)
{
	t_stack		*temp;

	temp = copy;
	while (temp)
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

void			ft_sol_rr(t_stack *copy, t_base *stc)
{
	int			rr;

	if (copy->ra > copy->rb)
	{
		rr = copy->rb;
		copy->ra = copy->ra - rr;
		copy->rb = copy->rb - rr;
	}
	else
	{
		rr = copy->ra;
		copy->ra = copy->ra - rr;
		copy->rb = copy->rb - rr;
	}
	while (rr-- > 0)
	{
		exucute_rr(stc);
		ft_putstr("rr\n");
	}
}

void			ft_sol_rrr(t_stack *copy, t_base *stc)
{
	int			rrr;

	if (copy->rra > copy->rrb)
	{
		rrr = copy->rrb;
		copy->rra = copy->rra - rrr;
		copy->rrb = copy->rrb - rrr;
	}
	else
	{
		rrr = copy->rra;
		copy->rra = copy->rra - rrr;
		copy->rrb = copy->rrb - rrr;
	}
	while (rrr-- > 0)
	{
		exucute_rrr(stc);
		ft_putstr("rrr\n");
	}
}

void			ft_solution_rarb(t_base *stc, int min)
{
	t_stack		*copy;

	copy = stc->b;
	while (copy->max_r != min)
		copy = copy->next;
	if (copy->ra > 0 && copy->rb > 0)
		ft_sol_rr(copy, stc);
	while (copy->ra-- > 0)
	{
		exucute_ra(stc);
		ft_putstr("ra\n");
	}
	while (copy->rb-- > 0)
	{
		exucute_rb(stc);
		ft_putstr("rb\n");
	}
	exucute_pa(stc);
	ft_putstr("pa\n");
}

void			ft_solution_rrarrb(t_base *stc, int min)
{
	t_stack		*copy;

	copy = stc->b;
	while (copy->max_rr != min)
		copy = copy->next;
	if (copy->rra > 0 && copy->rrb > 0)
		ft_sol_rrr(copy, stc);
	while (copy->rra-- > 0)
	{
		exucute_rra(stc);
		ft_putstr("rra\n");
	}
	while (copy->rrb-- > 0)
	{
		exucute_rrb(stc);
		ft_putstr("rrb\n");
	}
	exucute_pa(stc);
	ft_putstr("pa\n");
}
