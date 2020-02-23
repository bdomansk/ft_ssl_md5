/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 18:26:50 by bdomansk          #+#    #+#             */
/*   Updated: 2020/02/23 18:26:52 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "md5.h"

static void	md5_calc(t_info *info, uint32_t i)
{
	if (i < 16)
	{
		info->temp0 = info->block32->b & info->block32->c;
		info->temp1 = (~info->block32->b) & info->block32->d;
		info->temp2 = info->temp0 | info->temp1;
	}
	else if (i >= 16 && i <= 31)
	{
		info->temp0 = info->block32->d & info->block32->b;
		info->temp1 = (~info->block32->d) & info->block32->c;
		info->temp2 = info->temp0 | info->temp1;
	}
	else if (i > 31 && i <= 47)
		info->temp2 = info->block32->b ^ info->block32->c ^ info->block32->d;
	else if (i > 47 && i <= 63)
	{
		info->temp0 = info->block32->b | (~info->block32->d);
		info->temp2 = info->block32->c ^ info->temp0;
	}
}

static void	md5_prepare_blocks(t_info *info, uint32_t position)
{
	uint32_t	i;
	uint32_t	*data;

	i = 0;
	data = (uint32_t*)(info->data8 + position);
	while (i < 64)
	{
		md5_calc(info, i);
		info->temp3 = info->block32->d;
		info->block32->d = info->block32->c;
		info->block32->c = info->block32->b;
		info->temp0 = info->temp2 + info->block32->a + g_md5_consts0[i];
		info->temp4 = info->temp0 + data[g_md5_consts2[i]];
		info->block32->b += left_rotr32(info->temp4, g_md5_consts1[i]);
		info->block32->a = info->temp3;
		i++;
	}
}

void		md5_move_blocks(t_info *info, uint32_t position)
{
	info->block32->a = info->var_h[0];
	info->block32->b = info->var_h[1];
	info->block32->c = info->var_h[2];
	info->block32->d = info->var_h[3];
	md5_prepare_blocks(info, position);
	info->var_h[0] = info->block32->a + info->var_h[0];
	info->var_h[1] = info->block32->b + info->var_h[1];
	info->var_h[2] = info->block32->c + info->var_h[2];
	info->var_h[3] = info->block32->d + info->var_h[3];
}

void		md5_set_result(t_info *info)
{
	info->var_h[0] = swap_bits_md5(info->var_h[0]);
	info->var_h[1] = swap_bits_md5(info->var_h[1]);
	info->var_h[2] = swap_bits_md5(info->var_h[2]);
	info->var_h[3] = swap_bits_md5(info->var_h[3]);
	info->result = ft_sprintf("%08x%08x%08x%08x",
		info->var_h[0],
		info->var_h[1],
		info->var_h[2],
		info->var_h[3]);
}
