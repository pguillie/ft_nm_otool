/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_header.bak.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 15:10:03 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/18 18:48:07 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mach-o/loader.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <stdio.h>

int nm_sym_32(void *ptr, size_t size, struct symtab_command *sym, int *sectn);
int nm_sym_64(void *ptr, size_t size, struct symtab_command *sym, int *sectn);

static ssize_t
	nm_sect_32(void *eof, struct segment_command *seg, ssize_t idx,
	int	*sectn)
{
	size_t		i;
	struct section	*sect;

	i = 0;
	sect = (void *) seg + sizeof(struct segment_command);
	while (i < seg->nsects)
	{
		if ((void *) sect + sect->size > eof)
			return (-1);
		// replace `strcmp' -> `ft_strcmp'
		if (strcmp(sect->sectname, "__text") == 0
			&& strcmp(sect->segname, "__TEXT") == 0)
			sectn[0] = idx;
		else if (strcmp(sect->sectname, "__data") == 0
			&& strcmp(sect->segname, "__DATA") == 0)
			sectn[1] = idx;
		else if (strcmp(sect->sectname, "__bss") == 0
			&& strcmp(sect->segname, "__DATA") == 0)
			sectn[2] = idx;
		sect++;
		idx++;
		i++;
	}
	return (idx);
}

static int
	nm_header_32(void *ptr, size_t size)
{
	struct mach_header	*header;
	struct load_command	*lc;
	size_t			ncmds;
	ssize_t			sectx;
	int			sectn[3];

	header = (struct mach_header *) ptr;
	ncmds = header->ncmds;
	lc = (void *) ptr + sizeof(struct mach_header);
	sectx = 1;
	while (ncmds--)
	{
		if ((void *) lc + lc->cmdsize > ptr + size || sectx < 0)
			return (EXIT_FAILURE);
		if (lc->cmd == LC_SYMTAB)
			nm_sym_32(ptr, size, (void *) lc, sectn);
		else if (lc->cmd == LC_SEGMENT
			&& ((struct segment_command *) lc)->nsects)
			sectx = nm_sect_32(ptr + size, (void *) lc, sectx, sectn);
		lc = (void *) lc + lc->cmdsize;
	}
	return (EXIT_SUCCESS);
}

static ssize_t
	nm_sect_64(void *eof, struct segment_command_64 *seg, ssize_t idx,
	int	*sectn)
{
	size_t			i;
	struct section_64	*sect;

	i = 0;
	sect = (void *) seg + sizeof(struct segment_command_64);
	while (i < seg->nsects)
	{
		if ((void *) sect + sect->size > eof)
			return (-1);
		// replace `strcmp' -> `ft_strcmp'
		if (strcmp(sect->sectname, "__text") == 0
			&& strcmp(sect->segname, "__TEXT") == 0)
			sectn[0] = idx;
		else if (strcmp(sect->sectname, "__data") == 0
			&& strcmp(sect->segname, "__DATA") == 0)
			sectn[1] = idx;
		else if (strcmp(sect->sectname, "__bss") == 0
			&& strcmp(sect->segname, "__DATA") == 0)
			sectn[2] = idx;
		sect++;
		idx++;
		i++;
	}
	return (idx);
}

static int
	nm_header_64(void *ptr, size_t size)
{
	struct mach_header_64	*header;
	struct load_command	*lc;
	size_t			ncmds;
	ssize_t			sectx;
	int			sectn[3];

	header = (struct mach_header_64 *) ptr;
	ncmds = header->ncmds;
	lc = (void *) ptr + sizeof(struct mach_header_64);
	sectx = 1;
	while (ncmds--)
	{
		if ((void *) lc + lc->cmdsize > ptr + size || sectx < 0)
			return (EXIT_FAILURE);
		if (lc->cmd == LC_SYMTAB)
			nm_sym_64(ptr, size, (void *) lc, sectn);
		else if (lc->cmd == LC_SEGMENT_64
			&& ((struct segment_command_64 *) lc)->nsects)
			sectx = nm_sect_64(ptr + size, (void *) lc, sectx, sectn);
		lc = (void *) lc + lc->cmdsize;
	}
	return (EXIT_SUCCESS);
}

int
	nm_header(void *ptr, size_t size)
{
	unsigned int	magic;
	int		ret;

	magic = *(unsigned int *) ptr;
	if (magic == MH_MAGIC)
		ret = nm_header_32(ptr, size);
	else if (magic == MH_MAGIC_64)
		ret = nm_header_64(ptr, size);
	// else if (magic == MH_CIGAM)
	// 	ret = nm_header_swap_32(ptr, size);
	// else if (magic == MH_CIGAM_64)
	// 	ret = nm_header_swap_64(ptr, size);
	else
		return (EXIT_FAILURE);
	return (ret);
}
