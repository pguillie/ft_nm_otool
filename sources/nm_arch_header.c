/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_arch_header.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 18:17:16 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/29 23:02:39 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

// static size_t
// obj_size(const struct ar_hdr *header)
// {
// 	size_t len;
// 	int i;

// 	len = 0;
// 	i = 0;
// 	while (header->ar_size[i] != ' ' && i < 10)
// 		len = 10 * len + header->ar_size[i++] - '0';
// 	return (len);
// }

// static size_t
// name_size(const char *ar_name)
// {
// 	size_t len;
// 	int i;

// 	len = 0;
// 	i = 3;
// 	while (ar_name[i] != ' ' && i < 16)
// 		len = 10 * len + ar_name[i++] - '0';
// 	return (len);
// }

// static int
// nm_arch_obj_header(struct ar_hdr *obj_hdr, struct macho_info *macho)
// {
// 	struct macho_info obj;

// 	if (get_arch_header(obj_hdr, macho) == NULL) {
// 		if (obj_hdr == macho->ptr + macho->size)
// 			return (0);
// 		return (-1);
// 	}
// 	obj.ptr = (void *)obj_hdr + sizeof(struct ar_hdr);
// 	if (ft_strncmp(obj_hdr->ar_name, AR_EFMT1, 3) == 0)
// 		obj.ptr += name_size(obj_hdr->ar_name);
// 	obj.size = obj_size(obj_hdr);
// 	if (obj.ptr > macho->ptr + macho->size)
// 		return (-1);
// 	write(1, "\n:\n", 3); //TODO buffer
// 	nm_check_header(obj);
// 	return (nm_arch_obj_header((void *)obj_hdr + obj.size
// 		+ sizeof(struct ar_hdr), macho));
// }

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
	// while ((void *)obj_hdr < macho->ptr + macho->size) {
	while (1) {
		if (get_arch_header(obj_hdr, macho) == NULL)
			return (-1);
		obj_size = ar_hdr_size(obj_hdr->ar_size, 10);
		nm_arch_obj(obj_hdr, macho, obj_size);
		obj_hdr = (void *)obj_hdr + obj_size + sizeof(struct ar_hdr);
	}
	return (0);//TODO return value
}
