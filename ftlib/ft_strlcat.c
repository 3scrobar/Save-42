/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:47:40 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/06 11:47:50 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);

	// Si `size` est inférieur ou égal à la longueur de `dst`, on retourne `size + src_len`
	if (size <= dst_len)
		return (size + src_len);

	// On copie les caractères de `src` dans `dst`, sans dépasser `size - 1` pour garder la place du `\0`
	i = 0;
	while (src[i] && (dst_len + i) < (size - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	// On ajoute le caractère nul `\0`
	dst[dst_len + i] = '\0';

	// Retourne la longueur totale de la chaîne qu'on a tenté de créer
	return (dst_len + src_len);
}
