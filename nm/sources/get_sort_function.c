/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sort_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 19:54:22 by pguillie          #+#    #+#             */
/*   Updated: 2019/02/08 20:20:06 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int (*get_sort_function(const struct macho_info *macho))
	(const char *, const char *, uint64_t, uint64_t)
{
	if (macho->opt & OPT_P) {
		return (&is_unsorted);
	} else if (macho->opt & OPT_N) {
		if (macho->opt & OPT_R)
			return (&is_rev_num_sorted);
		return (&is_num_sorted);
	} else if (macho->opt & OPT_R) {
		return (&is_rev_ascii_sorted);
	} else {
		return (&is_ascii_sorted);
	}
}
