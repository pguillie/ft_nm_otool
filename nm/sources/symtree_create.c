/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symtree_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 15:50:34 by pguillie          #+#    #+#             */
/*   Updated: 2019/02/08 20:14:44 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

struct symtree *
symtree_create(const struct nlist *symtab, const char *strtab, uint32_t nsyms,
	struct macho_info *macho)
{
	struct symtree *root;
	int (*is_sorted)(const char *, const char *, uint64_t, uint64_t);

	is_sorted = get_sort_function(macho);
	root = NULL;
	while (nsyms--) {
		root = symtree_add(root, symtab++, strtab, is_sorted);
		if (root == NULL)
			break ;
	}
	return (root);
}
