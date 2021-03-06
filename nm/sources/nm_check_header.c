/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_check_header.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:35:34 by pguillie          #+#    #+#             */
/*   Updated: 2019/02/02 15:16:59 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static int
nm_check_mach_header(struct macho_info *macho)
{
	uint32_t magic;

	magic = *(uint32_t *)macho->ptr;
	if (magic == MH_MAGIC)
		macho->is_rev = 0;
	else if (magic == MH_CIGAM)
		macho->is_rev = 1;
	else
		return (0);
	dprintf(3, "%s\n", macho->is_rev ? "cigam" : "magic");
	return (1);
}

static int
nm_check_mach_header_64(struct macho_info *macho)
{
	uint32_t magic;

	magic = *(uint32_t *)macho->ptr;
	if (magic == MH_MAGIC_64)
		macho->is_rev = 0;
	else if (magic == MH_CIGAM_64)
		macho->is_rev = 1;
	else
		return (0);
	dprintf(3, "%s\n", macho->is_rev ? "cigam_64" : "magic_64");
	return (1);
}

static int
nm_check_fat_header(struct macho_info *macho)
{
	uint32_t magic;

	magic = *(uint32_t *)macho->ptr;
	if (magic == FAT_MAGIC)
		macho->is_rev = 0;
	else if (magic == FAT_CIGAM)
		macho->is_rev = 1;
	else
		return (0);
	dprintf(3, "%s\n", macho->is_rev ? "fat_cigam" : "fat_magic");
	return (1);
}

static int
nm_check_arch_header(struct macho_info *macho)
{
	if (ft_strncmp(macho->ptr, ARMAG, SARMAG) == 0)
		macho->is_rev = 0;
	else
		return (0);
	dprintf(3, "archive\n");
	return (1);
}

int
nm_check_header(struct macho_info *macho)
{
	if (nm_check_mach_header(macho))
		return (nm_mach_header(macho));
	else if (nm_check_mach_header_64(macho))
		return (nm_mach_header_64(macho));
	else if (nm_check_fat_header(macho))
		return (nm_fat_header(macho));
	else if (nm_check_arch_header(macho))
		return (nm_arch_header(macho));
	return (2);
}
//multi layer error !!!
