/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdomansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 14:31:36 by bdomansk          #+#    #+#             */
/*   Updated: 2020/02/23 14:31:38 by bdomansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

uint32_t	rotr32(uint32_t word, uint32_t offset)
{
	uint32_t	temp1;
	uint32_t	temp0;

	temp0 = word >> offset;
	temp1 = word << (32 - offset);
	return (temp0 | temp1);
}
