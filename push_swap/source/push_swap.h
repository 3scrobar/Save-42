/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:55:42 by tle-saut          #+#    #+#             */
/*   Updated: 2025/01/27 18:40:28 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/source/libft.h"
# include <limits.h>
/*******************************STRUCTURE*************************************/

typedef struct p_ush
{
	int				value;
	struct p_ush	*chain;
}					p_swap;

/*******************************FUNCTION**************************************/

int	lstsize(p_swap *lst);
p_swap	*lstnew(int value);
p_swap	*lstmap(p_swap *lst, int (*f)(int), void (*del)(int), void (*delv)(void *));
void	lstiter(p_swap *lst, int (*f)(int));
void	lstdelone(p_swap *lst, void (*del)(int));
void	lstclear(p_swap **lst, void (*del)(int));
void	lstadd_front(p_swap **lst, p_swap *new);
void	lstadd_back(p_swap **lst, p_swap *new);
int		check_args(char *str, p_swap *lst);
long int	atoi_long(const char *nptr);
int	lstcomp(p_swap *lst, int nbr);
void	ra(p_swap **lst);

#endif
