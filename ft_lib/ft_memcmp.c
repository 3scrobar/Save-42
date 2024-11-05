/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:30:02 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/04 16:35:06 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int memcmp(const void *s1, const void *s2, size_t n)
{
	int i;
	char *ptr1;
	char *ptr2;

	ptr1 = s1;
	ptr2 = s2;
	i = 0;
	if(n == 0)
		return (0);
	while(ptr1[i] && i <= n)
		i++;
	return (ptr1[i] - ptr2[i]);
}
