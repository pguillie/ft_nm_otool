/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_check_header.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:35:34 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/18 23:20:46 by pguillie         ###   ########.fr       */
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
		write(1, "magic\n", 6);
		macho.is_rev = 0;
		ret = nm_mach_header(macho);
	} else if (magic == MH_CIGAM) {
		write(1, "cigam\n", 6);
		macho.is_rev = 1;
		ret = nm_mach_header(macho);
	} else {
		write(1, "fuck\n", 5);
		return (-1);
	}
	return (ret);
}
