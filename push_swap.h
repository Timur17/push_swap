/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:45:52 by wtorwold          #+#    #+#             */
/*   Updated: 2019/10/16 15:47:45 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "get_next_line.h"
# include <stdlib.h>

typedef struct		s_stack
{
	int				value;
	struct s_stack	*next;
	int				rb;
	int				rrb;
	int				ra;
	int				rra;
	int				rr;
	int				rrr;
	int				max_r;
	int				max_rr;
}					t_stack;
typedef struct		s_stacks
{
	t_stack			*a;
	t_stack			*b;
	int				status;
}					t_base;

int					ft_valid1(char **av, int ac);
int					ft_valid2(t_stack *a);
int					ft_valid3(char *str);
t_stack				*fill_stack(int ac, char **av, t_base *stc);
void				ft_free(t_base *stc);
int					exucute_sa(t_base *stc);
int					exucute_rb(t_base *stc);
int					exucute_ra(t_base *stc);
int					exucute_rra(t_base *stc);
int					exucute_rr(t_base *stc);
int					exucute_rrb(t_base *stc);
int					exucute_rrr(t_base *stc);
int					exucute_ss(t_base *stc);
int					exucute_pb(t_base *stc);
int					exucute_pb(t_base *stc);
int					exucute_sb(t_base *stc);
int					exucute_pa(t_base *stc);
int					check_valid(char *line, t_base *stc);
int					ft_valid1(char **av, int ac);
int					ft_valid2(t_stack *a);
void				ft_free(t_base *stc);
int					check_sort(t_base *stc);
void				ft_sort_less_5(t_base *stc, int av);
int					ft_len(t_stack *a);
void				ft_sort_three(t_base *stc);
int					ft_min(t_stack *a);
void				ft_sort4(t_base *stc, int min, int len);
int					ft_max(t_stack *a);
int					*ft_mas(t_stack *a, int len);
void				ft_swap(int *tab, int i);
void				ft_sort4(t_base *stc, int min, int len);
void				ft_sort_two(t_base *stc);
int					ft_help_av(int len, int *tab);
int					ft_average(t_base *stc);
void				ft_add_rrb(int len1, int len, t_base *stc);
void				ft_add_rb(t_base *stc);
void				ft_add_rra(t_base *stc);
void				ft_add_ra(t_base *stc);
void				ft_solution(t_base *stc);
void				ft_solution_rrarrb(t_base *stc, int min);
void				ft_solution_rarb(t_base *stc, int min);
void				ft_sol_rrr(t_stack *copy, t_base *stc);
void				ft_sol_rr(t_stack *copy, t_base *stc);
int					ft_max_rr(t_base *stc);
int					ft_max_r(t_base *stc);
void				ft_solution(t_base *stc);
void				ft_bzero_stc(t_stack *copy);
void				ft_sort2(t_base *stc, int max, int min, int av);
void				ft_sort3(t_base *stc);
void				ft_print(t_base *stc);
void				exucute_sa_rra(t_base *stc);
void				exucute_sa_ra(t_base *stc);
void				exucute_sa_print(t_base *stc);
int					ft_check_v(char **av, int ac);
#endif
