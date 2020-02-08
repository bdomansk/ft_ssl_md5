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

static void		check_input(int argc, char **argv)
{
	if (argc == 1)
		error("usage: ./ft_ssl md5|sha256 [flags] [file_name]");
	ft_printf("%s", argv[1]);
}

int				main(int argc, char **argv)
{
	t_info	*info;

	info = init_info();
	ft_printf("Number - %s\n", info->algorithms[0].name);
	check_input(argc, argv);
	md5(info);
	return (0);
}
