/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otool.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 18:33:07 by pguillie          #+#    #+#             */
/*   Updated: 2019/02/10 18:23:00 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OTOOL_H
# define FT_OTOOL_H

# include "libmacho.h"
# include "otool_option.h"
# include "otool_error.h"

void
otool_usage(void);

int
otool_map_file(const char *file, int opt);

int
otool_check_header(struct macho_info *macho);

int
otool_mach_header(struct macho_info *macho);

int
otool_mach_header_64(struct macho_info *macho);

int
otool_fat_header(struct macho_info *macho);

int
otool_arch_header(struct macho_info *macho);

int
otool_sect(struct section *text, struct macho_info *macho);

int
otool_sect_64(struct section_64 *sect, struct macho_info *macho);

#endif /* FT_OTOOL_H */
