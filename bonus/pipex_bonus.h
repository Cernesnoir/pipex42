/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 16:40:31 by anmuller          #+#    #+#             */
/*   Updated: 2026/05/28 23:58:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipex
{
	int		fd_files[2];
	int	exit_code;
	int     h_doc_offset; 
	int		**fd_pipe;
	pid_t	*pid;
	char	**paths;
	int argc;
}	t_pipex;

int		check_access(char **argv);
int		error_pipe(t_pipex *p);
int		close_fd(t_pipex *p);
int	close_all_fd(t_pipex *p, const char *str, int argc);
void	free_all(char **str1, char *str2);
int		args_failure(char **argv);
int		error(const char *str);
void	cmd(t_pipex *p, int i, char **argv, char **envp);
void	error_perso(t_pipex *p, const char *str, int num);
void		do_fork_cmd(t_pipex *p, char **argv, char **envp);
void	error_execve(char **args_split, t_pipex *p, char *str, char *name_proc);
void	close_fd_cmd(t_pipex *p, char *name_proc);
void loop_wait(t_pipex *pip, int *status_cmd, int argc);
char	*alloc_arr(char const *s, char c);
char	*search_cmd(char *cmd, char **envp);
char	**split_pipex(char const *s, char c);
int	**free_pipe(int **fd_arr, int i);
void free_str(char **str);
void handle_exit(t_pipex *pip, char **argv);
int here_doc(char *str);
char **free_res(char **res, int j);
int	**make_pipe(t_pipex *p, int **fd_arr, int argc);
int make_fork(t_pipex *p, int argc);
void init_struct(t_pipex *p, char **argv, int argc);

#endif