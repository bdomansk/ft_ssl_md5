/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 16:55:39 by bdomansk          #+#    #+#             */
/*   Updated: 2020/02/08 16:55:42 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "sha256.h"

static void	sha256_init_var_h(t_info *info)
{
	info->var_h[0] = 0x6a09e667;
	info->var_h[1] = 0xbb67ae85;
	info->var_h[2] = 0x3c6ef372;
	info->var_h[3] = 0xa54ff53a;
	info->var_h[4] = 0x510e527f;
	info->var_h[5] = 0x9b05688c;
	info->var_h[6] = 0x1f83d9ab;
	info->var_h[7] = 0x5be0cd19;
}

static void	sha256_fill_message2(t_info *info, size_t size, uint32_t length)
{
	size_t		i;

	ft_bzero(info->data, 16 * size * sizeof(uint32_t));
	i = 0;
	while (i < info->length)
	{
		((char *)info->data)[i] = info->buffer[i];
		i++;
	}
	((char*)info->data)[info->length] = 0x80;
	i = 0;
	while (i < (size * 16))
	{
		// info->data[i] = swap_32bit((uint32_t)info->data[i]);
		i++;
	}
	info->data[(length) / 32 + 1] = (uint32_t)info->length * 8;
}

static void	sha256_fill_message(t_info *info)
{
	
	size_t		size;
	uint32_t	message_length;

	message_length = info->length * 8 + 1;
	while (message_length % 512 != 448)
		message_length++;
	size = (64 + message_length) / 512;
	info->data = malloc(16 * size * sizeof(uint32_t));
	if (info->data)
		sha256_fill_message2(info, size, message_length);
}

void		sha256(void *data)
{
	t_info	*info;

	info = data;
	sha256_init_var_h(info);
	sha256_fill_message(info);
	info->result = "sha256_fsfsfssfs";
}
