/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_sect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:01:34 by pguillie          #+#    #+#             */
/*   Updated: 2019/02/11 17:34:06 by pguillie         ###   ########.fr       */
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
	uint32_t j;

	i = 0;
	j = 0;
	while (i++ < n) {
		tmp[j++] = otool_hexa(*(unsigned char *)ptr / 16);
		tmp[j++] = otool_hexa(*(unsigned char *)ptr % 16);
		if (macho->cpu == CPU_TYPE_X86 || macho->cpu == CPU_TYPE_I386
			|| macho->cpu == CPU_TYPE_X86_64 || i % 4 == 0)
			tmp[j++] = ' ';
		ptr++;
	}
	buf_in(macho, tmp, j);
}

static void
otool_sect_descr(struct section *sect, struct macho_info *macho)
{
	buf_in(macho, "Contents of (", 13);
	buf_in(macho, sect->segname, ft_strlen(sect->segname));
	buf_in(macho, ",", 1);
	buf_in(macho, sect->sectname, ft_strlen(sect->sectname));
	buf_in(macho, ") section\n", 10);
}

int
otool_sect(struct section *sect, struct macho_info *macho)
{
	void *ptr;
	uint32_t i;
	uint32_t size;

	if (sect) {
		otool_sect_descr(sect, macho);
		if (sect->offset + sect->size > macho->size)
			return (1);
		ptr = macho->ptr + sect->offset;
		size = sect->size;
		i = 0;
		while (i < sect->size) {
			otool_address(sect->addr + i, macho);
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
