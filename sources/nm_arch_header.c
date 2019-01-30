/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_arch_header.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 18:17:16 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/30 12:16:48 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static size_t
ar_hdr_size(const char *s, size_t len)
{
	size_t size;

	size = 0;
	while (len-- && *s != ' ')
		size = 10 * size + *s++ - '0';
	return (size);
}

static int
nm_arch_obj(struct ar_hdr *obj_hdr, const struct macho_info *macho, size_t size)
{
	struct macho_info obj;
	size_t ext;

	obj.ptr = (void *)obj_hdr + sizeof(struct ar_hdr);
	obj.size = size;
	if (ft_strncmp(obj_hdr->ar_name, AR_EFMT1, 3) == 0) {
		ext = ar_hdr_size(obj_hdr->ar_name + 3, 13);
		obj.ptr += ext;
		obj.size -= ext;
	}
	if (obj.ptr + obj.size > macho->ptr + macho->size)
		return (-1);
	return (nm_check_header(&obj));
}

int
nm_arch_header(struct macho_info *macho)
{
	struct ar_hdr *header;
	struct ar_hdr *obj_hdr;
	size_t obj_size;

	if ((header = get_arch_header(macho->ptr + SARMAG, macho)) == NULL)
		return (-1);
	obj_hdr = (void *)header + ar_hdr_size(header->ar_size, 10)
		+ sizeof(struct ar_hdr);
	while ((void *)obj_hdr < macho->ptr + macho->size) {
		if (get_arch_header(obj_hdr, macho) == NULL)
			return (-1);
		obj_size = ar_hdr_size(obj_hdr->ar_size, 10);
		nm_arch_obj(obj_hdr, macho, obj_size);
		obj_hdr = (void *)obj_hdr + obj_size + sizeof(struct ar_hdr);
	}
	return (0);//TODO return value
}
