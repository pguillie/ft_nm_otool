/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_arch_header.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 18:17:16 by pguillie          #+#    #+#             */
/*   Updated: 2019/02/02 15:24:38 by pguillie         ###   ########.fr       */
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

static size_t
nm_arch_obj_name(struct ar_hdr *obj_hdr, char **name, size_t *len)
{
	size_t ext;

	*len = 0;
	if (ft_strncmp(obj_hdr->ar_name, AR_EFMT1, 3) == 0) {
		ext = ar_hdr_size(obj_hdr->ar_name + 3, 13);
		*name = (void *)obj_hdr + sizeof(struct ar_hdr);
		while (*len < ext && (*name)[*len])
			(*len)++;
	} else {
		ext = 0;
		*name = (void *)obj_hdr;
		while (*len < 16 && (*name)[*len] != ' ')
			(*len)++;
	}
	return (ext);
}

static int
nm_arch_obj(struct ar_hdr *obj_hdr, const struct macho_info *macho, size_t size)
{
	struct macho_info obj;
	char *name;
	size_t len;
	size_t ext;

	ext = nm_arch_obj_name(obj_hdr, &name, &len);
	obj.ptr = (void *)obj_hdr + sizeof(struct ar_hdr) + ext;
	obj.size = size - ext;
	if (obj.ptr + obj.size > macho->ptr + macho->size)
		return (1);
	obj.buf_index = 0;
	obj.file = macho->file;
	buf_in(&obj, "\n", 1);
	buf_in(&obj, macho->file, ft_strlen(macho->file));
	buf_in(&obj, "(", 1);
	buf_in(&obj, name, len);
	buf_in(&obj, "):\n", 3);
	return (nm_check_header(&obj));
}

int
nm_arch_header(struct macho_info *macho)
{
	struct ar_hdr *header;
	struct ar_hdr *obj_hdr;
	size_t obj_size;
	int ret;
	int err;

	if ((header = get_arch_header(macho->ptr + SARMAG, macho)) == NULL)
		return (1);
	obj_hdr = (void *)header + ar_hdr_size(header->ar_size, 10)
		+ sizeof(struct ar_hdr);
	ret = 0;
	while ((void *)obj_hdr < macho->ptr + macho->size) {
		if (get_arch_header(obj_hdr, macho) == NULL)
			return (1);
		obj_size = ar_hdr_size(obj_hdr->ar_size, 10);
		err = nm_arch_obj(obj_hdr, macho, obj_size);
		if (err < 0)
			return (-1);
		if (err)
			ret = 1;
		obj_hdr = (void *)obj_hdr + obj_size + sizeof(struct ar_hdr);
	}
	return (ret);
}
