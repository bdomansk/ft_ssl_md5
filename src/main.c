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

static void stdin(t_info *info)
{
	info->flags->q = 1;
	read_data(0, info);
	info->algorithm->function(info);
	output_hash(info);
}

int	main(int argc, char **argv)
{
	t_info	*info;

	info = init_info(argc, argv);
	check_input(info);
	info->algorithm->function(info);
	if (info->stdin)
		stdin(info);
	//tmp
	t_file *files;

	files = info->files;
		while (files) 
		{
			ft_printf("%s\n", files->name);
			files = files->next;
		}
	// if info->stdin 
	leaks_exit(0);
}
