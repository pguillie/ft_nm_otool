/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ascii_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 15:36:52 by pguillie          #+#    #+#             */
/*   Updated: 2019/02/08 17:53:23 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int
// is_ascii_sorted(const struct nlist *a, const struct nlist *b,
// 	const char *strtab)
is_ascii_sorted(const char *s1, const char *s2, uint64_t n1, uint64_t n2)
{
	int dif;

	dif = ft_strcmp(s1, s2);
	if (dif == 0)
		return (n1 < n2);
	return (dif < 0);
}
