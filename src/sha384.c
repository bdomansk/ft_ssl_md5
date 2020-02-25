/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha384.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 20:26:01 by bdomansk          #+#    #+#             */
/*   Updated: 2020/02/25 20:26:02 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void	sha384_init_var_h(t_info *info)
{
	info->v_h[0] = 0xcbbb9d5dc1059ed8;
	info->v_h[1] = 0x629a292a367cd507;
	info->v_h[2] = 0x9159015a3070dd17;
	info->v_h[3] = 0x152fecd8f70e5939;
	info->v_h[4] = 0x67332667ffc00b31;
	info->v_h[5] = 0x8eb44a8768581511;
	info->v_h[6] = 0xdb0c2e0d64f98fa7;
	info->v_h[7] = 0x47b5481dbefa4fa4;
}

static void	sha384_set_result(t_info *info)
{
	char *pattern;

	pattern = "%016llx%016llx%016llx%016llx%016llx%016llx";
	info->result = ft_sprintf(pattern,
		info->v_h[0],
		info->v_h[1],
		info->v_h[2],
		info->v_h[3],
		info->v_h[4],
		info->v_h[5]);
}

void		sha384(void *data)
{
	t_info	*info;

	info = data;
	sha384_init_var_h(info);
	sha512_fill_message(info);
	sha512_main_cycle(info);
	sha384_set_result(info);
}
