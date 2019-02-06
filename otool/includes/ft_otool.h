/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otool.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 18:33:07 by pguillie          #+#    #+#             */
/*   Updated: 2019/02/06 21:00:00 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OTOOL_H
# define FT_OTOOL_H

# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <mach-o/fat.h>
# include <ar.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>

# include "macho_info.h"
# include "cpu_type.h"
# include "getters.h"
# include "otool_error.h"
# include "../../libft/includes/libft.h"
/////
#include<stdio.h>
////

int
otool_map_file(const char *file);

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
otool_text(struct section *text, struct macho_info *macho);

int
otool_text_64(struct section_64 *text, struct macho_info *macho);

#endif /* FT_OTOOL_H */
