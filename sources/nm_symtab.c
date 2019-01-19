/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_symtab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 19:29:25 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/19 19:20:10 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static char *
get_string_table(struct symtab_command const *sym, struct nlist const *symtab,
	struct macho_info const macho)
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

int
nm_symtab(struct symtab_command *sym, struct macho_info const macho)
{
	struct nlist	*symtab;
	char		*strtab;

	if (get_symtab_command(sym, macho) == NULL)
		return (-1);
	if ((symtab = get_nlist(macho.ptr + sym->symoff, macho)) == NULL)
		return (-1);
	strtab = get_string_table(sym, symtab, macho);
	if (strtab == NULL)
		return (-1);
	write_symbols(symtab, sym->nsyms, strtab, macho);
	return (0);
}
