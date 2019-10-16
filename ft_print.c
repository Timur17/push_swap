/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:09:43 by wtorwold          #+#    #+#             */
/*   Updated: 2019/10/15 13:13:28 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void					ft_print(t_base *stc)
{
	t_stack				*copy_a;
	t_stack				*copy_b;
	char				n;

	copy_a = stc->a;
	copy_b = stc->b;
	n = '\n';
	ft_putstr("STACK A   STACK B");
	ft_putchar(n);
	while (copy_a || copy_b)
	{
		if (copy_a)
		{
			ft_putnbr(copy_a->value);
			copy_a = copy_a->next;
		}
		ft_putstr("           ");
		if (copy_b)
		{
			ft_putnbr(copy_b->value);
			copy_b = copy_b->next;
		}
		ft_putchar(n);
	}
}
