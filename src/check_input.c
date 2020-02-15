/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 13:53:44 by bdomansk          #+#    #+#             */
/*   Updated: 2020/02/15 13:53:47 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static int check_algorithm(t_info *info, char *algorithm)
{
	t_algorithm	*algorithms;
	int			i;

	i = 0;
	algorithms = info->algorithms;
	while (i < NUMBER_OF_ALGORITHMS)
	{
		if (!ft_strcmp(algorithm, algorithms[i].name)) {
			info->algorithm = &algorithms[i];
			return (1);
		}
		i++;
	}
	return (0);
}

static void	get_algorithm_from_stdin(t_info *info)
{
	char *buf;

	info->stdin = 1;
	while (!info->algorithm) {
		ft_printf("SSL> ");
		if (get_next_line(0, &buf))
		{
			if (ft_strlen(buf) && !check_algorithm(info, buf))
				ft_printf("algorithms list: md5|sha256\n" );
		} else {
			ft_strdel(&buf);
			leaks_exit(0);
		}
		ft_strdel(&buf);
	}
}

static void	check_arguments(t_info *info)
{
	int i;

	i = 2;
	while (i < info->argc)
	{
		//if
		i++; 
	}
}

void		check_input(t_info *info)
{
	if (info->argc == 1)
		get_algorithm_from_stdin(info);
	else {
		if (!check_algorithm(info, info->argv[1]))
			error("Wrong algorithm name");
		if (info->argc > 2) 
			check_arguments(info);
		else
			info->stdin = 1;
	}
}