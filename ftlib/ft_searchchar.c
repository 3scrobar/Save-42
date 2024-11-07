/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_searchchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:41:25 by root              #+#    #+#             */
/*   Updated: 2024/11/07 20:44:56 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_searchchar(char c, char *str)
{
    int i;
    int yes;

    i = 0;
    yes = 0;

    while (str[i])
    {
        if (str[i] == c)
            yes = 1;
        i++;
    }
    return (yes);
}