/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:38:30 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/09 14:48:12 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_itoa(int n)
{
	char	*str;
	int	

	if (n ==-2147483648 )
		str = "-2147483648";
	 if (n == 0)
	 {
		str[i++] = '0';
		str[i] = '\0';
		return;
	}
	if (n < 0) {
		isNegative = 1;
		n = -n;
	}
	if (isNegative)
		str[i++] = '-';
	int start = 0;
	int end = i - 1;
	while (start < end)
	{
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
}
