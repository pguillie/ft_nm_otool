/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_segment_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 16:58:00 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/18 19:12:27 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

struct segment_command *
get_segment_command(void *ptr, struct macho_info macho)
{
	struct segment_command	*seg;

	if (ptr + sizeof(struct segment_command) > macho.ptr + macho.size)
		return (NULL);
	seg = (struct segment_command *)ptr;
	if (macho.is_rev) {
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
