/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rev_ascii_sorted.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 16:38:22 by pguillie          #+#    #+#             */
/*   Updated: 2019/02/08 17:25:06 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int
// is_rev_ascii_sorted(const struct nlist *a, const struct nlist *b,
// 	const char *strtab)
is_rev_ascii_sorted(const char *s1, const char *s2, uint64_t n1, uint64_t n2)
{
	int dif;

	dif = ft_strcmp(s1, s2);
	if (dif == 0)
		return (n1 > n2);
	return (dif > 0);
}
