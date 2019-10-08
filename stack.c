/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:09:43 by wtorwold          #+#    #+#             */
/*   Updated: 2019/10/08 13:47:43 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack				*fill_stack(int ac, char **av)
{
	int		i;
	t_stack *temp;
	t_stack *test;
	t_stack	*copy;

	i = 1;
	test = (t_stack *)malloc(sizeof(t_stack));
	test->next = NULL;
	temp = test;
	while(ac > i)
	{
		if (temp->next != NULL)
			temp = temp->next;
		temp->value = ft_atoi(av[i]);
//		temp->m = 0;
//		printf("value t %d\n", temp->value);
		copy = (t_stack *)malloc(sizeof(t_stack));
		temp->next = copy;
		i++;
	}
	free(copy);
	temp->next = NULL;
	return(test);
}
