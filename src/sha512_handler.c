/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 22:37:05 by bdomansk          #+#    #+#             */
/*   Updated: 2020/02/23 22:37:07 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "sha512.h"

void		sha512_fill_block(t_info *info, int position)
{
	int			i;
	uint64_t	sum0;
	uint64_t	sum1;

	i = 16;
	info->block64->w = (uint64_t *)malloc(80 * 8 * sizeof(uint64_t));
	ft_bzero(info->block64->w, sizeof(uint64_t) * 640);
	ft_memcpy(info->block64->w, &(info->data[16 * position]), 640);
	while (i < 80)
	{
		info->t0 = rotr64(info->block64->w[i - 15], 1);
		info->t1 = rotr64(info->block64->w[i - 15], 8);
		info->t2 = info->block64->w[i - 15] >> 7;
		sum0 = info->t0 ^ info->t1 ^ info->t2;
		info->t0 = rotr64(info->block64->w[i - 2], 19);
		info->t1 = rotr64(info->block64->w[i - 2], 61);
		info->t2 = info->block64->w[i - 2] >> 6;
		sum1 = info->t0 ^ info->t1 ^ info->t2;
		info->block64->w[i] = info->block64->w[i - 16] + sum0 + sum1;
		info->block64->w[i] = info->block64->w[i] + info->block64->w[i - 7];
		i++;
	}
}

static void	sha512_calc(t_info *info, uint64_t sum0, uint64_t sum1, int i)
{
	info->t0 = info->block64->e & info->block64->f;
	info->t1 = (~info->block64->e) & info->block64->g;
	info->t2 = info->t0 ^ info->t1;
	info->t3 = info->block64->h + sum1 + info->t2;
	info->t3 += g_sha512_consts[i] + info->block64->w[i];
	info->t0 = info->block64->a & info->block64->b;
	info->t1 = info->block64->a & info->block64->c;
	info->t2 = info->block64->b & info->block64->c;
	info->t0 = info->t0 ^ info->t1 ^ info->t2;
	info->t4 = sum0 + info->t0;
	info->block64->h = info->block64->g;
	info->block64->g = info->block64->f;
	info->block64->f = info->block64->e;
	info->block64->e = info->block64->d + info->t3;
	info->block64->d = info->block64->c;
	info->block64->c = info->block64->b;
	info->block64->b = info->block64->a;
	info->block64->a = info->t3 + info->t4;
}

static void	sha512_prepare_blocks(t_info *info)
{
	uint64_t	sum0;
	uint64_t	sum1;
	int			i;

	i = 0;
	while (i < 64)
	{
		info->t0 = rotr64(info->block64->e, 14);
		info->t1 = rotr64(info->block64->e, 18);
		info->t2 = rotr64(info->block64->e, 41);
		sum1 = info->t0 ^ info->t1 ^ info->t2;
		info->t0 = rotr64(info->block64->a, 28);
		info->t1 = rotr64(info->block64->a, 34);
		info->t2 = rotr64(info->block64->a, 39);
		sum0 = info->t0 ^ info->t1 ^ info->t2;
		sha512_calc(info, sum0, sum1, i);
		i++;
	}
}

void		sha512_move_blocks(t_info *info)
{
	info->block64->a = info->v_h[0];
	info->block64->b = info->v_h[1];
	info->block64->c = info->v_h[2];
	info->block64->d = info->v_h[3];
	info->block64->e = info->v_h[4];
	info->block64->f = info->v_h[5];
	info->block64->g = info->v_h[6];
	info->block64->h = info->v_h[7];
	sha512_prepare_blocks(info);
	info->v_h[0] += info->block64->a;
	info->v_h[1] += info->block64->b;
	info->v_h[2] += info->block64->c;
	info->v_h[3] += info->block64->d;
	info->v_h[4] += info->block64->e;
	info->v_h[5] += info->block64->f;
	info->v_h[6] += info->block64->g;
	info->v_h[7] += info->block64->h;
	free(info->block64->w);
}

void		sha512_set_result(t_info *info)
{
	char *pattern;

	pattern = "%016llx%016llx%016llx%016llx%016llx%016llx%016llx%016llx",
	info->result = ft_sprintf(pattern,
		info->v_h[0],
		info->v_h[1],
		info->v_h[2],
		info->v_h[3],
		info->v_h[4],
		info->v_h[5],
		info->v_h[6],
		info->v_h[7]);
}
