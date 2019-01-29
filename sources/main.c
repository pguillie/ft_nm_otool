/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:32:01 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/29 21:29:19 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int
main(int argc, char const *argv[])
{
	int i;

	if (argc > 2) {
		i = 1;
		while (i < argc)
			nm_map_file(argv[i++], 1);
	} else if (argc == 2) {
		nm_map_file(argv[1], 0);
	} else {
		nm_map_file("a.out", 0);
	}
	return 0; //
}
