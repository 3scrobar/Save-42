/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_searchchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:41:25 by root              #+#    #+#             */
/*   Updated: 2024/11/08 12:57:16 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_searchchar(char c, char *str)
{
	int	i;
	int	yes;

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
