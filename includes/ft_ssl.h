/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 17:23:34 by bdomansk          #+#    #+#             */
/*   Updated: 2020/02/01 17:23:36 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H
# include "../libft/libft.h"
# include <fcntl.h>
# include <errno.h>

# define LEAKS 1
# define NUMBER_OF_ALGORITHMS 2

typedef struct	s_algorithm
{
	char		*name;
	void		(*function)(void*);
}				t_algorithm;

typedef struct	s_file
{
	char			*name;
	int				string;
	struct s_file	*next;
}				t_file;

typedef struct	s_flags
{
	int			p;
	int			q;
	int			r;
	int			s;
}				t_flags;

typedef struct	s_info
{
	int			argc;
	char		**argv;
	int			stdin;
	size_t		length;
	t_algorithm	*algorithms;
	t_algorithm	*algorithm;
	t_file		*files;
	t_flags		*flags;
	char		*buffer;
	char		*result;
	char		*error;
	uint32_t	var_h[8];
	uint32_t	*data;
}				t_info;

void			error(char *error_reason);
void			leaks_exit(int code);
t_info			*init_info(int argc, char **argv);
void			check_input(t_info *info);
void			check_arguments(t_info *info);
void			read_file(t_info *info);
void			read_stdin(t_info *info);
void			output_hash(t_info *info);
void			free_file_info(t_info *info);
void			md5(void *data);
void			sha256(void *data);

#endif
