/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmaokham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:20:49 by vmaokham          #+#    #+#             */
/*   Updated: 2020/03/06 16:26:02 by vmaokham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		fd[argc];
	int		ret[argc];
	char	*str;
	int		are_all_files_read;
	int		i;

	are_all_files_read = 0;
	i = 0;
	if (argc == 1)
	{
		while (ret[0])
		{
			fd[0] = open("/dev/stdin", O_RDONLY);
			ret[0] = get_next_line(fd[0], &str);
			printf("%d-%s\n", ret[0], str);
			free(str);
		}
	}
	while (i < argc - 1)
	{
		fd[i] = open(argv[i + 1], O_RDONLY);
		i++;
	}
	i = 0;
	while (!are_all_files_read)
	{
		while (i < argc - 1)
		{
			ret[i] = get_next_line(fd[i], &str);
			printf("%d-%s\n", ret[i], str);
			free(str);
			i++;
		}
		are_all_files_read = 1;
		while (i)
		{
			i--;
			if (ret[i])
				are_all_files_read = 0;
		}
	}
	while (1)
		;
	return (0);
}
