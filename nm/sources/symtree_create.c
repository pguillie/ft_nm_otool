/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symtree_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 15:50:34 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/30 18:50:58 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

struct symtree *
symtree_create(const struct nlist *symtab, const char *strtab, uint32_t nsyms)
{
	struct symtree *root;

	root = NULL;
	while (nsyms--) {
		root = symtree_add(root, symtab++, strtab, &is_ascii_sorted);
		if (root == NULL)
			break ;
	}
	return (root);
}
