/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_section_64.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 17:04:13 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/29 20:45:59 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

struct section_64 *
get_section_64(void *ptr, const struct macho_info *macho)
{
	struct section_64 *sect;

	if (ptr + sizeof(struct section_64) > macho->ptr + macho->size)
		return (NULL);
	sect = (struct section_64 *)ptr;
	if (macho->is_rev) {
		sect->addr = OSSwapConstInt64(sect->addr);
		sect->size = OSSwapConstInt64(sect->size);
		sect->offset = OSSwapConstInt32(sect->offset);
		sect->align = OSSwapConstInt32(sect->align);
		sect->reloff = OSSwapConstInt32(sect->reloff);
		sect->nreloc = OSSwapConstInt32(sect->nreloc);
		sect->flags = OSSwapConstInt32(sect->flags);
		sect->reserved1 = OSSwapConstInt32(sect->reserved1);
		sect->reserved2 = OSSwapConstInt32(sect->reserved2);
		sect->reserved3 = OSSwapConstInt32(sect->reserved3);
	}
	dprintf(2, "= SECTION_64 =\n");
	dprintf(2, "%.16s\n", sect->sectname);
	dprintf(2, "%.16s\n", sect->segname);
	dprintf(2, "%.16llx\n", sect->addr);
	dprintf(2, "%.16llx\n", sect->size);
	dprintf(2, "%.8x\n", sect->offset);
	dprintf(2, "%.8x\n", sect->align);
	dprintf(2, "%.8x\n", sect->reloff);
	dprintf(2, "%.8x\n", sect->nreloc);
	dprintf(2, "%.8x\n", sect->flags);
	dprintf(2, "%.8x\n", sect->reserved1);
	dprintf(2, "%.8x\n", sect->reserved2);
	dprintf(2, "%.8x\n", sect->reserved3);
	if (sect->addr + sect->size > (uint64_t)macho->ptr + macho->size)
		return (NULL);
	return (sect);
}
