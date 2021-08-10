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
#define STDIN 0
#define STDOUT 1
#define STDERR 2


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
	char **cmd1;
	char **cmd2;
	int		fds[2];
	pid_t 	childpid1;
	pid_t	childpid2;
	int 	status;
	int 	i;
	(void) envp; 	
	(void) argv;

	// char* arg1[] = {"/bin/ls", 0};
	// char* arg2[] = {"/bin/cat", 0};

	i = 0;
	
	pipe(fds);
	if (pipe(fds) == -1)
	{
		write(STDERR, "pipe failed\n", 12);
		exit(1);
	}

	if (argc != 5)
		exit(1);

	cmd1 = ft_split(argv[2], ' ');
	cmd2 = ft_split(argv[3], ' ');

	status = 0;
	childpid1 = fork();
	if (childpid1 == -1)
	{
		perror("fork child1");
		exit(1);
	}
	if (childpid1 == 0)
	{
		write(1, "@\n", 2);
		close(fds[0]); 
		dup2(fds[1], 1);
		close(fds[1]);
		execve(cmd1[0], cmd1, NULL);
	}
	else 
	{
		childpid2 = fork();
		if (childpid2 == -1)
		{
			perror("fork child2");
			exit(1);
		}
		if (childpid2 == 0)
		{
			write(1, "&\n", 2);
			close(fds[1]);
			dup2(fds[0], 0);
			close(fds[0]);
			execve(cmd2[0], cmd2, NULL);
		}
		else
		{		
			write(1, "#\n", 2);
			close(fds[0]);
			close(fds[1]);
			waitpid(childpid1, &status, 0);
			waitpid(childpid2, &status, 0);
		}
	}

	// char *getenv;
	// char **getpath;
	// char *tmp;
	// char *pathname;

	// getenv = NULL;
	// getpath = NULL;

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
	
	// char* arg[] = {"/bin/pwd", 0};

	//execve("/bin/ls", cmd1, NULL);
	return 0;
}