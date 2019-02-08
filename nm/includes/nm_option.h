/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_option.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 19:23:45 by pguillie          #+#    #+#             */
/*   Updated: 2019/02/08 22:13:59 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_OPTION_H
# define NM_OPTION_H

enum {
	OPT_G = (1 << 0),
	OPT_N = (1 << 1),
	OPT_P = (1 << 2),
	OPT_R = (1 << 3),
	OPT_U = (1 << 4),
	OPT_NU = (1 << 5),
	OPT_J = (1 << 6)
};

int
nm_options(int *ac, const char ***av);

#endif /* NM_OPTION_H */
