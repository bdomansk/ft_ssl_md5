/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 21:46:33 by bdomansk          #+#    #+#             */
/*   Updated: 2020/02/21 21:46:35 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static int	check_file(t_info *info)
{
	int fd;

	if ((fd = open(info->files->name, O_WRONLY)) < 0 && errno == EISDIR)
		info->error = "Is a directory";
	else if ((fd = open(info->files->name, O_RDONLY)) < 0 && errno == EACCES)
		info->error = "Permission denied";
	else if (fd == -1)
		info->error = "No such file";
	return (fd);
}

void		read_file(t_info *info)
{
	char	*buffer;
	int		fd;

	if ((fd = check_file(info)) > 0)
	{
		info->length = 0;
		fd = open(info->files->name, O_RDONLY);
		while (read(fd, &buffer, 1) > 0)
			info->length++;
		close(fd);
		fd = open(info->files->name, O_RDONLY);
		info->buffer = ft_strnew(info->length);
		read(fd, info->buffer, info->length);
		close(fd);
	}
}

void		read_stdin(t_info *info)
{
	char	*temp_buffer;
	char	*buffer;

	buffer = ft_strnew(1);
	info->buffer = ft_strnew(1);
	while (1)
	{
		temp_buffer = info->buffer;
		if (read(0, buffer, 1) == 0)
			break ;
		info->length++;
		info->buffer = ft_strjoin(temp_buffer, buffer);
		ft_strdel(&temp_buffer);
	}
	ft_strdel(&buffer);
}
