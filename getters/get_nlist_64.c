/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nlist_64.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 23:13:21 by pguillie          #+#    #+#             */
/*   Updated: 2019/02/01 14:09:04 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

struct nlist_64 *
get_nlist_64(void *ptr, const struct macho_info *macho)
{
	struct nlist_64 *symtab_entry;

	if (ptr + sizeof(struct nlist_64) > macho->ptr + macho->size)
		return (NULL);
	symtab_entry = (struct nlist_64 *)ptr;
	if (macho->is_rev) {
		symtab_entry->n_un.n_strx =
			OSSwapConstInt32(symtab_entry->n_un.n_strx);
		symtab_entry->n_desc = OSSwapConstInt16(symtab_entry->n_desc);
		symtab_entry->n_value = OSSwapConstInt64(symtab_entry->n_value);
	}
	dprintf(3, "== NLIST_64 ==\n");
	dprintf(3, "%.8x\n", symtab_entry->n_un.n_strx);
	dprintf(3, "%.2x\n", symtab_entry->n_type);
	dprintf(3, "%.2x\n", symtab_entry->n_sect);
	dprintf(3, "%.4x\n", symtab_entry->n_desc);
	dprintf(3, "%.16llx\n", symtab_entry->n_value);
	return (symtab_entry);
}
