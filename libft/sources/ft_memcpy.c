/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 18:10:27 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/31 15:20:25 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>

void *
ft_memcpy(void *dest, const void *src, size_t n)
{
	uint64_t i;

	i = (uint64_t)n & (uint64_t)-8;
	while (n > i) {
		n -= 1;
		*(uint8_t *)(dest + n) = *(const uint8_t *)(src + n);
	}
	while (i) {
		i -= 8;
		*(uint64_t *)(dest + i) = *(const uint64_t *)(src + i);
	}
	return (dest);
}
