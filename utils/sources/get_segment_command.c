/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_segment_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 16:58:00 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/17 18:14:20 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mach-o/loader.h>
#include <stddef.h>

# define REV_BYTE_ORDER 1

struct segment_command *
get_segment_command(void *ptr, void *boundary)
{
	struct segment_command	*seg;
	int			rev;

	rev = (uint32_t)boundary & REV_BYTE_ORDER;
	boundary = (uint32_t)boundary & ~REV_BYTE_ORDER;
	if (ptr + sizeof(struct segment_command) > boundary)
		return (NULL);
	seg = (struct segment_command *)ptr;
	if (rev) {
		seg->vmaddr = OSSwapConstInt32(seg->vmaddr);
		seg->vmsize = OSSwapConstInt32(seg->vmsize);
		seg->fileoff = OSSwapConstInt32(seg->fileoff);
		seg->filesize = OSSwapConstInt32(seg->filesize);
		seg->maxprot = OSSwapConstInt32(seg->maxprot);
		seg->initprot = OSSwapConstInt32(seg->initprot);
		seg->nsects = OSSwapConstInt32(seg->nsects);
		seg->flags = OSSwapConstInt32(seg->flags);
	}
	return (seg);
}
