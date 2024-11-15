/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:38:24 by tle-saut          #+#    #+#             */
/*   Updated: 2024/11/15 17:12:48 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int				ft_printchar(char c);
int				ft_check(va_list args, char c);
int				ft_printstr(char *str);
unsigned int	ft_strlen(const char *s);
int				ft_putnbr_fd(int n, int fd);
int				ft_printfnumb(int n);
unsigned int	ft_printfnumb_base_maj(unsigned int nbr);
size_t			ft_printfnumb_base_min(size_t nbr);
unsigned int	ft_printf(const char *str, ...);
int				ft_printpointer(size_t	nbr);
int				ft_printf_unsnbr(unsigned int n);

#endif
