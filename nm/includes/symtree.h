/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symtree.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 19:49:40 by pguillie          #+#    #+#             */
/*   Updated: 2019/02/08 19:53:07 by pguillie         ###   ########.fr       */
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
symtree_create(const struct nlist *symtab, const char *strtab, uint32_t nsyms,
	struct macho_info *macho);

struct symtree_64 *
symtree_create_64(const struct nlist_64 *symtab, const char *strtab,
	uint32_t nsyms, struct macho_info *macho);

void
symtree_delete(struct symtree *node);

void
symtree_delete_64(struct symtree_64 *node);

struct symtree *
symtree_add(struct symtree *node, const struct nlist *entry, const char *strtab,
	int (*is_sorted)(const char *s1, const char *s2, uint64_t n1,
		uint64_t n2));

struct symtree_64 *
symtree_add_64(struct symtree_64 *node, const struct nlist_64 *entry,
	const char *strtab, int (*is_sorted)(const char *s1, const char *s2,
		uint64_t n1, uint64_t n2));

#endif /* SYMTREE_H */
