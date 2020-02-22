/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 17:47:52 by bdomansk          #+#    #+#             */
/*   Updated: 2018/10/30 17:47:54 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void	ft_stdin(t_info *info)
{
	// read_stdin(info);
	info->algorithm->function(info);
	output_hash(info);
	info->flags->p = 0;
	info->stdin = 0;
}

static void	parse_file(t_info *info)
{
	if (info->flags->p)
		ft_stdin(info);
	if (info->files->string)
		info->buffer = ft_strdup(info->files->name);
	else
		read_file(info);
	info->algorithm->function(info);
	output_hash(info);
	free_file_info(info);
	if (info->files)
		parse_file(info);
}

int			main(int argc, char **argv)
{
	t_info	*info;

	info = init_info(argc, argv);
	check_input(info);
	if (info->stdin)
		ft_stdin(info);
	else
		parse_file(info);
	leaks_exit(0);
}
