/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erreur.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmuller <anmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 21:37:29 by anmuller          #+#    #+#             */
/*   Updated: 2026/03/12 09:35:11 by anmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	error(const char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
	return (1);
}

int	error_pipe(int fd1, int fd2)
{
	perror("pipe");
	close_fd(fd1, fd2);
	return (1);
}

void	error_execve(char **args_split, char *str, char *name_proc)
{
	perror("execve");
	free_arr(args_split);
	free(str);
	if (ft_strncmp(name_proc, "cmd2", 4) == 0)
		exit(EXIT_FAILURE);
	else if (ft_strncmp(name_proc, "cmd1", 4) == 0)
		exit(EXIT_FAILURE);
}
