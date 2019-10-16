/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:09:43 by wtorwold          #+#    #+#             */
/*   Updated: 2019/10/15 14:50:20 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int						exucute_sb(t_base *stc)
{
	int					temp;

	if (stc->b == NULL || stc->b->next == NULL)
		return (1);
	temp = stc->b->value;
	stc->b->value = stc->b->next->value;
	stc->b->next->value = temp;
	if (stc->status == 1)
		ft_print(stc);
	return (1);
}

int						exucute_pa(t_base *stc)
{
	t_stack				*new;
	t_stack				*list;

	if (stc->b == NULL)
		return (1);
	new = (t_stack *)malloc(sizeof(t_stack));
	new->value = stc->b->value;
	new->next = NULL;
	if (stc->a == NULL)
		stc->a = new;
	else
	{
		new->next = stc->a;
		stc->a = new;
	}
	list = stc->b->next;
	free(stc->b);
	stc->b = list;
	if (stc->status == 1)
		ft_print(stc);
	return (1);
}

int						exucute_rr(t_base *stc)
{
	exucute_ra(stc);
	exucute_rb(stc);
	return (1);
}

int						exucute_rrr(t_base *stc)
{
	exucute_rra(stc);
	exucute_rrb(stc);
	return (1);
}

int						exucute_ss(t_base *stc)
{
	exucute_sa(stc);
	exucute_sb(stc);
	return (1);
}
