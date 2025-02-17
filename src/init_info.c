/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:55:52 by bdomansk          #+#    #+#             */
/*   Updated: 2020/02/08 14:55:54 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static t_flags		*init_flags(void)
{
	t_flags	*flags;

	flags = (t_flags*)malloc(sizeof(t_flags));
	flags->p = 0;
	flags->q = 0;
	flags->r = 0;
	flags->s = 0;
	return (flags);
}

static t_algorithm	*init_algorithms(void)
{
	t_algorithm	*algorithms;
	int			num;

	num = NUMBER_OF_ALGORITHMS;
	algorithms = (t_algorithm*)malloc(sizeof(t_algorithm ) * num);
	algorithms[0].name = "md5";
	algorithms[0].function = md5;
	algorithms[1].name = "sha256";
	algorithms[1].function = sha256;
	algorithms[2].name = "sha224";
	algorithms[2].function = sha224;
	algorithms[3].name = "sha512";
	algorithms[3].function = sha512;
	algorithms[4].name = "sha384";
	algorithms[4].function = sha384;
	return (algorithms);
}

t_info				*init_info(int argc, char **argv)
{
	t_info		*info;

	info = (t_info*)malloc(sizeof(t_info));
	info->argc = argc;
	info->argv = argv;
	info->stdin = 0;
	info->length = 0;
	info->flags = init_flags();
	info->algorithms = init_algorithms();
	info->algorithm = NULL;
	info->files = NULL;
	info->buffer = NULL;
	info->error = NULL;
	info->result = NULL;
	info->data = NULL;
	info->data8 = NULL;
	info->data64 = NULL;
	info->block32 = (t_block_32*)malloc(sizeof(t_block_32));
	info->block64 = (t_block_64*)malloc(sizeof(t_block_64));
	return (info);
}
