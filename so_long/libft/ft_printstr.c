/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:49:48 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/04 15:39:02 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


int	ft_printstr(char *str)
{
	if (str == NULL)
		return (ft_printstr("(null)"));
	return (write(1, str, ft_strlen(str)));
}
