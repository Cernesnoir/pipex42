/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 10:47:41 by anmuller          #+#    #+#             */
/*   Updated: 2026/05/25 17:36:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

int	is_path(char *cmd)
{
	if (!ft_strchr(cmd, '/'))
		return (0);
	else
		return (1);
}

char	*loop_paths(char **paths, char *cmd, int i)
{
	char	*res;
	char	*temp;

	if (is_path(cmd) == 1 && access(cmd, F_OK) == 0)
		return (cmd);
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		if (!temp)
			return (NULL);
		res = ft_strjoin(temp, cmd);
		if (!res)
		{
			free(temp);
			return (NULL);
		}
		free(temp);
		if (access(res, X_OK) == 0)
			return (res);
		i++;
		free(res);
	}
	return (NULL);
}

char	*cmd_not_found(char *cmd)
{
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": command not found\n", 2);
	return (NULL);
}

char	*search_cmd(char *cmd, char **envp)
{
	int		i;
	char	*res;
	char	*str;
	char	**paths;

	str = path(envp);
	if (!str)
		return (NULL);
	paths = ft_split(str, ':');
	if (!paths)
		return (NULL);
	i = 0;
	res = loop_paths(paths, cmd, i);
	if (!res || (access(res, X_OK) == 0))
	{
		free_str(paths);
		if (!res)
			cmd_not_found(cmd);
		return (res);
	}
	free_str(paths);
	return (NULL);
}
