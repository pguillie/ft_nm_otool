/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 20:02:50 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/30 20:24:35 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETTERS_H
# define GETTERS_H

# include "ft_nm.h"

struct mach_header
*get_mach_header(const struct macho_info *macho);

struct mach_header_64
*get_mach_header_64(const struct macho_info *macho);

struct fat_header
*get_fat_header(const struct macho_info *macho);

struct fat_arch
*get_fat_arch(void *ptr, const struct macho_info *macho);

struct ar_hdr
*get_arch_header(void *ptr, const struct macho_info *macho);

struct load_command
*get_load_command(void *ptr, const struct macho_info *macho);

struct segment_command
*get_segment_command(void *ptr, const struct macho_info *macho);

struct segment_command_64
*get_segment_command_64(void *ptr, const struct macho_info *macho);

struct section
*get_section(void *ptr, const struct macho_info *macho);

struct section_64
*get_section_64(void *ptr, const struct macho_info *macho);

struct symtab_command
*get_symtab_command(void *ptr, const struct macho_info *macho);

struct nlist
*get_nlist(void *ptr, const struct macho_info *macho);

struct nlist_64
*get_nlist_64(void *ptr, const struct macho_info *macho);

#endif /* GETTERS_H */
