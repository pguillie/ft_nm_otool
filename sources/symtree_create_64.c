/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symtree_create_64.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 18:58:51 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/30 19:20:49 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

struct symtree_64 *
symtree_create_64(const struct nlist_64 *symtab, const char *strtab,
	uint32_t nsyms)
{
	struct symtree_64 *root;

	root = NULL;
	while (nsyms--) {
		root = symtree_add_64(root, symtab++, strtab,
			&is_ascii_sorted_64);
		if (root == NULL)
			break ;
	}
	return (root);
}
