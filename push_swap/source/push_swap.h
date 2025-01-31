/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:55:42 by tle-saut          #+#    #+#             */
/*   Updated: 2025/01/31 13:56:14 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
/*****************************************************************************/
/*******************************INCLUDE***************************************/
/*****************************************************************************/
# include "../libft/source/libft.h"
# include <limits.h>
/*****************************************************************************/
/*******************************STRUCTURE*************************************/
/*****************************************************************************/

typedef struct p_ush
{
	int				value;
	struct p_ush	*chain;
}					p_swap;

typedef struct s_all
{
	p_swap	*lsta;
	p_swap	*lstb;
	int		counta;
    int		countb;
	int		mina;
	int		maxa;
	int		minb;
	int		maxb;
    int     sorted;
	int		first;
}				t_all;
/*****************************************************************************/
/*******************************FUNCTION**************************************/
/*****************************************************************************/
/*------------------------------LISTE----------------------------------------*/
int			lstsize(p_swap *lst);
p_swap		*lstnew(int value);
p_swap		*lstmap(p_swap *lst, int (*f)(int), void (*del)(int), void (*delv)(void *));
void		lstiter(p_swap *lst, int (*f)(int));
void		lstdelone(p_swap *lst, void (*del)(int));
void		lstclear(p_swap **lst, void (*del)(int));
void		lstadd_front(p_swap **lst, p_swap *new);
void		lstadd_back(p_swap **lst, p_swap *new);
int         lst_givelast(p_swap *lst);

/*------------------------------UTILS----------------------------------------*/
long int	atoi_long(const char *nptr, int j);
int			lstcomp(p_swap *lst, int nbr);
int			ft_printfnumb_nl(int n);
void		print_lst(t_all *all);
void	    count_all(t_all *all);
void    	push_lstb(t_all *all);
/*------------------------------CHECK----------------------------------------*/
int			check_sorted(t_all *all);
int		    count_all_lsta(t_all *all, int a);
int         count_all_lstb(t_all *all, int a);
int			check_args(char **str, p_swap **lst, int ac);
int		    while_check_args(p_swap **lst, int i, char **str);
int         while_check_args_string(p_swap **lst, int i, int j, char **str);
int         is_valid_args(char *str);

/*------------------------------ALGO----------------------------------------*/
int			check_sort(t_all *all);
int			check_list_sort(p_swap *lst);
void		sort_two(t_all *all);
void		sort_three(p_swap *lst, t_all *all);
void        sort_multiple(t_all *all);
void    	sort_three_reverse(p_swap *lst, t_all *all);
int			check_list_sort_reverse(p_swap *lst);

/*------------------------------SWAP----------------------------------------*/
void    	swap(p_swap **lst);
void		sa(t_all *all);
void		sb(t_all *all);
void		ss(t_all *all);
/*------------------------------PUSH----------------------------------------*/
void    	push(p_swap **lst1, p_swap **lst2);
void		pa(t_all *all);
void		pb(t_all *all);

/*------------------------------ROTATE--------------------------------------*/
void		rotate(p_swap **lst);
void		ra(t_all *all);
void		rb(t_all *all);
void		rr(t_all *all);

/*-----------------------------REVERSE_ROTATE-------------------------------*/
void    	reverse_rotate(p_swap **lst);
void		rra(t_all *all);
void		rrb(t_all *all);
void		rrr(t_all *all);


#endif
