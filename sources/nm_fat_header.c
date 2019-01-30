/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_fat_header.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 18:37:56 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/30 14:18:08 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static ssize_t
get_arch(struct fat_arch *arch_hdr, uint32_t narch, const struct macho_info *macho)
{
	uint32_t i;

	i = 0;
	while (i < narch) {
		if (get_fat_arch(arch_hdr, macho) == NULL)
			return (-1);
		if (arch_hdr->cputype == CPU_TYPE_X86_64)
			break ;
		arch_hdr++;
		i++;
	}
	return (i);
}

static int
nm_fat_arch(struct fat_arch *arch_hdr, const struct macho_info *macho)
{
	struct macho_info arch;

	arch.ptr = macho->ptr + arch_hdr->offset;
	arch.size = arch_hdr->size;
	return (nm_check_header(&arch));
}

int
nm_fat_header(struct macho_info *macho)
{
	struct fat_header *header;
	struct fat_arch *arch_hdr;
	ssize_t i;

	if ((header = get_fat_header(macho)) == NULL)
		return (-1);
	arch_hdr = macho->ptr + sizeof(struct fat_header);
	if ((i = get_arch(arch_hdr, header->nfat_arch, macho)) < 0)
		return (-1);
	if (i == header->nfat_arch) {
		while (i--) {
			nm_fat_arch(arch_hdr, macho);
			arch_hdr++;
		}
	} else {
		while (i--)
			arch_hdr++;
		nm_fat_arch(arch_hdr, macho);
	}
	return (0); //TODO return value
}
