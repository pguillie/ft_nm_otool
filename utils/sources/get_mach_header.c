/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mach_header.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:19:06 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/17 18:13:00 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mach-o/loader.h>
#include <stddef.h>

# define REV_BYTE_ORDER 1

struct mach_header *
get_mach_header(void *ptr, void *boundary)
{
	struct mach_header	*header;
	int			rev;

	rev = (uint32_t)boundary & REV_BYTE_ORDER;
	boundary = (uint32_t)boundary & ~REV_BYTE_ORDER;
	if (ptr + sizeof(struct mach_header) > boundary)
		return (NULL);
	header = (struct mach_header *)ptr;
	if (rev) {
		header->magic = OSSwapConstInt32(header->magic);
		header->cputype = OSSwapConstInt32(header->cputype);
		header->cpusubtype = OSSwapConstInt32(header->cpusubtype);
		header->filetype = OSSwapConstInt32(header->filetype);
		header->ncmds = OSSwapConstInt32(header->ncmds);
		header->sizeofcmds = OSSwapConstInt32(header->sizeofcmds);
		header->flags = OSSwapConstInt32(header->flags);
	}
	if (ptr + header->sizeofcmds > boundary)
		return (NULL);
	return (header);
}
