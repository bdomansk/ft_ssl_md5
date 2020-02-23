/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 13:18:32 by bdomansk          #+#    #+#             */
/*   Updated: 2020/02/23 13:18:34 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "sha256.h"

void		sha256_fill_block(t_info *info, int position)
{
	int			i;
	uint32_t	sum0;
	uint32_t	sum1;

	i = 16;
	info->block32->w = (uint32_t *)malloc(64 * 8 * sizeof(uint32_t));
	ft_bzero(info->block32->w, sizeof(uint32_t) * 512);
	ft_memcpy(info->block32->w, &(info->data[16 * position]), 512);
	while (i < 64)
	{
		info->temp0 = rotr32(info->block32->w[i - 15], 7);
		info->temp1 = rotr32(info->block32->w[i - 15], 18);
		info->temp2 = info->block32->w[i - 15] >> 3;
		sum0 = info->temp0 ^ info->temp1 ^ info->temp2;
		info->temp0 = rotr32(info->block32->w[i - 2], 17);
		info->temp1 = rotr32(info->block32->w[i - 2], 19);
		info->temp2 = info->block32->w[i - 2] >> 10;
		sum1 = info->temp0 ^ info->temp1 ^ info->temp2;
		info->block32->w[i] = info->block32->w[i - 16] + sum0 + sum1;
		info->block32->w[i] = info->block32->w[i] + info->block32->w[i - 7];
		i++;
	}
}

static void	sha256_calc(t_info *info, uint32_t sum0, uint32_t sum1, int i)
{
	info->temp0 = info->block32->e & info->block32->f;
	info->temp1 = (~info->block32->e) & info->block32->g;
	info->temp2 = info->temp0 ^ info->temp1;
	info->temp3 = info->block32->h + sum1 + info->temp2;
	info->temp3 += g_sha256_consts[i] + info->block32->w[i];
	info->temp0 = info->block32->a & info->block32->b;
	info->temp1 = info->block32->a & info->block32->c;
	info->temp2 = info->block32->b & info->block32->c;
	info->temp0 = info->temp0 ^ info->temp1 ^ info->temp2;
	info->temp4 = sum0 + info->temp0;
	info->block32->h = info->block32->g;
	info->block32->g = info->block32->f;
	info->block32->f = info->block32->e;
	info->block32->e = info->block32->d + info->temp3;
	info->block32->d = info->block32->c;
	info->block32->c = info->block32->b;
	info->block32->b = info->block32->a;
	info->block32->a = info->temp3 + info->temp4;
}

static void	sha256_prepare_blocks(t_info *info)
{
	uint32_t	sum0;
	uint32_t	sum1;
	int			i;

	i = 0;
	while (i < 64)
	{
		info->temp0 = rotr32(info->block32->e, 6);
		info->temp1 = rotr32(info->block32->e, 11);
		info->temp2 = rotr32(info->block32->e, 25);
		sum1 = info->temp0 ^ info->temp1 ^ info->temp2;
		info->temp0 = rotr32(info->block32->a, 2);
		info->temp1 = rotr32(info->block32->a, 13);
		info->temp2 = rotr32(info->block32->a, 22);
		sum0 = info->temp0 ^ info->temp1 ^ info->temp2;
		sha256_calc(info, sum0, sum1, i);
		i++;
	}
}

void		sha256_move_blocks(t_info *info)
{
	info->block32->a = info->var_h[0];
	info->block32->b = info->var_h[1];
	info->block32->c = info->var_h[2];
	info->block32->d = info->var_h[3];
	info->block32->e = info->var_h[4];
	info->block32->f = info->var_h[5];
	info->block32->g = info->var_h[6];
	info->block32->h = info->var_h[7];
	sha256_prepare_blocks(info);
	info->var_h[0] += info->block32->a;
	info->var_h[1] += info->block32->b;
	info->var_h[2] += info->block32->c;
	info->var_h[3] += info->block32->d;
	info->var_h[4] += info->block32->e;
	info->var_h[5] += info->block32->f;
	info->var_h[6] += info->block32->g;
	info->var_h[7] += info->block32->h;
	free(info->block32->w);
}

void		sha256_set_result(t_info *info)
{
	info->result = ft_sprintf("%08x%08x%08x%08x%08x%08x%08x%08x",
		info->var_h[0],
		info->var_h[1],
		info->var_h[2],
		info->var_h[3],
		info->var_h[4],
		info->var_h[5],
		info->var_h[6],
		info->var_h[7]);
}
