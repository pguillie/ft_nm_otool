/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_mach_header_64.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:49:50 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/22 15:34:03 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static ssize_t
nm_section_64(struct segment_command_64 *seg, ssize_t sectx, struct macho_info *macho)
{
	struct section_64	*sect;
	size_t			nsects;

	if (get_segment_command_64(seg, *macho) == NULL)
		return (-1);
	sect = (void *)seg + sizeof(struct segment_command_64);
	nsects = seg->nsects;
	while (nsects--) {
		if (get_section_64(sect, *macho) == NULL)
			return (-1);
		if (ft_strcmp(sect->sectname, "__text") == 0
			&& ft_strcmp(sect->segname, "__TEXT") == 0)
			macho->text_sect = sectx;
		else if (ft_strcmp(sect->sectname, "__data") == 0
			&& ft_strcmp(sect->segname, "__DATA") == 0)
			macho->data_sect = sectx;
		else if (ft_strcmp(sect->sectname, "__bss") == 0
			&& ft_strcmp(sect->segname, "__DATA") == 0)
			macho->bss_sect = sectx;
		sect++;
		sectx++;
	}
	return (sectx);
}

static struct symtab_command *
get_lc_symtab(struct load_command *lc, size_t ncmds, struct macho_info *macho)
{
	struct symtab_command	*sym;
	ssize_t			sectx;

	sym = NULL;
	sectx = 1;
	while (ncmds--) {
		if (get_load_command(lc, *macho) == NULL)
			return (NULL);
		if (lc->cmd == LC_SYMTAB)
			sym = (struct symtab_command *)lc;
		else if (lc->cmd == LC_SEGMENT_64)
			sectx = nm_section_64((void *)lc, sectx, macho);
		if (sectx < 0)
			return (NULL);
		lc = (void *)lc + lc->cmdsize;
	}
	return (sym);
}

int
nm_mach_header_64(struct macho_info macho)
{
	struct mach_header_64	*header;
	struct symtab_command	*lc_symtab;

	if ((header = get_mach_header_64(macho)) == NULL)
		return (-1);
	if ((lc_symtab = get_lc_symtab(macho.ptr + sizeof(struct mach_header_64),
		header->ncmds, &macho)) == NULL)
		return (-1);
	return (nm_symtab_64(lc_symtab, macho));
}
