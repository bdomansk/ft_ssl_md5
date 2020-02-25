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
# define NUMBER_OF_ALGORITHMS 5

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

typedef struct	s_block_32
{
	uint32_t		a;
	uint32_t		b;
	uint32_t		c;
	uint32_t		d;
	uint32_t		e;
	uint32_t		f;
	uint32_t		g;
	uint32_t		h;
	uint32_t		*w;
}				t_block_32;

typedef struct	s_block_64
{
	uint64_t		a;
	uint64_t		b;
	uint64_t		c;
	uint64_t		d;
	uint64_t		e;
	uint64_t		f;
	uint64_t		g;
	uint64_t		h;
	uint64_t		*w;
}				t_block_64;

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
	uint64_t	v_h[8];
	uint32_t	*data;
	uint8_t		*data8;
	uint64_t	*data64;
	size_t		size;
	t_block_32	*block32;
	t_block_64	*block64;
	uint32_t	temp0;
	uint32_t	temp1;
	uint32_t	temp2;
	uint32_t	temp3;
	uint32_t	temp4;
	uint64_t	t0;
	uint64_t	t1;
	uint64_t	t2;
	uint64_t	t3;
	uint64_t	t4;
	uint32_t	message_length;
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
void			md5_move_blocks(t_info *info, uint32_t position);
void			md5_set_result(t_info *info);
void			sha256(void *data);
void			sha256_main_cycle(t_info *info);
void			sha256_fill_message(t_info *info);
void			sha256_fill_message2(t_info *info, uint32_t length);
void			sha256_fill_block(t_info *info, int position);
void			sha256_move_blocks(t_info *info);
void			sha256_set_result(t_info *info);
void			sha224(void *data);
void			sha512(void *data);
void			sha512_fill_message(t_info *info);
void			sha512_fill_message2(t_info *info, uint64_t length);
void			sha512_set_result(t_info *info);
void			sha512_main_cycle(t_info *info);
void			sha512_fill_block(t_info *info, int position);
void			sha512_move_blocks(t_info *info);
void			sha384(void *data);
uint32_t		swap_bits_32(uint32_t var);
uint32_t		swap_bits_md5(uint32_t var);
uint64_t		swap_bits_64(uint64_t var);
uint32_t		rotr32(uint32_t word, uint32_t offset);
uint64_t		rotr64(uint64_t word, uint64_t offset);
uint32_t		left_rotr32(uint32_t word, uint32_t offset);

#endif
