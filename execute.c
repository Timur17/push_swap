/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:09:43 by wtorwold          #+#    #+#             */
/*   Updated: 2019/10/16 13:16:21 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int						exucute_sa(t_base *stc)
{
	int					temp;

	if (stc->a == NULL || stc->a->next == NULL)
	{
		if (stc->status == 1)
			ft_print(stc);
		return (1);
	}
	temp = stc->a->value;
	stc->a->value = stc->a->next->value;
	stc->a->next->value = temp;
	if (stc->status == 1)
		ft_print(stc);
	return (1);
}

int						exucute_rb(t_base *stc)
{
	int					temp;
	t_stack				*help;

	if (stc->b == NULL)
	{
		if (stc->status == 1)
			ft_print(stc);
		return (1);
	}
	help = stc->b;
	temp = help->value;
	while (help)
	{
		if (help->next != NULL)
			help->value = help->next->value;
		if (help->next == NULL)
			break ;
		help = help->next;
	}
	help->value = temp;
	if (stc->status == 1)
		ft_print(stc);
	return (1);
}

int						exucute_ra(t_base *stc)
{
	int					temp;
	t_stack				*help;

	if (stc->a == NULL)
	{
		if (stc->status == 1)
			ft_print(stc);
		return (1);
	}
	help = stc->a;
	temp = help->value;
	while (help)
	{
		if (help->next != NULL)
			help->value = help->next->value;
		if (help->next == NULL)
			break ;
		help = help->next;
	}
	help->value = temp;
	if (stc->status == 1)
		ft_print(stc);
	return (1);
}

int						exucute_rra(t_base *stc)
{
	int					temp;
	int					tt;
	t_stack				*help;
	t_stack				*copy;

	if (stc->a == NULL)
		return (1);
	help = stc->a;
	copy = help;
	temp = help->value;
	while (help)
	{
		if (help->next != NULL)
		{
			tt = help->next->value;
			help->next->value = temp;
			temp = tt;
		}
		if (help->next == NULL)
			break ;
		help = help->next;
	}
	copy->value = temp;
	stc->status == 1 ? ft_print(stc) : 0;
	return (1);
}

int						exucute_rrb(t_base *stc)
{
	int					temp;
	int					tt;
	t_stack				*help;
	t_stack				*copy;

	if (stc->b == NULL)
		return (1);
	help = stc->b;
	copy = help;
	temp = help->value;
	while (help)
	{
		if (help->next != NULL)
		{
			tt = help->next->value;
			help->next->value = temp;
			temp = tt;
		}
		if (help->next == NULL)
			break ;
		help = help->next;
	}
	copy->value = temp;
	stc->status == 1 ? ft_print(stc) : 0;
	return (1);
}
