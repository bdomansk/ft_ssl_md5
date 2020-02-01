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

typedef struct	s_flags
{
	int	h;
	int l;
	int	c;
	int v;
	int	m;
	int	n;
	int	dump;
	int	dump_value;
	int	dump_bytes;
	int	lives;
	int	cycles;
	int	ops;
	int	deaths;
	int	moves;
}				t_flags;

#endif
