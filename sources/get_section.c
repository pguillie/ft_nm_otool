/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_section.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 17:04:13 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/18 19:14:01 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

struct section *
get_section(void *ptr, struct macho_info macho)
{
	struct section	*sect;

	if (ptr + sizeof(struct section) > macho.ptr + macho.size)
		return (NULL);
	sect = (struct section *)ptr;
	if (macho.is_rev) {
		sect->addr = OSSwapConstInt32(sect->addr);
		sect->size = OSSwapConstInt32(sect->size);
		sect->offset = OSSwapConstInt32(sect->offset);
		sect->align = OSSwapConstInt32(sect->align);
		sect->reloff = OSSwapConstInt32(sect->reloff);
		sect->nreloc = OSSwapConstInt32(sect->nreloc);
		sect->flags = OSSwapConstInt32(sect->flags);
		sect->reserved1 = OSSwapConstInt32(sect->reserved1);
		sect->reserved2 = OSSwapConstInt32(sect->reserved2);
	}
	if (ptr + sect->size > macho.ptr + macho.size)
		return (NULL);
	return (sect);
}
