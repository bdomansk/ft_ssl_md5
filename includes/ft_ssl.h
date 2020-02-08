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

# define LEAKS 1
# define NUMBER_OF_ALGORITHMS 2

typedef struct	s_algorithm
{
	char		*name;
	void		(*function)(void*);
}				t_algorithm;

typedef struct	s_flags
{
	char	p;
	char	q;
	char	r;
	char	s;
}				t_flags;

typedef struct	s_info
{
	t_algorithm	*algorithms;
	t_flags		*flags;
}				t_info;

void			error(char *error_reason);
t_info			*init_info();
void			md5(void *data);
void			sha256(void *data);

#endif
