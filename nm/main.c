/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 13:56:45 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/16 19:01:35 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		nm_file(const char *file);

int		main(int ac, char *av[])
{
	//TODO multiarg 
	if (ac > 1)
		return (nm_file(av[1]));
	else
		return (nm_file("a.out"));
}
