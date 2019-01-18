/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 18:33:07 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/18 23:13:06 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_H
# define FT_NM_H

# include <mach-o/loader.h>
#include <mach-o/nlist.h>
# include <stddef.h>
# include <stdint.h>
# include <unistd.h>

struct macho_info {
	// char	*name;
	void	*ptr;
	size_t	size;
	uint8_t	is_rev;
	uint8_t	text_sect;
	uint8_t	data_sect;
	uint8_t	bss_sect;
};

int	nm_map_file(char const *file);
int	nm_check_header(struct macho_info macho);
int	nm_mach_header(struct macho_info macho);
int	nm_symtab(struct symtab_command *sym, struct macho_info macho);

struct mach_header	*get_mach_header(struct macho_info macho);
struct load_command	*get_load_command(void *ptr, struct macho_info macho);
struct segment_command	*get_segment_command(void *ptr, struct macho_info macho);
struct section		*get_section(void *ptr, struct macho_info macho);
struct symtab_command	*get_symtab_command(void *ptr, struct macho_info macho);
struct nlist		*get_nlist(void *ptr, struct macho_info macho);

#endif /* FT_NM_H */
