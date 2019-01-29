/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fat_arch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 13:19:58 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/29 20:52:13 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

struct fat_arch *
get_fat_arch(void *ptr, const struct macho_info *macho)
{
	struct fat_arch	*arch;

	if (ptr + sizeof(struct fat_arch) > macho->ptr + macho->size)
		return (NULL);
	arch = (struct fat_arch *)ptr;
	if (macho->is_rev) {
		arch->cputype = OSSwapConstInt32(arch->cputype);
		arch->cpusubtype = OSSwapConstInt32(arch->cpusubtype);
		arch->offset = OSSwapConstInt32(arch->offset);
		arch->size = OSSwapConstInt32(arch->size);
		arch->align = OSSwapConstInt32(arch->align);
	}
	dprintf(2, "=== FAT_ARCH ===\n");
	dprintf(2, "%.8x\n", arch->cputype);
	dprintf(2, "%.8x\n", arch->cpusubtype);
	dprintf(2, "%.8x\n", arch->offset);
	dprintf(2, "%.8x\n", arch->size);
	dprintf(2, "%.8x\n", arch->align);
	if (arch->offset + arch->size > macho->size)
		return (NULL);
	return (arch);
}
