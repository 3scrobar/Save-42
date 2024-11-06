/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:23:28 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/06 14:21:40 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_calloc(size_t nmemb, size_t size)
{
    void *ptr;
    size_t total_size;


    if (nmemb == 0 || size == 0)
        return (NULL);
    total_size = nmemb * size;
    ptr = malloc(total_size);
    if (ptr == NULL)
        return (NULL);
    ft_memset(ptr, 0, total_size);
    return (ptr);
}

