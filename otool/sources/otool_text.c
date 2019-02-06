/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:01:34 by pguillie          #+#    #+#             */
/*   Updated: 2019/02/06 21:48:32 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

static int
otool_hexa(int digit)
{
	return (digit > 9 ? digit - 10 + 'a' : digit + '0');
}

static void
otool_address(uint32_t addr, struct macho_info *macho)
{
	char tmp[8];
	uint32_t i;

	i = 8;
	while (i--) {
		tmp[i] = otool_hexa(addr % 16);
		addr /= 16;
	}
	buf_in(macho, tmp, 8);
}

static void
otool_content(void *ptr, uint32_t n, struct macho_info *macho)
{
	char tmp[48];
	uint32_t i;

	i = 0;
	while (n--) {
		tmp[i++] = otool_hexa(*(unsigned char *)ptr / 16);
		tmp[i++] = otool_hexa(*(unsigned char *)ptr % 16);
		if (macho->cpu == CPU_TYPE_X86 || macho->cpu == CPU_TYPE_I386
			|| macho->cpu == CPU_TYPE_X86_64 || n % 4 == 0)
			tmp[i++] = ' ';
		ptr++;
	}
	buf_in(macho, tmp, i);
}

int
otool_text(struct section *text, struct macho_info *macho)
{
	void *ptr;
	uint32_t i;
	uint32_t size;

	if (text) {
		buf_in(macho, "Contents of (__TEXT,__text) section\n", 36);
		if (text->offset + text->size > macho->size)
			return (-1);
		ptr = macho->ptr + text->offset;
		size = text->size;
		i = 0;
		while (i < text->size)
		{
			otool_address(text->addr + i, macho);
			buf_in(macho, "\t", 1);
			otool_content(ptr + i, size > 16 ? 16 : size, macho);
			buf_in(macho, "\n", 1);
			i += 16;
			size -= 16;
		}
	}
	buf_out(macho);
	return (0);
}
