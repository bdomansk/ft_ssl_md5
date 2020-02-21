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

static void	check_file(t_info *info, t_file *file)
{
	int fd;

	if ((fd = open(file->name, O_WRONLY)) < 0 && errno == EISDIR) 
		info->error = 
		return (error_directory(argv[i], hash_name));
	if ((fd = open(file->name, O_RDONLY)) < 0 && errno == EACCES)
		return (error_permission(argv[i], hash_name));
	if (fd == -1)
		return (error_no_file(argv[i], hash_name));
	close(fd);
	
}

void		read_file(t_info *info, t_file *file)
{
	char	*buffer;
	int		fd;

	if (check_file(info,file))
	{
		info->length = 0;
		fd = open(file->name, O_RDONLY);
		while (read(fd, &buffer, 1) > 0)
			info->length++;
	}
	
}
