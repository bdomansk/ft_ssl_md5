/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 20:06:23 by bdomansk          #+#    #+#             */
/*   Updated: 2020/02/19 20:06:25 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static int		check_flags(t_info *info, char *s)
{
	if (ft_strlen(s) != 2 || !ft_strchr("pqrs", (int)s[1]) || info->flags->s)
		return (0);
	info->flags->p = (s[1] == 'p') ? 1 : info->flags->p;
	info->flags->q = (s[1] == 'q') ? 1 : info->flags->q;
	info->flags->r = (s[1] == 'r') ? 1 : info->flags->r;
	info->flags->s = (s[1] == 's') ? 1 : info->flags->s;
	return (1);
}

static t_file	*add_file(t_info *info, int i)
{
	t_file *file;

	file = (t_file*)malloc(sizeof(t_file));
	file->name = info->argv[i];
	if (info->flags->s)
	{
		info->flags->s = 0;
		file->string = 1;
	}
	else
		file->string = 0;
	if (++i < info->argc)
		file->next = add_file(info, i);
	else
		file->next = NULL;
	return (file);
}

void			check_arguments(t_info *info)
{
	int i;

	i = 2;
	while (i < info->argc)
	{
		if (info->argv[i][0] != '-' || !check_flags(info, info->argv[i]))
			break ;
		i++;
	}
	if (i == info->argc && info->flags->s)
		error("You need to put string after -s flag");
	else if (i == info->argc)
		info->stdin = 1;
	else
		info->files = add_file(info, i);
}
