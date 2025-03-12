/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:05:19 by toto              #+#    #+#             */
/*   Updated: 2025/03/12 16:57:48 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include "../libft/source/libft.h"

void	son_process(char **argv, char **envp, int *fd);
void	father_process(char **argv, char **envp, int *fd);
char	*find_path(char *cmd, char **envp);
void	error(void);
void	execute(char *argv, char **envp);

#endif
