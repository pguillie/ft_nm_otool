/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_check_header.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:35:34 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/19 21:01:01 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int
nm_check_header(struct macho_info macho)
{
	unsigned int	magic;
	int		ret;

	magic = *(unsigned int *)macho.ptr;
	if (magic == MH_MAGIC) {
		dprintf(2, "magic\n");
		macho.is_rev = 0;
		ret = nm_mach_header(macho);
	} else if (magic == MH_CIGAM) {
		dprintf(2, "cigam\n");
		macho.is_rev = 1;
		ret = nm_mach_header(macho);
	} else if (magic == MH_MAGIC_64) {
		dprintf(2, "magic64\n");
		macho.is_rev = 0;
		ret = nm_mach_header_64(macho);
	} else if (magic == MH_CIGAM_64) {
		dprintf(2, "cigam64\n");
		macho.is_rev = 1;
		ret = nm_mach_header_64(macho);
	} else {
		return (-1);
	}
	return (ret);
}
