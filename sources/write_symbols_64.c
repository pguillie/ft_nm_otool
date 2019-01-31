/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_symbols_64.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 19:08:39 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/31 17:39:51 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static void
write_symbol_value(uint8_t type, uint64_t value, struct macho_info *macho)
{
	char tmp[16];
	size_t i;

	if ((type & N_TYPE) == N_UNDF && !((type & N_EXT) && value)) {
		ft_memset(tmp, ' ', 16);
	} else {
		i = 16;
		while (i--) {
			if (value % 16 > 9)
				tmp[i] = value % 16 - 10 + 'a';
			else
				tmp[i] = value % 16 + '0';
			value /= 16;
		}
	}
	buf_in(macho, tmp, 16);
}

static char
get_symbole_type(const struct nlist_64 *entry, const struct macho_info *macho)
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
write_symbol_type(const struct nlist_64 *entry, struct macho_info *macho)
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
write_symbol_name(const struct nlist_64 *entry, const char *strtab,
	struct macho_info *macho)
{
	const char *name;

	name = strtab + entry->n_un.n_strx;
	buf_in(macho, name, ft_strlen(name));
	buf_in(macho, "\n", 1);
}

void
write_symbols_64(struct symtree_64 *node, char *strtab,
	struct macho_info *macho)
{
	if (node == NULL)
		return ;
	write_symbols_64(node->left, strtab, macho);
	if (!(node->entry->n_type & N_STAB)) {
		write_symbol_value(node->entry->n_type, node->entry->n_value,
			macho);
		write_symbol_type(node->entry, macho);
		write_symbol_name(node->entry, strtab, macho);
	}
	write_symbols_64(node->right, strtab, macho);
}
