/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_symtab_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 19:35:17 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/29 19:28:05 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

struct symtab_command *
get_symtab_command(void *ptr, const struct macho_info *macho)
{
	struct symtab_command *sym;

	if (ptr + sizeof(struct symtab_command) > macho->ptr + macho->size)
		return (NULL);
	sym = (struct symtab_command *)ptr;
	if (macho->is_rev) {
		sym->symoff = OSSwapConstInt32(sym->symoff);
		sym->nsyms = OSSwapConstInt32(sym->nsyms);
		sym->stroff = OSSwapConstInt32(sym->stroff);
		sym->strsize = OSSwapConstInt32(sym->strsize);
	}
	dprintf(2, "== SYMTAB_COMMAND ==\n");
	dprintf(2, "%.8x\n", sym->symoff);
	dprintf(2, "%.8x\n", sym->nsyms);
	dprintf(2, "%.8x\n", sym->stroff);
	dprintf(2, "%.8x\n", sym->strsize);
	return (sym);
}
