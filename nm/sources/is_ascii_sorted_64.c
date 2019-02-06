/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ascii_sorted_64.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 19:20:04 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/30 19:20:17 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int
is_ascii_sorted_64(const struct nlist_64 *a, const struct nlist_64 *b,
	const char *strtab)
{
	int dif;

	dif = ft_strcmp(strtab + a->n_un.n_strx, strtab + b->n_un.n_strx);
	if (dif < 0)
		return (1);
	if (dif > 0)
		return (0);
	return (a->n_value < b->n_value);
}
