/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symtree.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 19:49:40 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/30 20:01:16 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMTREE_H
# define SYMTREE_H

# include "ft_nm.h"

struct	symtree {
	const struct nlist	*entry;
	struct symtree		*left;
	struct symtree		*right;
};

struct	symtree_64 {
	const struct nlist_64	*entry;
	struct symtree_64	*left;
	struct symtree_64	*right;
};

struct symtree *
symtree_create(const struct nlist *symtab, const char *strtab, uint32_t nsyms);

struct symtree_64 *
symtree_create_64(const struct nlist_64 *symtab, const char *strtab,
	uint32_t nsyms);

void
symtree_delete(struct symtree *node);

void
symtree_delete_64(struct symtree_64 *node);

struct symtree *
symtree_add(struct symtree *node, const struct nlist *entry, const char *strtab,
	int (*is_sorted)(const struct nlist *a, const struct nlist *b,
		const char *strtab));

struct symtree_64 *
symtree_add_64(struct symtree_64 *node, const struct nlist_64 *entry,
	const char *strtab, int (*is_sorted)(const struct nlist_64 *a,
		const struct nlist_64 *b, const char *strtab));

#endif /* SYMTREE_H */
