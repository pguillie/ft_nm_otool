/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symtree_create_64.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 18:58:51 by pguillie          #+#    #+#             */
/*   Updated: 2019/02/08 20:14:41 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

struct symtree_64 *
symtree_create_64(const struct nlist_64 *symtab, const char *strtab,
	uint32_t nsyms, struct macho_info *macho)
{
	struct symtree_64 *root;
	int (*is_sorted)(const char *, const char *, uint64_t, uint64_t);

	is_sorted = get_sort_function(macho);
	root = NULL;
	while (nsyms--) {
		root = symtree_add_64(root, symtab++, strtab, is_sorted);
		if (root == NULL)
			break ;
	}
	return (root);
}
