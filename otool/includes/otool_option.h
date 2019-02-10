/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_option.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 16:34:31 by pguillie          #+#    #+#             */
/*   Updated: 2019/02/10 19:11:30 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTOOL_OPTION_H
# define OTOOL_OPTION_H

enum {
	OPT_D = (1 << 0),
	OPT_T = (1 << 1)
};

int
otool_options(int *ac, const char ***av);

#endif /* OTOOL_OPTION_H */
