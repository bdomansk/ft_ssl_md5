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
