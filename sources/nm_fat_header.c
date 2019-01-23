/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_fat_header.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 18:37:56 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/23 18:43:38 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static ssize_t
get_default_arch(struct fat_arch **arch, uint32_t n, struct macho_info macho)
{
	uint32_t	i;

	i = 0;
	while (i++ < n) {
		if (get_fat_arch(*arch, macho) == NULL)
			return (0);
		if ((*arch)->cputype == CPU_TYPE_X86_64)
			return (1);
		(*arch)++;
	}
	*arch = NULL;
	return (1);
}

int
nm_fat_header(struct macho_info macho)
{
	struct fat_header	*header;
	struct fat_arch		*arch;
	struct macho_info	sub;
	size_t			i;
	int			ret;

	if ((header = get_fat_header(macho)) == NULL)
		return (-1);
	arch = (void *)macho.ptr + sizeof(struct fat_header);
	if (get_default_arch(&arch, header->nfat_arch, macho) == 0)
		return (-1);
	if (arch) {
		macho.ptr += arch->offset;
		macho.size = arch->size;
		return (nm_check_header(macho));
	}
	ret = 0;
	arch = (void *)macho.ptr + sizeof(struct fat_header);
	i = 0;
	while (i++ < header->nfat_arch) {
		//name
		sub.ptr = macho.ptr + arch->offset;
		sub.size = arch->size;
		//ret
		nm_check_header(sub);
		arch++;
	}
	return (ret);
}
