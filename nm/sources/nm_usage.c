/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_usage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 22:23:37 by pguillie          #+#    #+#             */
/*   Updated: 2019/02/08 22:33:03 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void
nm_usage(void)
{
	ft_putstr("usage: ft_nm [options] file ...\n");
	ft_putstr("\t-g\tDisplay only global (external) symbols.\n");
	ft_putstr("\t-n\tSort numerically rather than alphabetically.\n");
	ft_putstr("\t-p\tDon't sort; display in symbol-table order.\n");
	ft_putstr("\t-r\tSort in reverse order.\n");
	ft_putstr("\t-u\tDisplay only undefined symbols.\n");
	ft_putstr("\t-U\tDon't display undefined symbols.\n");
	ft_putstr("\t-j\tJust display the symbol names (no value or type).\n");
}
