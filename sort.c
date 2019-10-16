/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:09:43 by wtorwold          #+#    #+#             */
/*   Updated: 2019/10/15 14:01:33 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_swap(int *tab, int i)
{
	int			temp;

	temp = tab[i];
	tab[i] = tab[i + 1];
	tab[i + 1] = temp;
}

int				ft_help_av(int len, int *tab)
{
	int			av;

	if (len % 2 == 0)
	{
		len = len / 2;
		len--;
		av = (tab[len]);
		free(tab);
		return (av);
	}
	else
	{
		len = (len - 1) / 2;
		len--;
		av = (tab[len + 1]);
		free(tab);
		return (av);
	}
}

int				ft_average(t_base *stc)
{
	int			len;
	int			*tab;
	int			i;

	i = 0;
	len = ft_len(stc->a);
	tab = ft_mas(stc->a, len);
	while (len > i + 1)
	{
		if (tab[i] > tab[i + 1])
		{
			ft_swap(tab, i);
			if (i - 1 >= 0)
				i--;
			else
				i = 0;
		}
		else
			i++;
	}
	i = 0;
	return (ft_help_av(len, tab));
}

void			ft_sort_two(t_base *stc)
{
	int			first;
	int			second;

	first = stc->a->value;
	second = stc->a->next->value;
	if (first > second)
	{
		exucute_ra(stc);
		ft_putstr("ra\n");
	}
}

void			ft_sort4(t_base *stc, int min, int len)
{
	t_stack		*copy;
	int			i;

	i = 0;
	copy = stc->a;
	while (copy->value != min)
	{
		copy = copy->next;
		i++;
	}
	if (i < (len / 2) + 1)
		while (stc->a->value != min)
		{
			exucute_ra(stc);
			ft_putstr("ra\n");
		}
	else
		while (stc->a->value != min)
		{
			exucute_rra(stc);
			ft_putstr("rra\n");
		}
}
