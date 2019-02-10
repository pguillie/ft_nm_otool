/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_usage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 22:23:37 by pguillie          #+#    #+#             */
/*   Updated: 2019/02/10 17:10:20 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void
nm_usage(void)
{
	ft_putstr("usage: ft_nm [options] file ...\n");
	ft_putstr("\t-g Display only global (external) symbols.\n");
	ft_putstr("\t-n Sort numerically rather than alphabetically.\n");
	ft_putstr("\t-p Don't sort; display in symbol-table order.\n");
	ft_putstr("\t-r Sort in reverse order.\n");
	ft_putstr("\t-u Display only undefined symbols.\n");
	ft_putstr("\t-U Don't display undefined symbols.\n");
	ft_putstr("\t-j Just display the symbol names (no value or type).\n");
}
