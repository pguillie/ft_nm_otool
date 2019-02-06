/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_segment_command_64.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 16:58:00 by pguillie          #+#    #+#             */
/*   Updated: 2019/02/02 15:49:02 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

struct segment_command_64 *
get_segment_command_64(void *ptr, const struct macho_info *macho)
{
	struct segment_command_64 *seg;

	if (ptr + sizeof(struct segment_command_64) > macho->ptr + macho->size)
		return (NULL);
	seg = (struct segment_command_64 *)ptr;
	if (macho->is_rev) {
		seg->vmaddr = OSSwapConstInt64(seg->vmaddr);
		seg->vmsize = OSSwapConstInt64(seg->vmsize);
		seg->fileoff = OSSwapConstInt64(seg->fileoff);
		seg->filesize = OSSwapConstInt64(seg->filesize);
		seg->maxprot = OSSwapConstInt32(seg->maxprot);
		seg->initprot = OSSwapConstInt32(seg->initprot);
		seg->nsects = OSSwapConstInt32(seg->nsects);
		seg->flags = OSSwapConstInt32(seg->flags);
	}
	dprintf(3, "== SEGMENT_COMMAND_64 ==\n");
	dprintf(3, "%.16s\n", seg->segname);
	dprintf(3, "%.16llx\n", seg->vmaddr);
	dprintf(3, "%.16llx\n", seg->vmsize);
	dprintf(3, "%.16llx\n", seg->fileoff);
	dprintf(3, "%.16llx\n", seg->filesize);
	dprintf(3, "%.8x\n", seg->maxprot);
	dprintf(3, "%.8x\n", seg->initprot);
	dprintf(3, "%.8x\n", seg->nsects);
	dprintf(3, "%.8x\n", seg->flags);
	return (seg);
}
