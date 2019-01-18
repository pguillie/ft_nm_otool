/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_symtab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 19:29:25 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/18 23:19:42 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

#include<stdio.h>
#include<string.h>

static char *
get_string_table(struct symtab_command *sym, struct nlist *symtab,
	struct macho_info macho)
{
	char		*str;
	size_t		i;

	if (sym->stroff + sym->strsize > macho.size)
		return (NULL);
	i = 0;
	while (i < sym->nsyms) {
		str = macho.ptr + sym->stroff + symtab[i++].n_un.n_strx;
		while (*str)
			if ((void *)str++
				> macho.ptr + sym->stroff + sym->strsize)
				return (NULL);
	}
	return (macho.ptr + sym->stroff);
}

static void
write_symbol_value(uint8_t type, uint32_t value)
{
	if ((type & N_TYPE) == N_UNDF && !((type & N_EXT) && value))
		write(1, "        ", 8);
	else
		printf("%.8x", value);
		// ft_putptr_32(value);
}

static char
get_symbole_section(struct nlist entry, struct macho_info macho)
{
	if (entry.n_sect == macho.text_sect)
		return ('T');
	else if (entry.n_sect == macho.data_sect)
		return ('D');
	else if (entry.n_sect == macho.bss_sect)
		return ('B');
	return ('S');
}

static void
write_symbol_type(struct nlist entry, struct macho_info macho)
{
	char	s[3];

	s[0] = ' ';
	s[2] = ' ';
	if ((entry.n_type & N_TYPE) == N_UNDF) {
		if ((entry.n_type & N_EXT) && entry.n_value)
			s[1] = 'C';
		else
			s[1] = 'U';
	} else {
		if ((entry.n_type & N_TYPE) == N_ABS)
			s[1] = 'A';
		else if ((entry.n_type & N_TYPE) == N_SECT)
			s[1] = get_symbole_section(entry, macho);
		else if ((entry.n_type & N_TYPE) == N_PBUD)
			s[1] = 'P';
		else if ((entry.n_type & N_TYPE) == N_INDR)
			s[1] = 'I';
		else
			s[1] = 'X';		
	}
	if (!(entry.n_type & N_EXT))
		s[1] |= (1 << 5);
	write(1, s, 3);
}

static void
write_symbols(struct nlist *symtab, size_t nsyms, char *strtab,
	struct macho_info macho)
{
	size_t	i;
	char	*name;

	i = 0;
	while (i < nsyms) {
		if (symtab[i].n_type & N_STAB) {
			i++;
			continue ;
		}
		write_symbol_value(symtab[i].n_type, symtab[i].n_value);
		write_symbol_type(symtab[i], macho);
		name = strtab + symtab[i].n_un.n_strx;
		write(1, name, strlen(name));
	}
}

int
nm_symtab(struct symtab_command *sym, struct macho_info macho)
{
	struct nlist	*symtab;
	char		*strtab;

	if (get_symtab_command(sym, macho) == NULL)
		return (-1);
	if ((symtab = get_nlist(macho.ptr + sym->symoff, macho)) == NULL)
		return (-1);
	strtab = get_string_table(macho.ptr + sym->stroff, symtab, macho);
	if (strtab == NULL)
		return (-1);
	write_symbols(symtab, sym->nsyms, strtab, macho);
	return (0);
}
