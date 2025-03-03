/* ************************************************************************** */
/*	*/
/*	:::	  ::::::::   */
/*   push_swap.h	:+:	  :+:	:+:   */
/*	+:+ +:+	 +:+	 */
/*   By: toto <toto@student.42.fr>	  +#+  +:+	   +#+	*/
/*	+#+#+#+#+#+   +#+	   */
/*   Created: 2025/01/24 14:55:42 by tle-saut	  #+#	#+#	 */
/*   Updated: 2025/02/04 17:18:33 by toto	 ###   ########.fr	   */
/*	*/
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
/*****************************************************************************/
/*******************************INCLUDE***************************************/
/*****************************************************************************/
# include "../libft/source/libft.h"
# include <limits.h>
# include <stdio.h>
/*****************************************************************************/
/*******************************STRUCTURE*************************************/
/*****************************************************************************/

typedef struct s_ush
{
	int				value;
	struct s_ush	*chain;
}					t_swap;

typedef struct s_all
{
	t_swap	*lsta;
	t_swap	*lstb;
	int		counta;
	int		countb;
	int		mina;
	int		maxa;
	int		minb;
	int		maxb;
	int		range;
	int		first;
	int		mintot;
	int		maxtot;
	int		i;

}				t_all;
/*****************************************************************************/
/*******************************FUNCTION**************************************/
/*****************************************************************************/
/*------------------------------LIST-----------------------------------------*/
int			lstsize(t_swap *lst);
t_swap		*lstnew(int value);
int			lstcomp(t_swap *lst, int nbr);
t_swap		*lstlast(t_swap *lst);
void		lstiter(t_swap *lst, int (*f)(int));
void		lstdelone(t_swap *lst, void (*del)(int));
void		lstclear(t_swap *lst);
void		lstadd_front(t_swap **lst, t_swap *new);
void		lstadd_back(t_swap **lst, t_swap *new);
int			lst_givelast(t_swap *lst);
int			lst_give_bef_last(t_swap *lst);

/*------------------------------UTILS----------------------------------------*/
long int	atoi_long(const char *nptr, int j);
int			ft_printfnumb_nl(int n);
void		print_lst(t_all *all);
void		push_back_a(t_all *all);

/*------------------------------SORT-----------------------------------------*/
void		sort_three_lsta(t_all *all);
void		sort_three_lstb(t_all *all);
void		sort_two(t_all *lst);
int			get_index_b(t_all *all, int i);
void		rotate_b(t_all *all);
int			between_b(t_all *all, int i);
void		move_tier_1(t_all *all);
void		move_tier_2(t_all *all);
void		move_tier_3(t_all *all);
void		if_push_back_a(int firsta, int firstb, int lasta, t_all *all);
void		else_if_pba(t_all *all);
void		if_2_push_back_a(t_all *all);

/*------------------------------ALGO-----------------------------------------*/
void		algo(t_all *all);
void		push_b(t_all *all);
void		sort_more(t_all *all);
int			get_between(t_all *all, int i);
void		mv_index(t_all *all, int i);
int			get_index(t_all *all, int i);
int			first_tier(t_all *all, int i);
int			second_tier(t_all *all, int i);
int			third_tier(t_all *all, int i);
int			check_tier(t_all *all);
int			get_clockwise(t_all *all, int i);

/*------------------------------PUSH-----------------------------------------*/
void		push(t_swap **lst1, t_swap **lst2);
void		pa(t_all *all);
void		pb(t_all *all);
/*---------------------------REVERSE_ROTATE----------------------------------*/
void		reverse_rotate(t_swap **lst);
void		rra(t_all *all);
void		rrb(t_all *all);
void		rrr(t_all *all);
/*---------------------------ROTATE------------------------------------------*/
void		rotate(t_swap **lst);
void		ra(t_all *all);
void		rb(t_all *all);
void		rr(t_all *all);
/*---------------------------SWAP--------------------------------------------*/
void		swap(t_swap **lst);
void		sa(t_all *all);
void		sb(t_all *all);
void		ss(t_all *all);
/*---------------------------CHECK-------------------------------------------*/
int			count_all_lsta(t_all *all, int a);
int			count_all_lstb(t_all *all, int a);
int			check_args(char **str, t_swap **lst, int ac);
int			while_check_args_string(t_swap **lst, int i, int j, char **str);
int			while_check_args(t_swap **lst, int i, char **str);
int			is_valid_args(char *str);
int			check_list_sort(t_swap *lst);
int			check_list_sort_reverse(t_swap *lst);
void		count_all(t_all *all, int i);
int			check_sorted_lsta(t_all *all);
int			check_sorted_lstb(t_all *all);

#endif
