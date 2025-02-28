/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:18:00 by tle-saut          #+#    #+#             */
/*   Updated: 2025/02/28 18:18:04 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	first_tier(t_all *all, int i)
{

	count_all(all, 1);
	if (i > all->mintot + ((all->range / 3) * 2))
		return (1);
	return (0);
}

int	second_tier(t_all *all, int i)
{
	count_all(all, 1);
	if (i > all->mintot + (all->range / 3) && i <= all->mintot + (all->range / 3) * 2)
		return (1);
	else
		return (0);
}

int	third_tier(t_all *all, int i)
{
	count_all(all, 1);
	if (i < all->mintot + (all->range / 3))
		return (1);
	else
		return (0);
}

int	check_tier(t_all *all)
{
	t_swap	*temp;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	temp = all->lstb;
	while (temp)
	{
		if (first_tier(all, temp->value) == 1)
			i = 1;
		else if (second_tier(all, temp->value) == 1)
			j = 1;
		else if (third_tier(all, temp->value) == 1)
			k = 1;
		temp = temp->chain;
	}
	if ( i == 1 && j == 1 && k == 1)
		return (1);
	else
		return (0);
}

int	get_clockwise(t_all *all, int i)
{
	t_swap	*temp;
	int	j;

	j = 0;
	temp = all->lstb;
	while (temp && j != all->countb)
	{	
		if (temp->chain == NULL)
			return (pb(all), 0);
		if((i < temp->value && i > temp->chain->value ))
			return (j + 1);
		j++;
		temp = temp->chain;
	}
	return (0);
}
