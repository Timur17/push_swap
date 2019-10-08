/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_less_5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:43:47 by wtorwold          #+#    #+#             */
/*   Updated: 2019/10/08 15:16:27 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//void	ft_ra(t_base	*stc)
//{

//}

//void	ft_sort_help(t_base *stc)
//{
//}


//void ft_add2_ra(t_base *stc)
//{

//}

void    ft_sort_less_5(t_base *stc, int av)
{
	t_stack     *copy;
	int			len;
	int			l;
	
	copy = stc->a;
	l = len = ft_len(stc->a);
//	printf("av %d\n", av);
	while(len-- > 0)
	{
		copy = stc->a;
		if (copy->value >= av)
		{
			exucute_ra(stc);
			ft_putstr("ra\n");
		}
		else
		{
			exucute_pb(stc);
			ft_putstr("pb\n");
		}
	}
	ft_sort_three(stc);
	if (l == 5)
		if (stc->b->value < stc->b->next->value)
		{
			exucute_sb(stc);
			ft_putstr("sb\n");
		}
	while(stc->b)
	{
		exucute_pa(stc);
		ft_putstr("pa\n");
	}
//	ft_add2_ra(stc);
//	while(stc->b)
//		ft_sort_help(stc);
}
