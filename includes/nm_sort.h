/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_sort.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 19:59:34 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/30 20:01:52 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_SORT_H
# define NM_SORT_H

# include "ft_nm.h"

int
is_ascii_sorted(const struct nlist *a, const struct nlist *b,
	const char *strtab);

int
is_ascii_sorted_64(const struct nlist_64 *a, const struct nlist_64 *b,
	const char *strtab);

#endif /* NM_SORT_H */
