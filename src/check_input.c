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

static int	check_algorithm(t_info *info, char *algorithm)
{
	t_algorithm	*algorithms;
	int			i;

	i = 0;
	algorithms = info->algorithms;
	while (i < NUMBER_OF_ALGORITHMS)
	{
		if (!ft_strcmp(algorithm, algorithms[i].name))
		{
			info->algorithm = &algorithms[i];
			return (1);
		}
		i++;
	}
	return (0);
}

static void	print_algorithms_list(t_algorithm *algorithms)
{
	int	i;

	i = 0;
	ft_printf("Wrong algorithm name. Algorithms list: ");
	while (i < NUMBER_OF_ALGORITHMS)
	{
		if (i == 0)
			ft_printf("%s", algorithms[i].name);
		else
			ft_printf("|%s", algorithms[i].name);
		i++;
	}
	ft_printf("\n");
}

static void	get_algorithm_from_stdin(t_info *info)
{
	char *buf;

	info->stdin = 1;
	while (!info->algorithm)
	{
		ft_printf("SSL> ");
		if (get_next_line(0, &buf))
		{
			if (ft_strlen(buf) && !check_algorithm(info, buf))
				print_algorithms_list(info->algorithms);
		}
		else
		{
			ft_strdel(&buf);
			leaks_exit(0);
		}
		ft_strdel(&buf);
	}
}

void		check_input(t_info *info)
{
	if (info->argc == 1)
		get_algorithm_from_stdin(info);
	else
	{
		if (!check_algorithm(info, info->argv[1]))
		{
			print_algorithms_list(info->algorithms);
			error(NULL);
		}
		if (info->argc > 2)
			check_arguments(info);
		else
			info->stdin = 1;
	}
}
