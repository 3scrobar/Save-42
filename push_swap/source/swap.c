/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:06:43 by tle-saut          #+#    #+#             */
/*   Updated: 2025/01/28 22:59:00 by tle-saut         ###   ########.fr       */
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

void    sa(t_all *all)
{
    swap(&all->lsta);
    ft_printf("sa\n");
}

void    sb(t_all *all)
{
    swap(&all->lstb);
    ft_printf("sb\n");
}

void    ss(t_all *all)
{
    swap(&all->lsta);
    swap(&all->lstb);
    ft_printf("ss\n");
}
