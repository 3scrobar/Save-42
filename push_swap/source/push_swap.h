/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:55:42 by tle-saut          #+#    #+#             */
/*   Updated: 2025/01/28 13:49:06 by tle-saut         ###   ########.fr       */
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
/*------------------------------UTILS----------------------------------------*/
int			check_args(char **str, p_swap **lst);
long int	atoi_long(const char *nptr);
int			lstcomp(p_swap *lst, int nbr);
int			ft_printfnumb_nl(int n);
/*------------------------------SWAP----------------------------------------*/
void    	swap(p_swap **lst);
void		sa(t_all *all);
void		sb(t_all *all);
void		ss(t_all *all);
/*------------------------------PUSH----------------------------------------*/
void    	push(p_swap **lst1, p_swap **lst2);
void		pa(t_all *all);
void		pb(t_all *all);
void		pp(t_all *all);

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
