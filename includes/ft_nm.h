/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 18:33:07 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/28 19:14:51 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_H
# define FT_NM_H

# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <mach-o/fat.h>
# include <ar.h>
# include <stddef.h>
# include <stdint.h>
# include <unistd.h>

# include "libft.h"

/////
#include<stdio.h>

struct macho_info {
	const char	*name;
	void		*ptr;
	uint64_t	size;
	uint8_t		is_rev;
	uint8_t		text_sect;
	uint8_t		data_sect;
	uint8_t		bss_sect;
};

int	nm_map_file(char const *file, int store_name);
int	nm_check_header(struct macho_info macho);
int	nm_mach_header(struct macho_info macho);
int	nm_mach_header_64(struct macho_info macho);
int	nm_fat_header(struct macho_info macho);
int	nm_arch_header(struct macho_info macho);
int	nm_symtab(struct symtab_command *sym, const struct macho_info macho);
int	nm_symtab_64(struct symtab_command *sym, const struct macho_info macho);
void	write_symbols(struct nlist *symtab, size_t nsyms, char *strtab,
	const struct macho_info macho);
void	write_symbols_64(const struct nlist_64 * const symtab,
	const size_t nsyms, const char * strtab, const struct macho_info macho);

struct mach_header		*get_mach_header(const struct macho_info macho);
struct mach_header_64		*get_mach_header_64(const struct macho_info macho);
struct fat_header		*get_fat_header(const struct macho_info macho);
struct fat_arch			*get_fat_arch(void *ptr, const struct macho_info macho);
struct ar_hdr			*get_arch_header(void *ptr, struct macho_info macho);
struct load_command		*get_load_command(void *ptr,
	const struct macho_info macho);

struct segment_command		*get_segment_command(void *ptr,
	const struct macho_info macho);
struct segment_command_64	*get_segment_command_64(const void *ptr,
	const struct macho_info macho);

struct section			*get_section(void *ptr,
	const struct macho_info macho);
struct section_64		*get_section_64(void *ptr,
	const struct macho_info macho);

struct symtab_command		*get_symtab_command(void *ptr,
	const struct macho_info macho);

struct nlist			*get_nlist(void *ptr, uint32_t nsyms,
	const struct macho_info macho);
struct nlist_64			*get_nlist_64(void *ptr, uint32_t nsyms,
	const struct macho_info macho);

#endif /* FT_NM_H */
