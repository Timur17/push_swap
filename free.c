/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:09:43 by wtorwold          #+#    #+#             */
/*   Updated: 2019/10/10 21:10:47 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_base *stc)
{
	t_stack			*temp;

	temp = stc->a;
	while (temp)
	{
		temp = temp->next;
		free(stc->a);
		stc->a = temp;
	}
	temp = stc->b;
	while (temp)
	{
		temp = temp->next;
		free(stc->b);
		stc->b = temp;
	}
}
