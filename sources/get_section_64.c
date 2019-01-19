/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_section_64.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 17:04:13 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/19 19:48:37 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

struct section_64 *
get_section_64(void *ptr, struct macho_info macho)
{
	struct section_64 *sect;

	if (ptr + sizeof(struct section_64) > macho.ptr + macho.size)
		return (NULL);
	sect = (struct section_64 *)ptr;
	if (macho.is_rev) {
		sect->addr = OSSwapConstInt64(sect->addr);
		sect->size = OSSwapConstInt64(sect->size);
		sect->offset = OSSwapConstInt32(sect->offset);
		sect->align = OSSwapConstInt32(sect->align);
		sect->reloff = OSSwapConstInt32(sect->reloff);
		sect->nreloc = OSSwapConstInt32(sect->nreloc);
		sect->flags = OSSwapConstInt32(sect->flags);
		sect->reserved1 = OSSwapConstInt32(sect->reserved1);
		sect->reserved2 = OSSwapConstInt32(sect->reserved2);
		sect->reserved3 = OSSwapConstInt32(sect->reserved3);
	}
	if (ptr + sect->size > macho.ptr + macho.size)
		return (NULL);
	return (sect);
}
