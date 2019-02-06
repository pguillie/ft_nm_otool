/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symtree_add_64.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 19:07:50 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/30 19:19:41 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

struct symtree_64 *
symtree_add_64(
	struct symtree_64 *node,
	const struct nlist_64 *entry,
	const char *strtab,
	int (*is_sorted)(
		const struct nlist_64 *a,
		const struct nlist_64 *b,
		const char *strtab))
{
	struct symtree_64 **side;

	if (node == NULL) {
		if ((node = malloc(sizeof(struct symtree_64))) == NULL)
			return (NULL);
		node->entry = entry;
		node->left = NULL;
		node->right = NULL;
		return (node);
	}
	if (is_sorted(entry, node->entry, strtab))
		side = &node->left;
	else
		side = &node->right;
	if ((*side = symtree_add_64(*side, entry, strtab, is_sorted)) == NULL) {
		symtree_delete_64(node);
		node = NULL;
	}
	return (node);
}
