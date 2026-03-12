/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmuller <anmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 10:47:41 by anmuller          #+#    #+#             */
/*   Updated: 2026/03/12 08:59:37 by anmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

char	*loop_paths(char **paths, char *cmd, int i)
{
	char	*res;
	char	*temp;

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
	if (!res || access(res, X_OK) == 0)
	{
		free_arr(paths);
		if (!res)
		{
			ft_printf("%s: command not found\n", cmd);
			return (NULL);
		}
		return (res);
	}
	free_arr(paths);
	return (NULL);
}
