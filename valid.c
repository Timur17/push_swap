/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:09:43 by wtorwold          #+#    #+#             */
/*   Updated: 2019/09/18 19:40:31 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_valid(char *line, t_base *stc)
{
	if (ft_strcmp(line, "sa") == 0)
		return(exucute_sa(stc));
	else if (ft_strcmp(line, "ra") == 0)
		return(exucute_ra(stc));
	else if (ft_strcmp(line, "rra") == 0)
		return(exucute_rra(stc));
	else if (ft_strcmp(line, "pb") == 0)
		return(exucute_pb(stc));
	else if (ft_strcmp(line, "sb") == 0)
		return(exucute_sb(stc));
	else if (ft_strcmp(line, "pa") == 0)
		return(exucute_pa(stc));
	else if (ft_strcmp(line, "rb") == 0)
		return(exucute_rb(stc));
	else if (ft_strcmp(line, "rrb") == 0)
		return(exucute_rrb(stc));
	else if (ft_strcmp(line, "rr") == 0)
		return(exucute_rr(stc));
	else if (ft_strcmp(line, "rrr") == 0) 
		return(exucute_rrr(stc));
	else if (ft_strcmp(line, "ss") == 0)
		return(exucute_ss(stc)); 
	return(0);
}

int		ft_valid1(char **av, int ac)
{
	int i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while(av[i][j] != '\0')
		{
			if(av[i][j] < '0' || av[i][j] > '9') 
				  return(0);
			j++;	  
		}
		i++;
	}
	return(1);
}

int     ft_valid2(t_stack *a)
{
	t_stack *temp;
	t_stack *copy;
	int		num;
	int		i;

	temp = a;
	while(temp)
	{
		i = 0;
		copy = a;
		num = temp->value;
		while(copy)
		{
			if (num == copy->value)
				i++;
			copy = copy->next;
		}
		if (i > 1)
			return (0);
		temp = temp->next;
	}
	return (1);
}
