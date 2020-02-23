/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha224.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 21:38:08 by bdomansk          #+#    #+#             */
/*   Updated: 2020/02/23 21:38:10 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void	sha224_init_var_h(t_info *info)
{
	info->var_h[0] = 0xc1059ed8;
	info->var_h[1] = 0x367cd507;
	info->var_h[2] = 0x3070dd17;
	info->var_h[3] = 0xf70e5939;
	info->var_h[4] = 0xffc00b31;
	info->var_h[5] = 0x68581511;
	info->var_h[6] = 0x64f98fa7;
	info->var_h[7] = 0xbefa4fa4;
}

static void	sha224_set_result(t_info *info)
{
	info->result = ft_sprintf("%08x%08x%08x%08x%08x%08x%08x",
		info->var_h[0],
		info->var_h[1],
		info->var_h[2],
		info->var_h[3],
		info->var_h[4],
		info->var_h[5],
		info->var_h[6]);
}

void		sha224(void *data)
{
	t_info	*info;

	info = data;
	sha224_init_var_h(info);
	sha256_fill_message(info);
	sha256_main_cycle(info);
	sha224_set_result(info);
}