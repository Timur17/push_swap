/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:09:43 by wtorwold          #+#    #+#             */
/*   Updated: 2019/09/18 19:48:37 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_base *stc)
{
	t_stack     *temp;

	temp = stc->a;
	while(temp)
	{
		free(stc->a);
		temp = temp->next;
		stc->a = temp;
	}
	temp = stc->b;
	while(temp)
	{
		free(stc->b);
		temp = temp->next;
		stc->b = temp;
	}
}
