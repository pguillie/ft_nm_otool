/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symtree_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 15:07:29 by pguillie          #+#    #+#             */
/*   Updated: 2019/02/08 18:00:16 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

struct symtree *
symtree_add(
	struct symtree *node,
	const struct nlist *entry,
	const char *strtab,
	int (*is_sorted)(
		const char *str_a,
		const char *str_b,
		uint64_t val_a,
		uint64_t val_b))
{
	struct symtree **side;
	int sorted;

	if (node == NULL) {
		if ((node = malloc(sizeof(struct symtree))) == NULL)
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
	if ((*side = symtree_add(*side, entry, strtab, is_sorted)) == NULL) {
		symtree_delete(node);
		node = NULL;
	}
	return (node);
}
