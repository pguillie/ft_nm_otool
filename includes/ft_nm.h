/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 18:33:07 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/19 20:18:55 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_H
# define FT_NM_H

# include <mach-o/loader.h>
#include <mach-o/nlist.h>
# include <stddef.h>
# include <stdint.h>
# include <unistd.h>

/////
#include<stdio.h>

struct macho_info {
	// char	*name;
	void		*ptr;
	uint64_t	size;
	uint8_t		is_rev;
	uint8_t		text_sect;
	uint8_t		data_sect;
	uint8_t		bss_sect;
};

////// libft
void	*ft_memset(void *s, int c, size_t n);
int	ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *str);
//////

int	nm_map_file(const char *file);
int	nm_check_header(struct macho_info macho);
int	nm_mach_header(struct macho_info macho);
int	nm_mach_header_64(struct macho_info macho);
int	nm_symtab(struct symtab_command *sym, const struct macho_info macho);
int	nm_symtab_64(struct symtab_command *sym, const struct macho_info macho);
void	write_symbols(struct nlist *symtab, size_t nsyms, char *strtab,
	const struct macho_info macho);
void	write_symbols_64(const struct nlist_64 * const symtab,
	const size_t nsyms, const char * strtab, const struct macho_info macho);

struct mach_header		*get_mach_header(const struct macho_info macho);
struct mach_header_64		*get_mach_header_64(const struct macho_info macho);

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

struct nlist			*get_nlist(void *ptr,
	const struct macho_info macho);
struct nlist_64			*get_nlist_64(void *ptr,
	const struct macho_info macho);

#endif /* FT_NM_H */
