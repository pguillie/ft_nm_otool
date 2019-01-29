/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_symtab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 19:29:25 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/29 22:08:14 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

// static int
// valid_symbol_string(const struct symtab_command *sym,
// 	const struct nlist *symtab_entry, const struct macho_info *macho)
// {
// 	char *str;

// 	if (sym->stroff + symtab_entry->n_un.n_strx > sym->strsize)
// 		return (0);
// 	str = macho->ptr + sym->stroff + symtab_entry->n_un.n_strx;
// 	while (*str) {
// 		if ((void *)str++ > macho->ptr + macho->size)
// 			return (0);
// 	}
// 	return (1);
// }

static int
verify_symbol_string(const char *symstr, const char *strtab_end)
{
	while (symstr < strtab_end) {
		if (*symstr++ == '\0')
			return (1);
	}
	return (0);
}

static int
verify_string_table(const char *strtab, const struct symtab_command *sym,
	const struct nlist *symtab, const struct macho_info *macho)
{
	size_t i;
	const char *symstr;

	if ((void *)strtab + sym->strsize > macho->ptr + macho->size)
		return (0);
	i = 0;
	while (i < sym->nsyms) {
		symstr = strtab + symtab[i++].n_un.n_strx;
		if (verify_symbol_string(symstr, strtab + sym->strsize))
			continue ;
		return (0);
	}
	return (1);
}

int
nm_symtab(struct symtab_command *sym, struct macho_info *macho)
{
	struct nlist *symtab;
	char *strtab;
	size_t i;

	if (get_symtab_command(sym, macho) == NULL)
		return (-1);
	symtab = macho->ptr + sym->symoff;
	i = 0;
	while (i < sym->nsyms) {
		if (get_nlist(symtab + i, macho) == NULL)
			return (-1);
		i++;
	}
	// symtab = get_nlist(macho->ptr + sym->symoff, sym->nsyms, macho);
	// if (symtab == NULL)
	// 	return (-1);
	strtab = macho->ptr + sym->stroff;
	if (verify_string_table(strtab, sym, symtab, macho) == 0)
		return (-1);
	// strtab = get_string_table(sym, symtab, macho);
	// if (strtab == NULL)
	// 	return (-1);
	write_symbols(symtab, sym->nsyms, strtab, macho);
	return (0);
}
