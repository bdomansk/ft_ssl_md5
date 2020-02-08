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

static t_flags	*init_flags(void)
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
	return (algorithms);
}

t_info				*init_info(void)
{
	t_info		*info;

	info = (t_info*)malloc(sizeof(t_info));
	info->flags = init_flags();
	info->algorithms = init_algorithms();
	return (info);
}
