/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_section_64.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 17:04:13 by pguillie          #+#    #+#             */
/*   Updated: 2019/02/02 15:51:06 by pguillie         ###   ########.fr       */
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
	dprintf(3, "= SECTION_64 =\n");
	dprintf(3, "%.16s\n", sect->sectname);
	dprintf(3, "%.16s\n", sect->segname);
	dprintf(3, "%.16llx\n", sect->addr);
	dprintf(3, "%.16llx\n", sect->size);
	dprintf(3, "%.8x\n", sect->offset);
	dprintf(3, "%.8x\n", sect->align);
	dprintf(3, "%.8x\n", sect->reloff);
	dprintf(3, "%.8x\n", sect->nreloc);
	dprintf(3, "%.8x\n", sect->flags);
	dprintf(3, "%.8x\n", sect->reserved1);
	dprintf(3, "%.8x\n", sect->reserved2);
	dprintf(3, "%.8x\n", sect->reserved3);
	return (sect);
}
