/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:09:43 by wtorwold          #+#    #+#             */
/*   Updated: 2019/09/26 19:36:08 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*int		check_sort(t_base *stc)
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
}*/

int		main(int ac, char **av)
{
	t_base		stc;
	char		*line;

	if(ac < 2)
		return(0);
	if (ft_valid1(av, ac) == 0)
	{
		ft_putstr("Error\n");
		return (1);
	}
	stc.a = fill_stack(ac, av);
	if (ft_valid2(stc.a) == 0)
	{
		ft_putstr("Error\n");
		return (1);
	}
	while(get_next_line(0, &line)>0)
	{
		if(check_valid(line, &stc) == 0)
		{
			ft_putstr("Error\n");
			return(0);
		}
		free(line);
	}
	if (check_sort(&stc))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
//	if (stc.a == NULL)
//		printf("1 NULL\n");
/*	while (stc.a)
	{
		printf("value a = %d\n", stc.a->value);
		stc.a = stc.a->next;
	}
	while (stc.b)
	{
		printf("value b = %d\n", stc.b->value);
		stc.b = stc.b->next;
	}*/
	ft_free(&stc);
}
