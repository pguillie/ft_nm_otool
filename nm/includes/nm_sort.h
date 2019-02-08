/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_sort.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 19:59:34 by pguillie          #+#    #+#             */
/*   Updated: 2019/02/08 20:08:23 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_SORT_H
# define NM_SORT_H

# include "ft_nm.h"

int (*get_sort_function(const struct macho_info *macho))
	(const char *, const char *, uint64_t, uint64_t);

int
is_ascii_sorted(const char *s1, const char *s2, uint64_t n1, uint64_t n2);

int
is_rev_ascii_sorted(const char *s1, const char *s2, uint64_t n1, uint64_t n2);

int
is_num_sorted(const char *s1, const char *s2, uint64_t n1, uint64_t n2);

int
is_rev_num_sorted(const char *s1, const char *s2, uint64_t n1, uint64_t n2);

int
is_unsorted(const char *s1, const char *s2, uint64_t n1, uint64_t n2);

#endif /* NM_SORT_H */
