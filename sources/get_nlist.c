/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nlist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 23:13:21 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/18 23:19:07 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

struct nlist *
get_nlist(void *ptr, struct macho_info macho)
{
	struct nlist	*entry;

	if (ptr + sizeof(struct nlist) > macho.ptr + macho.size)
		return (NULL);
	entry = (struct nlist *)ptr;
	if (macho.is_rev) {
		entry->n_un.n_strx = OSSwapConstInt32(entry->n_un.n_strx);
		entry->n_type = OSSwapConstInt32(entry->n_type);
		entry->n_sect = OSSwapConstInt32(entry->n_sect);
		entry->n_desc = OSSwapConstInt32(entry->n_desc);
		entry->n_value = OSSwapConstInt32(entry->n_value);
	}
	return (entry);
}
