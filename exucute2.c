/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:09:43 by wtorwold          #+#    #+#             */
/*   Updated: 2019/10/15 14:28:40 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			exucute_sa_rra(t_base *stc)
{
	exucute_sa(stc);
	ft_putstr("sa\n");
	exucute_rra(stc);
	ft_putstr("rra\n");
}

void			exucute_sa_ra(t_base *stc)
{
	exucute_sa(stc);
	ft_putstr("sa\n");
	exucute_ra(stc);
	ft_putstr("ra\n");
}

void			exucute_sa_print(t_base *stc)
{
	exucute_sa(stc);
	ft_putstr("sa\n");
}
