/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_section.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 17:04:13 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/29 19:28:08 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

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
	dprintf(2, "= SECTION =\n");
	dprintf(2, "%.16s\n", sect->sectname);
	dprintf(2, "%.16s\n", sect->segname);
	dprintf(2, "%.8x\n", sect->addr);
	dprintf(2, "%.8x\n", sect->size);
	dprintf(2, "%.8x\n", sect->offset);
	dprintf(2, "%.8x\n", sect->align);
	dprintf(2, "%.8x\n", sect->reloff);
	dprintf(2, "%.8x\n", sect->nreloc);
	dprintf(2, "%.8x\n", sect->flags);
	dprintf(2, "%.8x\n", sect->reserved1);
	dprintf(2, "%.8x\n", sect->reserved2);
	if (sect->addr + sect->size > (uint32_t)macho->ptr + macho->size)
		return (NULL);
	return (sect);
}
