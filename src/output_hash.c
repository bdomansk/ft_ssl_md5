/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_hash.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 14:42:37 by bdomansk          #+#    #+#             */
/*   Updated: 2020/02/22 14:42:39 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		output_hash(t_info *info)
{
	if (info->error)
		ft_printf("%s: %s\n", info->files->name, info->error);
	else if (info->stdin || info->flags->q || info->flags->p)
		ft_printf("%s\n", info->result);
	else if (info->files && info->files->string)
	{
		if (info->flags->r)
			ft_printf("%s \"%s\"\n", info->result, info->files->name);
		else
			ft_printf("%s (\"%s\") = %s\n", info->algorithm->name,
			info->files->name, info->result);
	}
	else
	{
		if (info->flags->r)
			ft_printf("%s %s\n", info->result, info->files->name);
		else
			ft_printf("%s (%s) = %s\n", info->algorithm->name,
				info->files->name, info->result);
	}
}
