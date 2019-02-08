/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_symbols.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 19:08:39 by pguillie          #+#    #+#             */
/*   Updated: 2019/02/08 22:40:48 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static void
nm_symbol_value(uint8_t type, uint32_t value, struct macho_info *macho)
{
	char tmp[8];
	size_t i;

	if ((type & N_TYPE) == N_UNDF && !((type & N_EXT) && value)) {
		ft_memset(tmp, ' ', 8);
	} else {
		i = 8;
		while (i--) {
			if (value % 16 > 9)
				tmp[i] = value % 16 - 10 + 'a';
			else
				tmp[i] = value % 16 + '0';
			value /= 16;
		}
	}
	buf_in(macho, tmp, 8);
}

static char
get_symbole_type(const struct nlist *entry, const struct macho_info *macho)
{
	if ((entry->n_type & N_TYPE) == N_UNDF) {
		if ((entry->n_type & N_EXT) && entry->n_value)
			return ('C');
		return ('U');
	}
	if ((entry->n_type & N_TYPE) == N_ABS) {
		return ('A');
	} else if ((entry->n_type & N_TYPE) == N_SECT) {
		if (entry->n_sect == macho->text_sect)
			return ('T');
		else if (entry->n_sect == macho->data_sect)
			return ('D');
		else if (entry->n_sect == macho->bss_sect)
			return ('B');
		return ('S');
	} else if ((entry->n_type & N_TYPE) == N_PBUD) {
		return ('P');
	} else if ((entry->n_type & N_TYPE) == N_INDR) {
		return ('I');
	} else {
		return ('X');
	}
}

static void
nm_symbol_type(const struct nlist *entry, struct macho_info *macho)
{
	char t[3];

	t[0] = ' ';
	t[1] = get_symbole_type(entry, macho);
	if (!(entry->n_type & N_EXT))
		t[1] |= (1 << 5);
	t[2] = ' ';
	buf_in(macho, t, 3);
}

static void
nm_symbol_name(const struct nlist *entry, const char *strtab,
	struct macho_info *macho)
{
	const char *name;

	name = strtab + entry->n_un.n_strx;
	buf_in(macho, name, ft_strlen(name));
	buf_in(macho, "\n", 1);
}

void
nm_symbols(struct symtree *node, const char *strtab, struct macho_info *macho)
{
	if (node == NULL)
		return ;
	nm_symbols(node->left, strtab, macho);
	if (!(node->entry->n_type & N_STAB)
		&& !((macho->opt & OPT_U)
			&& (node->entry->n_type & N_TYPE) != N_UNDF)
		&& !((macho->opt & OPT_NU)
			&& (node->entry->n_type & N_TYPE) == N_UNDF)
		&& !((macho->opt & OPT_G)
			&& !(node->entry->n_type & N_EXT))) {
		if (!(macho->opt & OPT_J) && !(macho->opt & OPT_U)) {
			nm_symbol_value(node->entry->n_type,
				node->entry->n_value, macho);
			nm_symbol_type(node->entry, macho);
		}
		nm_symbol_name(node->entry, strtab, macho);
	}
	nm_symbols(node->right, strtab, macho);
}
