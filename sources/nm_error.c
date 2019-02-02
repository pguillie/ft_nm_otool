/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 12:59:32 by pguillie          #+#    #+#             */
/*   Updated: 2019/02/01 19:17:04 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void
nm_error(const char *file, const char *msg)
{
	write(2, "ft_nm: ", 7);
	if (file)
		write(2, file, ft_strlen(file));
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
}
