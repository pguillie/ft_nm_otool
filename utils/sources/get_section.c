/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_section.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 17:04:13 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/17 18:14:27 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mach-o/loader.h>
#include <stddef.h>

# define REV_BYTE_ORDER 1

struct section *
get_section(void *ptr, void *boundary)
{
	struct section	*sect;
	int		rev;

	rev = (uint32_t)boundary & REV_BYTE_ORDER;
	boundary = (uint32_t)boundary & ~REV_BYTE_ORDER;
	if (ptr + sizeof(struct section) > boundary)
		return (NULL);
	sect = (struct section *)ptr;
	if (rev) {
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
	if (ptr + sect->size > boundary)
		return (NULL);
	return (sect);
}
