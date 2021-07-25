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

int		main(int argc, char **argv)
{
	// char *pathname;
	char **cmd1;
	// char **cmd2;

	if (argc == 2)
	{
		cmd1 = ft_split(argv[1], ' ');
			// printarray(cmd1[0]);
		// if (cmd1[1])
			// printarray(cmd1[1]);
		// cmd2 = ft_split(argv[2], ' ');
	}
	// char* arg[] = {"/bin/pwd", 0};
	
	execve("/bin/ls", cmd1, NULL);
	return 0;
}