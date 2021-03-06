/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fat_header.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 12:49:10 by pguillie          #+#    #+#             */
/*   Updated: 2019/02/08 15:37:37 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmacho.h"

struct fat_header *
get_fat_header(const struct macho_info *macho)
{
	struct fat_header *header;

	if (sizeof(struct fat_header) > macho->size)
		return (NULL);
	header = (struct fat_header *)macho->ptr;
	if (macho->is_rev) {
		header->magic = OSSwapConstInt32(header->magic);
		header->nfat_arch = OSSwapConstInt32(header->nfat_arch);
	}
	dprintf(3, "=== FAT_HEADER ===\n");
	dprintf(3, "%.8x\n", header->magic);
	dprintf(3, "%.8x\n", header->nfat_arch);
	return (header);
}
