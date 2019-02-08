/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_section.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 17:04:13 by pguillie          #+#    #+#             */
/*   Updated: 2019/02/08 15:38:51 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmacho.h"

//addr or offset ?
struct section *
get_section(void *ptr, const struct macho_info *macho)
{
	struct section *sect;

	if (ptr + sizeof(struct section) > macho->ptr + macho->size)
		return (NULL);
	sect = (struct section *)ptr;
	if (macho->is_rev) {
		sect->addr = OSSwapConstInt32(sect->addr);
		sect->size = OSSwapConstInt32(sect->size);
		sect->offset = OSSwapConstInt32(sect->offset);
		sect->align = OSSwapConstInt32(sect->align);
		sect->reloff = OSSwapConstInt32(sect->reloff);
		sect->nreloc = OSSwapConstInt32(sect->nreloc);
		sect->flags = OSSwapConstInt32(sect->flags);
		sect->reserved1 = OSSwapConstInt32(sect->reserved1);
		sect->reserved2 = OSSwapConstInt32(sect->reserved2);
	}
	dprintf(3, "= SECTION =\n");
	dprintf(3, "%.16s\n", sect->sectname);
	dprintf(3, "%.16s\n", sect->segname);
	dprintf(3, "%.8x\n", sect->addr);
	dprintf(3, "%.8x\n", sect->size);
	dprintf(3, "%.8x\n", sect->offset);
	dprintf(3, "%.8x\n", sect->align);
	dprintf(3, "%.8x\n", sect->reloff);
	dprintf(3, "%.8x\n", sect->nreloc);
	dprintf(3, "%.8x\n", sect->flags);
	dprintf(3, "%.8x\n", sect->reserved1);
	dprintf(3, "%.8x\n", sect->reserved2);
	return (sect);
}
