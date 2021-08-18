/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 19:57:30 by ddiakova          #+#    #+#             */
/*   Updated: 2021/07/15 19:57:34 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
// #define STDIN 0
// #define STDOUT 1
// #define STDERR 2


char 	**ft_getpath(char **envp)
{
	int i;
	char **getpath;

	i = 0;
	getpath = NULL;

	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
		{
			envp[i] += 5;
			getpath = ft_split(envp[i], ':');
			break;
		}
		i++;    
	}
	return(getpath);
}

void 	freepath(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
}

int		main(int argc, char **argv, char **envp)
{
	char **cmd1;
	char **cmd2;
	int		fds[2];
	pid_t 	childpid1;
	pid_t	childpid2;
	int 	status;
	int 	fd_in;
	int 	fd_out;
	char **mypath;
	char *cmd;
	char *tmp;
	int i;
	int access_pathname;

	status = 0;
	fd_in = 0;
	fd_out = 0;
	
	if (argc != 5)
	{
		ft_putstr_fd(": wrong number of arguments", 2);
		exit(1);
	}
	if (pipe(fds) == -1)
	{
		perror("Error: pipe failed");
		exit(1);
	}
	childpid1 = fork();
	if (childpid1 == -1)
	{
		perror("Error: Failed to fork child process");
		exit(1);
	}
	if (childpid1 == 0)
	{
		fd_in = open(argv[1], O_RDONLY);
		if (fd_in == -1)
		{
			ft_putstr_fd(argv[1], 2);
			ft_putstr_fd(": No such file or directory", 2);
			write (1, "\n", 1);
		}
		close(fds[0]);
		dup2(fd_in, 0);
		close(fd_in);
		dup2(fds[1], 1);
		cmd1 = ft_split(argv[2], ' ');
		mypath = ft_getpath(envp);
		i = 0;
		access_pathname = 0;
		while (mypath[i])
		{
			tmp = ft_strjoin(mypath[i], "/");
			cmd = ft_strjoin(tmp, cmd1[0]);
			free (tmp);
			if (!access(cmd, X_OK))
				execve(cmd, cmd1, envp);
			else
				access_pathname = 1;                                                                                                                                                                                                    
			i++;
		}
		freepath(mypath);
		if (access_pathname == 1)
		{
			ft_putstr_fd(argv[2], 2);
			ft_putstr_fd(": command not found", 2);
			write (1, "\n", 1);
			if (cmd)
				free(cmd);
			exit(1);
		}
		close(fds[1]);
	}
	else 
	{
		childpid2 = fork();
		if (childpid2 == -1)
		{
			perror("Error: Failed to fork child process");
			exit(1);
		}
		if (childpid2 == 0)
		{
			fd_out = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
			if (fd_out == -1)
			{
				ft_putstr_fd(argv[4], 2);
				ft_putstr_fd(": No such file or directory", 2);
				write (1, "\n", 1);
			}
			close(fds[1]);
			dup2(fd_out, 1);
			close(fd_out);
			dup2(fds[0], 0);
			cmd2 = ft_split(argv[3], ' ');
			mypath = ft_getpath(envp);
			i = 0;
			access_pathname = 0;
			while (mypath[i])
			{
				tmp = ft_strjoin(mypath[i], "/");
				cmd = ft_strjoin(tmp, cmd2[0]);
				free (tmp);
				if (!access(cmd, X_OK))
					execve(cmd, cmd2, envp);
				else
					access_pathname = 1;
				i++;
			}
			freepath(mypath);
			if (access_pathname == 1)
			{
				ft_putstr_fd(argv[3], 2);
				ft_putstr_fd(": command not found", 2);
				write (1, "\n", 1);
				if (cmd)
					free(cmd);
				exit(1);
			}
			close(fds[0]);
		}
		else
		{		
			close(fds[0]);
			close(fds[1]);
			waitpid(childpid1, &status, 0);
			waitpid(childpid2, &status, 0);
		}
	}
	return 0;
}