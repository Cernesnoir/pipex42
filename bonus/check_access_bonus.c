/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_access_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 11:35:27 by anmuller          #+#    #+#             */
/*   Updated: 2026/05/24 09:38:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	check_access(char **argv)
{
	if (!access(argv[4], F_OK) && access(argv[4], W_OK) == -1)
	{
		perror(argv[4]);
		exit(1);
		return (0);
	}
	if (access(argv[1], R_OK) == -1)
		perror(argv[1]);
	return (1);
}
