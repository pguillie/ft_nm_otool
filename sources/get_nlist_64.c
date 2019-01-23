/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nlist_64.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 23:13:21 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/22 16:51:25 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

struct nlist_64 *
get_nlist_64(void *ptr, uint32_t nsyms, struct macho_info macho)
{
	struct nlist_64	*symtab;
	uint32_t	i;

	if (ptr + sizeof(struct nlist_64) > macho.ptr + macho.size)
		return (NULL);
	symtab = (struct nlist_64 *)ptr;
	i = 0;
	while (i < nsyms) {
		if (macho.is_rev) {
			symtab[i].n_un.n_strx = OSSwapConstInt32(symtab[i].n_un.n_strx);
			symtab[i].n_desc = OSSwapConstInt16(symtab[i].n_desc);
			symtab[i].n_value = OSSwapConstInt64(symtab[i].n_value);
		}
		dprintf(2, "=== NLIST_64 ===\n");
		dprintf(2, "%.8x\n", symtab[i].n_un.n_strx);
		dprintf(2, "%.2x\n", symtab[i].n_type);
		dprintf(2, "%.2x\n", symtab[i].n_sect);
		dprintf(2, "%.4x\n", symtab[i].n_desc);
		dprintf(2, "%.16llx\n", symtab[i].n_value);
		i++;
	}
	return (symtab);
}
