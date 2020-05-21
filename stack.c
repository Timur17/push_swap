/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:09:43 by wtorwold          #+#    #+#             */
/*   Updated: 2019/10/16 15:36:19 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					fill_status(char **av, t_base *stc)
{
	int				i;

	if (av[1][0] == '-' && av[1][1] == 'v')
	{
		stc->status = 1;
		i = 2;
	}
	else
	{
		stc->status = 0;
		i = 1;
	}
	return (i);
}

t_stack				*fill_stack(int ac, char **av, t_base *stc)
{
	int				i;
	t_stack			*temp;
	t_stack			*test;
	t_stack			*copy;

	i = fill_status(av, stc);
	test = (t_stack *)malloc(sizeof(t_stack));
	test->next = NULL;
	temp = test;
	while (ac > i)
	{
		if (temp->next != NULL)
			temp = temp->next;
		temp->value = ft_atoi(av[i]);
		copy = (t_stack *)malloc(sizeof(t_stack));
		temp->next = copy;
		i++;
	}
	free(copy);
	temp->next = NULL;
	stc->b = NULL;
	return (test);
}
