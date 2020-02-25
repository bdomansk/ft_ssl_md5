/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_file_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:35:55 by bdomansk          #+#    #+#             */
/*   Updated: 2020/02/22 16:35:57 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	free_data(t_info *info)
{
	if (info->data)
		free(info->data);
	if (info->data8)
		free(info->data8);
	if (info->data64)
		free(info->data64);
}

void	free_file_info(t_info *info)
{
	t_file	*file;

	file = info->files;
	info->files = file->next;
	free(file);
	free(info->result);
	ft_strdel(&info->buffer);
	info->buffer = NULL;
	info->error = NULL;
	info->result = NULL;
	info->length = 0;
	free_data(info);
}
