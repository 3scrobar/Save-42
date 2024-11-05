/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:30:02 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/05 17:33:31 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	const char	*ptr1;
	const char	*ptr2;

	ptr1 = s1;
	ptr2 = s2;
	i = 0;
	if (n == 0)
		return (0);
	while (ptr1[i] && i <= n)
		i++;
	return (ptr1[i] - ptr2[i]);
}
