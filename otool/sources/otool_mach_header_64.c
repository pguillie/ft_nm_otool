/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_mach_header_64.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:49:50 by pguillie          #+#    #+#             */
/*   Updated: 2019/02/06 21:30:57 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

static ssize_t
otool_section_64(struct segment_command_64 *seg, struct macho_info *macho,
	struct section_64 **text)
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
		if (ft_strcmp(sect->sectname, "__text") == 0
			&& ft_strcmp(sect->segname, "__TEXT") == 0) {
			*text = sect;
			break ;
		}
		sect++;
	}
	return (0);
}

static int
otool_mach_text(struct load_command *lc, size_t ncmds,
	struct macho_info *macho, struct section_64 **text)
{
	while (ncmds--) {
		if (get_load_command(lc, macho) == NULL)
			return (1);
		if (lc->cmd == LC_SEGMENT_64
			&& otool_section_64((void *)lc, macho, text))
			return (1);
		if (*text)
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
	struct section_64 *text;

	if ((header = get_mach_header_64(macho)) == NULL)
		return (1);
	macho->cpu = header->cputype;
	text = NULL;
	lc = macho->ptr + sizeof(struct mach_header_64);
	if (otool_mach_text(lc, header->ncmds, macho, &text))
		return (1);
	return (otool_text_64(text, macho));
}
