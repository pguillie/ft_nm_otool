/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:32:01 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/18 15:58:58 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int
main(int argc, char const *argv[])
{
	if (argc > 2)
		;//multiarg
	else if (argc == 2)
		nm_map_file(argv[1]);
	else
		nm_map_file("a.out");
	return 0;
}
