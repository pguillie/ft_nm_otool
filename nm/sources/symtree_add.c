/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symtree_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 15:07:29 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/30 19:19:25 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

struct symtree *
symtree_add(
	struct symtree *node,
	const struct nlist *entry,
	const char *strtab,
	int (*is_sorted)(
		const struct nlist *a,
		const struct nlist *b,
		const char *strtab))
{
	struct symtree **side;

	if (node == NULL) {
		if ((node = malloc(sizeof(struct symtree))) == NULL)
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
	if ((*side = symtree_add(*side, entry, strtab, is_sorted)) == NULL) {
		symtree_delete(node);
		node = NULL;
	}
	return (node);
}
