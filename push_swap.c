/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:09:43 by wtorwold          #+#    #+#             */
/*   Updated: 2019/10/16 15:34:04 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void					ft_sort3(t_base *stc)
{
	t_stack				*copy;
	t_stack				*copy_a;

	copy_a = stc->a;
	copy = stc->b;
	while (stc->b)
	{
		ft_bzero_stc(stc->b);
		ft_add_rb(stc);
		ft_add_ra(stc);
		ft_add_rra(stc);
		ft_solution(stc);
	}
}

void					ft_solution(t_base *stc)
{
	int					min_r;
	int					min_rr;
	t_stack				*copy;

	copy = stc->b;
	min_r = ft_max_r(stc);
	min_rr = ft_max_rr(stc);
	if (min_r > min_rr)
		ft_solution_rrarrb(stc, min_rr);
	else
		ft_solution_rarb(stc, min_r);
}

void					ft_sort(t_base *stc)
{
	int					len;
	int					min;
	int					max;
	int					av;

	max = ft_max(stc->a);
	min = ft_min(stc->a);
	av = ft_average(stc);
	len = ft_len(stc->a);
	if (len > 3 && len <= 5)
	{
		ft_sort_less_5(stc, av);
		return ;
	}
	if (len == 2)
	{
		ft_sort_two(stc);
		return ;
	}
	ft_sort2(stc, max, min, av);
	ft_sort_three(stc);
	ft_sort3(stc);
	ft_sort4(stc, min, len);
}

int						main(int ac, char **av)
{
	t_base				stc;

	if (ac < 2 || ft_check_v(av, ac) == 0)
		return (0);
	if (ft_valid1(av, ac) == 0)
	{
		ft_putstr("Error\n");
		return (1);
	}
	stc.a = fill_stack(ac, av, &stc);
	if (ft_valid2(stc.a) == 0)
	{
		ft_putstr("Error\n");
		ft_free(&stc);
		return (1);
	}
	if (check_sort(&stc) == 0)
		ft_sort(&stc);
	ft_free(&stc);
}
