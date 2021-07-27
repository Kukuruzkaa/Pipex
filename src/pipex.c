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
	char **cmd1;
	// char *tmp;
	// char *pathname;
	int 	i;
	(void) envp; 	

	i = 0;
	// getenv = NULL;
	// getpath = NULL;
	// char **cmd2;

	if (!(argc == 5))
		exit(1);
	cmd1 = ft_split(argv[2], ' ');
			// printarray(cmd1[0]);
		// if (cmd1[1])
			// printarray(cmd1[1]);
		// cmd2 = ft_split(argv[2], ' ');
	// char* arg[] = {"/bin/pwd", 0};
	
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
	execve(cmd1[0], cmd1, NULL);
	return 0;
}