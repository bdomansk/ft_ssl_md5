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

void	free_file_info(t_info *info)
{
	t_file	*file;

	file = info->files;
	info->files = file->next;
	free(file);
	ft_strdel(&info->buffer);
	info->buffer = NULL;
	info->error = NULL;
	info->result = NULL;
	info->length = 0;
}
