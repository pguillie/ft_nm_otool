/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_mach_header.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:49:50 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/29 20:26:37 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static ssize_t
nm_section(struct segment_command *seg, ssize_t sectx, struct macho_info *macho)
{
	struct section *sect;
	size_t nsects;

	if (get_segment_command(seg, macho) == NULL)
		return (-1);
	sect = (void *)seg + sizeof(struct segment_command);
	nsects = seg->nsects;
	while (nsects--) {
		if (get_section(sect, macho) == NULL)
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

//real nm doesn't return an error if no SYMTAB is found
static struct symtab_command *
get_lc_symtab(struct load_command *lc, size_t ncmds, struct macho_info *macho)
{
	struct symtab_command *sym;
	ssize_t sectx;

	sym = NULL;
	sectx = 1;
	while (ncmds--) {
		if (get_load_command(lc, macho) == NULL)
			return (NULL);
		if (lc->cmd == LC_SYMTAB)
			sym = (struct symtab_command *)lc;
		else if (lc->cmd == LC_SEGMENT)
			sectx = nm_section((void *)lc, sectx, macho);
		if (sectx < 0)
			return (NULL);
		lc = (void *)lc + lc->cmdsize;
	}
	return (sym);
}

int
nm_mach_header(struct macho_info *macho)
{
	struct mach_header *header;
	struct symtab_command *lc_symtab;

	if ((header = get_mach_header(macho)) == NULL)
		return (-1);
	lc_symtab = get_lc_symtab(macho->ptr + sizeof(struct mach_header),
		header->ncmds, macho);
	if (lc_symtab == NULL)
		return (-1);
	return (nm_symtab(lc_symtab, macho));
}
