/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:09:43 by wtorwold          #+#    #+#             */
/*   Updated: 2019/10/15 14:53:35 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int						exucute_pb(t_base *stc)
{
	t_stack				*list;
	t_stack				*new;

	if (stc->a == NULL)
		return (1);
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
	if (stc->status == 1)
		ft_print(stc);
	return (1);
}
