/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 12:24:46 by bdomansk          #+#    #+#             */
/*   Updated: 2020/02/23 12:24:48 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

uint32_t	swap_bits_32(uint32_t var)
{
	uint32_t	result;
	uint32_t	var_1;
	uint32_t	var_2;
	uint32_t	var_3;
	uint32_t	var_4;

	var_1 = (var >> 24) & 0xff;
	var_2 = (var << 8) & 0xff0000;
	var_3 = (var >> 8) & 0xff00;
	var_4 = (var << 24) & 0xff000000;
	result = var_1 | var_2 | var_3 | var_4;
	return (result);
}

uint64_t	swap_bits_64(uint64_t var)
{
	uint64_t	result;
	uint64_t	v1;
	uint64_t	v2;
	uint64_t	v3;
	uint64_t	v4;
	uint64_t	v5;
	uint64_t	v6;
	uint64_t	v7;
	uint64_t	v8;

	v1 = (var & 0xFF00000000000000) >> 56;
	v2 = (var & 0x00FF000000000000) >> 40;
	v3 = (var & 0x0000FF0000000000) >> 24;
	v4 = (var & 0x000000FF00000000) >> 8;
	v5 = (var & 0x00000000FF000000) << 8;
	v6 = (var & 0x0000000000FF0000) << 24;
	v7 = (var & 0x000000000000FF00) << 40;
	v8 = (var & 0x00000000000000FF) << 56;
	result = v1 | v2 | v3 | v4 | v5 | v6 | v7 | v8;
	return (result);
}

uint32_t	swap_bits_md5(uint32_t var)
{
	uint32_t	result;
	uint32_t	var_1;
	uint32_t	var_2;
	uint32_t	var_3;
	uint32_t	var_4;

	var_1 = var >> 24;
	var_2 = (var >> 8) & 0xff00;
	var_3 = (var << 8) & 0xff0000;
	var_4 = (var << 24);
	result = var_1 | var_2 | var_3 | var_4;
	return (result);
}
