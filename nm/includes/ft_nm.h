/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 18:33:07 by pguillie          #+#    #+#             */
/*   Updated: 2019/02/08 22:33:21 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_H
# define FT_NM_H

# include "libmacho.h"
# include "nm_option.h"
# include "nm_error.h"
# include "nm_sort.h"
# include "symtree.h"

void
nm_usage(void);

int
nm_map_file(const char *file, int opt, int multi_args);

int
nm_check_header(struct macho_info *macho);

int
nm_mach_header(struct macho_info *macho);

int
nm_mach_header_64(struct macho_info *macho);

int
nm_fat_header(struct macho_info *macho);

int
nm_arch_header(struct macho_info *macho);

int
nm_symtab(struct symtab_command *sym, struct macho_info *macho);

int
nm_symtab_64(struct symtab_command *sym, struct macho_info *macho);

void
nm_symbols(struct symtree *node, const char *strtab,
	struct macho_info *macho);

void
nm_symbols_64(struct symtree_64 *node, char *strtab,
	struct macho_info *macho);

#endif /* FT_NM_H */
