/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:09:43 by wtorwold          #+#    #+#             */
/*   Updated: 2019/09/29 19:00:17 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					exucute_sa(t_base *stc)
{
	int temp;

	if (stc->a == NULL || stc->a->next == NULL)
		return(1);
	temp = stc->a->value;
	stc->a->value = stc->a->next->value;
	stc->a->next->value = temp;
	return(1);
}

int    exucute_rb(t_base *stc)
{
	int temp;
	t_stack *help;

	if (stc->b == NULL)
		return(1);
	help = stc->b;
	temp = help->value;
	while(help)
	{
		if (help->next != NULL)
//	t_stack     *copy;
			help->value = help->next->value;
		if (help->next == NULL)
			break ;
		help = help->next;
	}
	help->value = temp;
	return(1);
}

int    exucute_ra(t_base *stc)
{
	int temp;
	t_stack *help;

	if (stc->a == NULL)
		return(1);
	help = stc->a;
	temp = help->value;
	while(help)
	{
		if (help->next != NULL)
			help->value = help->next->value;
		if (help->next == NULL)
			break ;
		help = help->next;
	}
	help->value = temp;
	return(1);
}

int    exucute_rra(t_base *stc)
{
	int temp;
	int tt;
	t_stack *help;
	t_stack *copy;

	if(stc->a == NULL)
		return(1);
	help = stc->a;
	copy = help;
	temp = help->value;
	while(help)
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
	return(1);
}

int    exucute_rrb(t_base *stc)
{
	int temp;
	int tt;
	t_stack *help;
	t_stack *copy;

	if(stc->b == NULL)
		return(1);
	help = stc->b;
	copy = help;
	temp = help->value;
	while(help)
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
	return(1);
}

int    exucute_pb(t_base *stc)
{
	t_stack *list;
	t_stack *new;

	if (stc->a == NULL)
		return(1);
	new = (t_stack *)malloc(sizeof(t_stack));
	new->value = stc->a->value;
	new->next = NULL;
	if (stc->b == NULL)
		stc->b = new;
	else
	{
		new->next = stc->b;
		stc->b = new;
	}
	list = stc->a->next;
	free(stc->a);
	stc->a = NULL;
	stc->a = list;
//	if (stc->a == NULL)
//		printf("NULL\n");
//	printf("test %p\n", stc->a); если все элементы передам в стэк б и выполню sa то сегается
	return(1);
}

int    exucute_sb(t_base *stc)
{
	int temp;

	if (stc->b == NULL || stc->b->next == NULL)
		return(1);
	temp = stc->b->value;
	stc->b->value = stc->b->next->value;
	stc->b->next->value = temp;
	return(1);
}

int    exucute_pa(t_base *stc)
{
	t_stack *new;
	t_stack *list;

	if (stc->b == NULL)
		return(1);
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
	return(1);
}

int    exucute_rr(t_base *stc)
{
	exucute_ra(stc);
	exucute_rb(stc);
	return(1);
}

int    exucute_rrr(t_base *stc)
{
	exucute_rra(stc);
	exucute_rrb(stc);
	return(1);
}

int    exucute_ss(t_base *stc)
{
	exucute_sa(stc);
	exucute_sb(stc);
	return(1);
}
