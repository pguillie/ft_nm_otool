/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmacho.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 20:11:04 by pguillie          #+#    #+#             */
/*   Updated: 2019/02/08 15:51:47 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMACHO_H
# define LIBMACHO_H

# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <mach-o/fat.h>
# include <ar.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>

# include "../../libft/includes/libft.h"
# include "macho_info.h"
# include "cpu_type.h"
# include "getters.h"
/////
#include<stdio.h>
////

void
buf_out(struct macho_info *macho);

void
buf_in(struct macho_info *macho, const char *str, size_t n);

#endif /* LIBMACHO_H */
