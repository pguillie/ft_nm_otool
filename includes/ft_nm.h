/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 18:33:07 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/30 20:11:51 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_H
# define FT_NM_H

# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <mach-o/fat.h>
# include <ar.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>

# include "macho_info.h"
# include "getters.h"
# include "symtree.h"
# include "nm_sort.h"
# include "libft.h"
/////
#include<stdio.h>
////

int
nm_map_file(const char *file, int store_name);

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
write_symbols(struct symtree *root, char *strtab,
	struct macho_info *macho);

void
write_symbols_64(struct symtree_64 *root, char * strtab,
	struct macho_info *macho);

#endif /* FT_NM_H */
