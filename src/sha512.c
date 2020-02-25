/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 22:17:57 by bdomansk          #+#    #+#             */
/*   Updated: 2020/02/23 22:17:58 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void	sha512_init_var_h(t_info *info)
{
	info->v_h[0] = 0x6a09e667f3bcc908;
	info->v_h[1] = 0xbb67ae8584caa73b;
	info->v_h[2] = 0x3c6ef372fe94f82b;
	info->v_h[3] = 0xa54ff53a5f1d36f1;
	info->v_h[4] = 0x510e527fade682d1;
	info->v_h[5] = 0x9b05688c2b3e6c1f;
	info->v_h[6] = 0x1f83d9abfb41bd6b;
	info->v_h[7] = 0x5be0cd19137e2179;
}

void		sha512_fill_message2(t_info *info, uint64_t length)
{
	size_t		i;

	ft_bzero(info->data64, 16 * info->size * sizeof(uint64_t));
	i = 0;
	while (i < info->length)
	{
		((char *)info->data64)[i] = info->buffer[i];
		i++;
	}
	((char*)info->data64)[info->length] = 0x80;
	i = 0;
	while (i < (info->size * 16))
	{
		info->data64[i] = swap_bits_64((uint64_t)info->data64[i]);
		i++;
	}
	info->data64[length / 64 + 1] = (uint64_t)info->length * 8;
}

void		sha512_fill_message(t_info *info)
{
	uint64_t	message_length;

	message_length = info->length * 8 + 1;
	while (message_length % 1024 != 896)
		message_length++;
	info->size = (128 + message_length) / 1024;
	info->data64 = malloc(16 * info->size * sizeof(uint64_t));
	if (info->data64)
		sha512_fill_message2(info, message_length);
}

void		sha512_main_cycle(t_info *info)
{
	size_t	i;

	i = 0;
	while (i < info->size)
	{
		sha512_fill_block(info, i);
		sha512_move_blocks(info);
		i++;
	}
}

void		sha512(void *data)
{
	t_info	*info;

	info = data;
	sha512_init_var_h(info);
	sha512_fill_message(info);
	sha512_main_cycle(info);
	sha512_set_result(info);
}
