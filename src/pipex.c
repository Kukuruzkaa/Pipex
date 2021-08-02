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
#define P_STDIN 0
#define P_STDOUT 0
#define P_STDERR 0


void		printarray(char *arr)
{
	int length;

	length = ft_strlen(arr);
	for (int i = 0; i < length; i++)
	{
		printf("%c", arr[i]);
	}
	printf("\n");
}

int		main(int argc, char **argv, char **envp)
{
	// char *getenv;
	// char **getpath;
	// char *tmp;
	// char *pathname;
	char **cmd1;
	//char **cmd2;
	int		fds[2];
	pid_t 	childpid;
	int 	i;
	(void) envp; 	

	i = 0;
	// getenv = NULL;
	// getpath = NULL;

	pipe(fds);

	if (!(argc == 5))
		exit(1);

	childpid = fork();
	if (childpid == -1)
	{
		perror("fork");
		exit(1);
	}
	if (childpid == 0)
	{
		write(1, "@", 1);
		cmd2 = ft_split(argv[3], ' ');
		dup2(0, fds[0]);
		execve(cmd2[0], cmd2, NULL);
		close(fds[1]); // child will read from the pipe, no need to write
		close(fds[0]);
	}
	else 
	{
		write(1, "#", 1);
		cmd1 = ft_split(argv[2], ' ');
		close(fds[0]); //parent does not need to read
		dup2(0, fds[1]);
		execve(cmd1[0], cmd1, NULL);
		waitpid(childpid, NULL, 0);
		close(fds[1]);
	// }

	// while (envp[i])
	// {
	// 	if (ft_strnstr(envp[i], "PATH", 4))
	// 	{
	// 		envp[i] += 5;
	// 		getpath = ft_split(envp[i], ':');
	// 	}
	// 	i++;    
	// }
	// i = 0;
	// while (getpath[i])
	// {
	// 	tmp = ft_strjoin(getpath[i], "/");
	// 	pathname = ft_strjoin(tmp, *cmd1);
	// 	i++;
	// }
	
	return 0;
}