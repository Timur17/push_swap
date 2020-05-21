/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:09:43 by wtorwold          #+#    #+#             */
/*   Updated: 2019/10/16 15:54:22 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_help(char *line, t_base *stc)
{
	if (check_valid(line, stc) == 0)
	{
		ft_putstr("Error\n");
		ft_free(stc);
		free(line);
		return (0);
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_base		stc;
	char		*line;

	if (ac < 2)
		return (0);
	if (ft_valid1(av, ac) == 0)
	{
		ft_putstr("Error\n");
		return (0);
	}
	stc.a = fill_stack(ac, av, &stc);
	if (ft_valid2(stc.a) == 0)
	{
		ft_putstr("Error\n");
		ft_free(&stc);
		return (0);
	}
	while (get_next_line(0, &line) > 0)
	{
		if (ft_help(line, &stc) == 0)
			return (0);
		free(line);
	}
	check_sort(&stc) != 0 ? ft_putstr("OK\n") : ft_putstr("KO\n");
	ft_free(&stc);
}
