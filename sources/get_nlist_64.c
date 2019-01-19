/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nlist_64.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 23:13:21 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/19 19:53:46 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

struct nlist_64 *
get_nlist_64(void *ptr, struct macho_info macho)
{
	struct nlist_64	*entry;

	if (ptr + sizeof(struct nlist_64) > macho.ptr + macho.size)
		return (NULL);
	entry = (struct nlist_64 *)ptr;
	if (macho.is_rev) {
		entry->n_un.n_strx = OSSwapConstInt32(entry->n_un.n_strx);
		entry->n_desc = OSSwapConstInt16(entry->n_desc);
		entry->n_value = OSSwapConstInt64(entry->n_value);
	}
	return (entry);
}
