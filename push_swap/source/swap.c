/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:06:43 by tle-saut          #+#    #+#             */
/*   Updated: 2025/01/29 13:40:39 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap(p_swap **lst)
{
    p_swap *temp;

    if (*lst == NULL || (*lst)->chain == NULL)
        return ;
    temp = *lst;
    *lst = (*lst)->chain;
    temp->chain = (*lst)->chain;
    (*lst)->chain = temp;
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
