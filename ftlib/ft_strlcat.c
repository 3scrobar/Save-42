/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:25:29 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/06 11:45:41 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	c;
	size_t	initsrc;

	i = 0;
	c = ft_strlen(dst);
	initsrc = ft_strlen(src);
	while (i <= size - 1 && src[i])
	{
		dst[c + i] = src[i];
		i++;
	}
	if (initsrc < size)
		dst[c + i] = 0;
	return (initsrc + c);
}
int	main(void)
{
	char *dest;
	
	dest[10] = 'a';
    ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 1));
    write(1, "\n", 1);
    write(1, dest, 15);

}
