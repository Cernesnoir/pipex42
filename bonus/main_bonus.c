/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 16:40:14 by anmuller          #+#    #+#             */
/*   Updated: 2026/05/28 23:58:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void free_str(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i])
			free(str[i]);
		i++;
	}
	if (str)
		free(str);
}

void do_fd(t_pipex *p, int i)
{
	if (i == 0)
		dup2(p->fd_files[0], STDIN_FILENO);
	else
		dup2(p->fd_pipe[i - 1][0], STDIN_FILENO);
	if (i == p->argc - 4 - p->h_doc_offset)
	{
    	if (p->fd_files[1] == -1)
        	exit(1);
    	dup2(p->fd_files[1], STDOUT_FILENO);
	}
	else
		dup2(p->fd_pipe[i][1], STDOUT_FILENO);
}

void	cmd(t_pipex *p, int i, char **argv, char **envp)
{
	char	*str;
	char	**args_split;

	do_fd(p, i);
	close_all_fd(p, NULL, p->argc);
	if (!argv[2][0])
		error_perso(p, "Command not found", 127);
	args_split = split_pipex(argv[i + 2 + p->h_doc_offset], ' ');
	if (!args_split)
		close_fd_cmd(p, "cmd");
	str = search_cmd(args_split[0], envp);
	if (!str)
	{
		free_str(args_split);
		free(p->pid);
		free(p);
		exit(127);
	}
	if (execve(str, args_split, envp) == -1)
		error_execve(args_split, p, str, "cmd");
}

int check_args(int argc, char **argv)
{
    if (argc < 5)
        return (0);
    if (ft_strncmp(argv[1], "here_doc", 10) == 0)
    {
        if (argc < 6)
            return (0);
    }
    return (1);
}

int	main(int argc, char **argv, char **envp)
{
	int		status_cmd;
	t_pipex *pip;

	if (!check_args(argc, argv))
		return (1);
	pip = ft_calloc(1, sizeof(t_pipex));
	init_struct(pip, argv, argc);
	if (!pip || !pip->fd_pipe || !pip->pid)
		return (1);
	handle_exit(pip, argv);
	do_fork_cmd(pip, argv, envp);
	close_all_fd(pip, NULL, argc);
	loop_wait(pip, &status_cmd, argc);
	if (pip->exit_code)
    	return (pip->exit_code);
	free(pip->pid);
	free(pip);
	if (WIFEXITED(status_cmd))
		return (WEXITSTATUS(status_cmd));
	return (1);
}
