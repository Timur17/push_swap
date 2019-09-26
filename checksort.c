/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:09:43 by wtorwold          #+#    #+#             */
/*   Updated: 2019/09/26 17:46:40 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_sort(t_base *stc)
{
	t_stack		*temp;

	if (stc->b != NULL)
		return(0);
	if (stc->a == NULL)
		return(0);
	temp = stc->a;
	while(temp)
	{
		if(temp->next)
			if(temp->value > temp->next->value)
				return(0);
		temp = temp->next;
	}
	return(1);
}
