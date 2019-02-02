/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_symtab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 19:29:25 by pguillie          #+#    #+#             */
/*   Updated: 2019/02/01 15:51:14 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

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
	struct symtree *root;
	char *strtab;
	size_t i;

	if (sym) {
		if (get_symtab_command(sym, macho) == NULL)
			return (1);
		symtab = macho->ptr + sym->symoff;
		i = 0;
		while (i < sym->nsyms)
			if (get_nlist(symtab + i++, macho) == NULL)
				return (1);
		strtab = macho->ptr + sym->stroff;
		if (verify_string_table(strtab, sym, symtab, macho) == 0)
			return (1);
		if ((root = symtree_create(symtab, strtab, sym->nsyms)) == NULL)
			return (-1);
		nm_symbols(root, strtab, macho);
		symtree_delete(root);
	}
	buf_out(macho);
	return (0);
}
