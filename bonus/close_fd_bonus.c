/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fd_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 11:57:59 by anmuller          #+#    #+#             */
/*   Updated: 2026/05/28 23:32:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_all(char **str1, char *str2)
{
	free_str(str1);
	free(str2);
	exit(EXIT_FAILURE);
}

int	close_all_fd(t_pipex *p, const char *str, int argc)
{
	int i;

	i = 0;
	while (i < argc - 4 - p->h_doc_offset)
	{
		close(p->fd_pipe[i][0]);
		close(p->fd_pipe[i][1]);
		free(p->fd_pipe[i]);
		i++;
	}
	if (p->fd_pipe)
		free(p->fd_pipe);
	close_fd(p);
	if (str)
		error(str);
	return (1);
}

void	close_fd_cmd(t_pipex *p, char *name_proc)
{
	if (p->pid)
		free(p->pid);
	if (p)
		free(p);
	if (ft_strncmp(name_proc, "cmd inexistante", 15) == 0)
		exit(127);
	if (ft_strncmp(name_proc, "cmd2", 4) == 0)
		exit(127);
	else if (ft_strncmp(name_proc, "cmd1", 4) == 0)
		exit(127);
}

int	close_fd(t_pipex *p)
{
	if (p->fd_files[0] >= 0)
		close(p->fd_files[0]);
	if (p->fd_files[1] >= 0)
		close(p->fd_files[1]);
	return (1);
}
