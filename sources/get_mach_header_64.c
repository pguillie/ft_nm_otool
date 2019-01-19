/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mach_header_64.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:19:06 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/19 20:11:47 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

struct mach_header_64 *
get_mach_header_64(struct macho_info const macho)
{
	struct mach_header_64	*header;

	if (sizeof(struct mach_header_64) > macho.size)
		return (NULL);
	header = (struct mach_header_64 *)macho.ptr;
	if (macho.is_rev) {
		header->magic = OSSwapConstInt32(header->magic);
		header->cputype = OSSwapConstInt32(header->cputype);
		header->cpusubtype = OSSwapConstInt32(header->cpusubtype);
		header->filetype = OSSwapConstInt32(header->filetype);
		header->ncmds = OSSwapConstInt32(header->ncmds);
		header->sizeofcmds = OSSwapConstInt32(header->sizeofcmds);
		header->flags = OSSwapConstInt32(header->flags);
		header->reserved = OSSwapConstInt32(header->reserved);
	}
	if (header->sizeofcmds > macho.size)
		return (NULL);
	return (header);
}
