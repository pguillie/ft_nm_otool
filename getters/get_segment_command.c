/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_segment_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 16:58:00 by pguillie          #+#    #+#             */
/*   Updated: 2019/02/02 15:50:16 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

struct segment_command *
get_segment_command(void *ptr, const struct macho_info *macho)
{
	struct segment_command *seg;

	if (ptr + sizeof(struct segment_command) > macho->ptr + macho->size)
		return (NULL);
	seg = (struct segment_command *)ptr;
	if (macho->is_rev) {
		seg->vmaddr = OSSwapConstInt32(seg->vmaddr);
		seg->vmsize = OSSwapConstInt32(seg->vmsize);
		seg->fileoff = OSSwapConstInt32(seg->fileoff);
		seg->filesize = OSSwapConstInt32(seg->filesize);
		seg->maxprot = OSSwapConstInt32(seg->maxprot);
		seg->initprot = OSSwapConstInt32(seg->initprot);
		seg->nsects = OSSwapConstInt32(seg->nsects);
		seg->flags = OSSwapConstInt32(seg->flags);
	}
	dprintf(3, "== SEGMENT_COMMAND ==\n");
	dprintf(3, "%.16s\n", seg->segname);
	dprintf(3, "%.8x\n", seg->vmaddr);
	dprintf(3, "%.8x\n", seg->vmsize);
	dprintf(3, "%.8x\n", seg->fileoff);
	dprintf(3, "%.8x\n", seg->filesize);
	dprintf(3, "%.8x\n", seg->maxprot);
	dprintf(3, "%.8x\n", seg->initprot);
	dprintf(3, "%.8x\n", seg->nsects);
	dprintf(3, "%.8x\n", seg->flags);
	return (seg);
}
