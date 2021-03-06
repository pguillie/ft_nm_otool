/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mach_header.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:19:06 by pguillie          #+#    #+#             */
/*   Updated: 2019/02/08 15:38:13 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmacho.h"

struct mach_header *
get_mach_header(const struct macho_info *macho)
{
	struct mach_header *header;

	if (sizeof(struct mach_header) > macho->size)
		return (NULL);
	header = (struct mach_header *)macho->ptr;
	if (macho->is_rev) {
		header->magic = OSSwapConstInt32(header->magic);
		header->cputype = OSSwapConstInt32(header->cputype);
		header->cpusubtype = OSSwapConstInt32(header->cpusubtype);
		header->filetype = OSSwapConstInt32(header->filetype);
		header->ncmds = OSSwapConstInt32(header->ncmds);
		header->sizeofcmds = OSSwapConstInt32(header->sizeofcmds);
		header->flags = OSSwapConstInt32(header->flags);
	}
	dprintf(3, "=== MACH_HEADER ===\n");
	dprintf(3, "%.8x\n", header->magic);
	dprintf(3, "%.8x\n", header->cputype);
	dprintf(3, "%.8x\n", header->cpusubtype);
	dprintf(3, "%.8x\n", header->filetype);
	dprintf(3, "%.8x\n", header->ncmds);
	dprintf(3, "%.8x\n", header->sizeofcmds);
	dprintf(3, "%.8x\n", header->flags);
	if (header->sizeofcmds > macho->size)
		return (NULL);
	return (header);
}
