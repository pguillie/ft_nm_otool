/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symtree_add_64.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 19:07:50 by pguillie          #+#    #+#             */
/*   Updated: 2019/02/08 18:00:22 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

struct symtree_64 *
symtree_add_64(
	struct symtree_64 *node,
	const struct nlist_64 *entry,
	const char *strtab,
	int (*is_sorted)(
		const char *str_a,
		const char *str_b,
		uint64_t val_a,
		uint64_t val_b))
{
	struct symtree_64 **side;
	int sorted;

	if (node == NULL) {
		if ((node = malloc(sizeof(struct symtree_64))) == NULL)
			return (NULL);
		node->entry = entry;
		node->left = NULL;
		node->right = NULL;
		return (node);
	}
	sorted = is_sorted(strtab + entry->n_un.n_strx,
		strtab + node->entry->n_un.n_strx,
		entry->n_value, node->entry->n_value);
	if (sorted)
		side = &node->left;
	else
		side = &node->right;
	if ((*side = symtree_add_64(*side, entry, strtab, is_sorted)) == NULL) {
		symtree_delete_64(node);
		node = NULL;
	}
	return (node);
}
