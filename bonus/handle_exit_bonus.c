/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_exit_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 19:20:38 by marvin            #+#    #+#             */
/*   Updated: 2026/05/25 19:20:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void handle_exit(t_pipex *pip, char **argv)
{
	pip->exit_code = 0;
	if (pip->fd_files[1] == -1)
	{
    	perror(argv[pip->argc - 1]);
    	pip->exit_code = 1;
	}
}