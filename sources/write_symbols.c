/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_symbols.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 19:08:39 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/22 18:10:58 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void
ft_putptr_32(char *buf, uint32_t ptr)
{
	size_t	i;

	i = 8;
	while (i--) {
		buf[i] = ptr % 16 > 9 ? ptr % 16 - 10 + 'a' : ptr % 16 + '0';
		ptr /= 16;
	}
}

static void
write_symbol_value(uint8_t type, uint32_t value)
{
	char	addr[8];

	if ((type & N_TYPE) == N_UNDF && !((type & N_EXT) && value))
		ft_memset(addr, ' ', 8);
	else
		ft_putptr_32(addr, value);
	write(1, addr, 8);
}

static char
get_symbole_section(struct nlist entry, struct macho_info macho)
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
write_symbol_type(struct nlist entry, struct macho_info macho)
{
	char	s[3];

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

void
write_symbols(struct nlist *symtab, size_t nsyms, char *strtab,
	struct macho_info macho)
{
	size_t	i;
	char	*name;

	if (macho.name) {
		write(1, "\n", 1);
		write(1, macho.name, ft_strlen(macho.name));
		write(1, ":\n", 2);
	}
	i = 0;
	while (i < nsyms) {
		if (symtab[i].n_type & N_STAB) {
			i++;
			continue ;
		}
		write_symbol_value(symtab[i].n_type, symtab[i].n_value);
		write_symbol_type(symtab[i], macho);
		name = strtab + symtab[i].n_un.n_strx;
		write(1, name, ft_strlen(name));
		write(1, "\n", 1);
		i++;
	}
}
