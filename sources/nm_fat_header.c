/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_fat_header.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 18:37:56 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/29 22:14:49 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

// static ssize_t
// get_default_arch(struct fat_arch **arch, uint32_t n, struct macho_info *macho)
// {
// 	uint32_t i;

// 	i = 0;
// 	while (i++ < n) {
// 		if (get_fat_arch(*arch, macho) == NULL)
// 			return (0);
// 		if ((*arch)->cputype == CPU_TYPE_X86_64)
// 			return (1);
// 		(*arch)++;
// 	}
// 	*arch = NULL;
// 	return (1);
// }

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

	// if (get_default_arch(&arch, header->nfat_arch, macho) == 0)
	// 	return (-1);
	// if (arch) {
	// 	foo.ptr = macho.ptr + arch->offset;
	// 	foo.size = arch->size;
	// 	return (nm_check_header(foo));
	// }
	// arch = /* (void *) */macho.ptr + sizeof(struct fat_header);
	// i = 0;
	// while (i++ < header->nfat_arch) {
	// 	//name
	// 	foo.ptr = macho.ptr + arch->offset;
	// 	foo.size = arch->size;
	// 	//ret
	// 	nm_check_header(foo);
	// 	arch++;
	// }
	// return (0); //ret
}
