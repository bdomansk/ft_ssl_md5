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

static void	stdin(t_info *info)
{
	info->flags->q = 1;
	//read_data(0, info);
	info->algorithm->function(info);
	//output_hash(info); // учитывает флаги -r и  -q
}

static void	parse_files(t_info *info)
{
	t_file *file;

	if (info->flags->p)
		stdin(info);
	file = info->files;
	while (file)
	{
		if (file->string)
			info->buffer = ft_strdup(file->name);
		else
			read_file(info, file);
		info->algorithm->function(info);
		//output_hash(info);
		//free_file_info(info); // внутри ft_strdel(info->buffer) + free t_file;
		file = file->next;
	}
}

int			main(int argc, char **argv)
{
	t_info	*info;

	info = init_info(argc, argv);
	check_input(info);
	if (info->stdin)
		stdin(info);
	else
		parse_files(info);
	leaks_exit(0);
}
