/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toto <toto@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:06:43 by tle-saut          #+#    #+#             */
/*   Updated: 2025/02/03 16:20:21 by toto             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(p_swap **lst)
{
    p_swap *temp;

    if (*lst == NULL || (*lst)->chain == NULL)
        return;

    temp = (*lst)->chain;   // temp devient le second élément
    if ((*lst)->chain != NULL)
        (*lst)->chain->chain = temp->chain;  // Le premier élément pointe vers le troisième
    temp->chain = *lst;     // Le second élément pointe vers le premier
    *lst = temp;            // Mise à jour de la tête de liste
}




//switch 1-2 lista
void    sa(t_all *all)
{
    swap(&all->lsta);
    ft_printf("sa\n");
}

//switch 1-2 listb
void    sb(t_all *all)
{
    swap(&all->lstb);
    ft_printf("sb\n");
}

//switch 1-2 lista & listb
void    ss(t_all *all)
{
    swap(&all->lsta);
    swap(&all->lstb);
    ft_printf("ss\n");
}
