/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rev_num_sorted.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 17:27:15 by pguillie          #+#    #+#             */
/*   Updated: 2019/02/08 17:53:48 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int
is_rev_num_sorted(const char *s1, const char *s2, uint64_t n1, uint64_t n2)
{
	if (n1 != n2)
		return (n1 > n2);
	return (ft_strcmp(s1, s2) > 0);
}
