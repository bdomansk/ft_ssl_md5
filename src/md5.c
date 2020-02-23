/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 16:55:28 by bdomansk          #+#    #+#             */
/*   Updated: 2020/02/08 16:55:29 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void	md5_init_var_h(t_info *info)
{
	info->var_h[0] = 0x67452301;
	info->var_h[1] = 0xefcdab89;
	info->var_h[2] = 0x98badcfe;
	info->var_h[3] = 0x10325476;
}

static void	md5_fill_message2(t_info *info)
{
	size_t	i;
	uint8_t	*buf;

	buf = (uint8_t *)info->buffer;
	i = 0;
	while (i < info->length)
	{
		((char *)info->data8)[i] = buf[i];
		i++;
	}
	info->message_length = info->message_length / 8;
	info->data8[info->length] = 0x80;
	i = info->length;
	while (++i < info->message_length)
		info->data8[i] = 0;
	*(uint32_t*)(info->data8 + i) = (uint32_t)info->length * 8;
}

static void	md5_fill_message(t_info *info)
{
	uint32_t	message_length;

	message_length = info->length * 8 + 1;
	while (message_length % 512 != 448)
		message_length++;
	info->message_length = message_length;
	info->data8 = malloc(message_length + 64);
	if (info->data8)
		md5_fill_message2(info);
}

static void	md5_main_cycle(t_info *info)
{
	size_t	i;

	i = 0;
	while (i < info->message_length)
	{
		md5_move_blocks(info, i);
		i += 64;
	}
}

void		md5(void *data)
{
	t_info	*info;

	info = data;
	md5_init_var_h(info);
	md5_fill_message(info);
	md5_main_cycle(info);
	md5_set_result(info);
}
