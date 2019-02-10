/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_mach_header_64.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:49:50 by pguillie          #+#    #+#             */
/*   Updated: 2019/02/10 19:11:01 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

static int
otool_section_64(struct segment_command_64 *seg, struct macho_info *macho,
	struct section_64 **sect_ptr)
{
	struct section_64 *sect;
	size_t nsects;

	if (get_segment_command_64(seg, macho) == NULL)
		return (-1);
	sect = (void *)seg + sizeof(struct segment_command_64);
	nsects = seg->nsects;
	while (nsects--) {
		if (get_section_64(sect, macho) == NULL)
			return (-1);
		if (((macho->opt & OPT_T)
			&& ft_strcmp(sect->sectname, "__text") == 0
			&& ft_strcmp(sect->segname, "__TEXT") == 0)
			|| ((macho->opt & OPT_D)
			&& ft_strcmp(sect->sectname, "__data") == 0
			&& ft_strcmp(sect->segname, "__DATA") == 0)) {
			*sect_ptr = sect;
			break ;
		}
		sect++;
	}
	return (0);
}

static int
otool_mach_sect(struct load_command *lc, size_t ncmds,
	struct macho_info *macho, struct section_64 **sect_ptr)
{
	while (ncmds--) {
		if (get_load_command(lc, macho) == NULL)
			return (1);
		if (lc->cmd == LC_SEGMENT_64
			&& otool_section_64((void *)lc, macho, sect_ptr))
			return (1);
		if (*sect_ptr)
			break ;
		lc = (void *)lc + lc->cmdsize;
	}
	return (0);
}

int
otool_mach_header_64(struct macho_info *macho)
{
	struct mach_header_64 *header;
	struct load_command *lc;
	struct section_64 *sect;

	if ((header = get_mach_header_64(macho)) == NULL)
		return (1);
	if (macho->opt & OPT_D || macho->opt & OPT_T) {
		sect = NULL;
		lc = macho->ptr + sizeof(struct mach_header_64);
		if (otool_mach_sect(lc, header->ncmds, macho, &sect))
			return (1);
		macho->cpu = header->cputype;
		return (otool_sect_64(sect, macho));
	}
	return (0);
}
