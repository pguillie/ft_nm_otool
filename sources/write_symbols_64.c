/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_symbols_64.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 19:08:39 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/30 19:18:00 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void
ft_putptr_64(char *buf, uint64_t ptr)
{
	size_t i;

	i = 16;
	while (i--) {
		buf[i] = ptr % 16 > 9 ? ptr % 16 - 10 + 'a' : ptr % 16 + '0';
		ptr /= 16;
	}
}

static void
write_symbol_value(uint8_t type, uint64_t value)
{
	char addr[16];

	if ((type & N_TYPE) == N_UNDF && !((type & N_EXT) && value))
		ft_memset(addr, ' ', 16);
	else
		ft_putptr_64(addr, value);
	write(1, addr, 16);
}

static char
get_symbole_section(struct nlist_64 entry, struct macho_info macho)
{
	if (entry.n_sect == macho.text_sect)
		return ('T');
	else if (entry.n_sect == macho.data_sect)
		return ('D');
	else if (entry.n_sect == macho.bss_sect)
		return ('B');
	return ('S');
}

static void
write_symbol_type(struct nlist_64 entry, struct macho_info macho)
{
	char s[3];

	s[0] = ' ';
	s[2] = ' ';
	if ((entry.n_type & N_TYPE) == N_UNDF) {
		if ((entry.n_type & N_EXT) && entry.n_value)
			s[1] = 'C';
		else
			s[1] = 'U';
	} else {
		if ((entry.n_type & N_TYPE) == N_ABS)
			s[1] = 'A';
		else if ((entry.n_type & N_TYPE) == N_SECT)
			s[1] = get_symbole_section(entry, macho);
		else if ((entry.n_type & N_TYPE) == N_PBUD)
			s[1] = 'P';
		else if ((entry.n_type & N_TYPE) == N_INDR)
			s[1] = 'I';
		else
			s[1] = 'X';		
	}
	if (!(entry.n_type & N_EXT))
		s[1] |= (1 << 5);
	write(1, s, 3);
}

//bufferize
void
write_symbols_64(struct symtree_64 *node, char *strtab,
	struct macho_info *macho)
{
	char *name;

	if (node == NULL)
		return ;
	write_symbols_64(node->left, strtab, macho);
	if (!(node->entry->n_type & N_STAB)) {
		write_symbol_value(node->entry->n_type, node->entry->n_value);
		write_symbol_type(*node->entry, *macho);
		name = strtab + node->entry->n_un.n_strx;
		write(1, name, ft_strlen(name));
		write(1, "\n", 1);
	}
	write_symbols_64(node->right, strtab, macho);
}
