/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arch_header.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:10:59 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/29 22:39:59 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

struct ar_hdr *
get_arch_header(void *ptr, const struct macho_info *macho)
{
	struct ar_hdr	*header;

	if (ptr + sizeof(struct ar_hdr) > macho->ptr + macho->size)
		return (NULL);
	header = (struct ar_hdr *)ptr;
	dprintf(2, "=== ARCH_HEADER ===\n");
	dprintf(2, "%.16s\n", header->ar_name);
	dprintf(2, "%.12s\n", header->ar_date);
	dprintf(2, "%.6s\n", header->ar_uid);
	dprintf(2, "%.6s\n", header->ar_gid);
	dprintf(2, "%.6s\n", header->ar_mode);
	dprintf(2, "%.10s\n", header->ar_size);
	dprintf(2, "%.2s\n", header->ar_fmag);
	if (ft_strncmp(header->ar_fmag, "`\n", 2))
		return (NULL);
	return (header);
}
