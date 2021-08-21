/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 19:57:30 by ddiakova          #+#    #+#             */
/*   Updated: 2021/08/21 17:39:51 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_in(char **envp, char **argv, int fds[2])
{
	char	**cmd1;
	int		fd_in;

	cmd1 = NULL;
	fd_in = 0;
	fd_in = open(argv[1], O_RDONLY);
	if (fd_in == -1)
		ft_print_error_and_exit(argv[1], 0);
	close(fds[0]);
	dup2(fd_in, 0);
	close(fd_in);
	dup2(fds[1], 1);
	cmd1 = ft_split(argv[2], ' ');
	if (!cmd1 || cmd1[0] == 0)
	{
		free(cmd1);
		ft_print_error_and_exit(argv[2], 1);
	}
	ft_add_mypath(envp, argv[2], cmd1, 0);
	close(fds[1]);
}

void	ft_child_out(char **envp, char **argv, int fds[2])
{
	char	**cmd2;
	int		fd_out;

	cmd2 = NULL;
	fd_out = 0;
	fd_out = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd_out == -1)
		ft_print_error_and_exit(argv[4], 0);
	close(fds[1]);
	dup2(fd_out, 1);
	close(fd_out);
	dup2(fds[0], 0);
	cmd2 = ft_split(argv[3], ' ');
	if (!cmd2 || cmd2[0] == 0)
	{
		free(cmd2);
		ft_print_error_and_exit(argv[3], 1);
	}
	ft_add_mypath(envp, argv[3], cmd2, 0);
	close(fds[0]);
}

void	ft_close_parent(int fds[2], pid_t childpid1, pid_t childpid2,
		int status)
{
	close(fds[0]);
	close(fds[1]);
	waitpid(childpid1, &status, 0);
	waitpid(childpid2, &status, 0);
}

int	main(int argc, char **argv, char **envp)
{
	int		fds[2];
	pid_t	childpid1;
	pid_t	childpid2;
	int		status;

	status = 0;
	ft_check_argc(argc);
	ft_check_pipe(fds);
	childpid1 = fork();
	ft_check_childpid(childpid1);
	if (childpid1 == 0)
		ft_child_in(envp, argv, fds);
	else
	{
		childpid2 = fork();
		ft_check_childpid(childpid2);
		if (childpid2 == 0)
			ft_child_out(envp, argv, fds);
		else
			ft_close_parent(fds, childpid1, childpid2, status);
	}
	return (0);
}
