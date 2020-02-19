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

int	main(int argc, char **argv)
{
	t_info	*info;

	info = init_info(argc, argv);
	check_input(info);
	info->algorithm->function(info);
	//tmp
	t_file *files;

	files = info->files;
		while (files) 
		{
			ft_printf("%s\n", files->name);
			files = files->next;
		}
	//           ./ft_ssl md5 -s 1 Makefile Что-то не так  - (null)
	// if info->stdin 
	leaks_exit(0);
}
