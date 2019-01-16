/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_sym_64.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 19:38:01 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/16 22:49:08 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mach-o/loader.h>
#include <mach-o/nlist.h>
#include <stdlib.h>

#include <stdio.h>

int	nm_sym_64(void *ptr, size_t size, struct symtab_command *sym, int *sectn)
{
	struct nlist_64	*symtab;
	char		*strtab;
	unsigned int	i;

	symtab = ptr + sym->symoff;
	strtab = ptr + sym->stroff;
	if ((void *) symtab + sizeof(struct nlist_64) * sym->nsyms > ptr + size)
		return (EXIT_FAILURE);
	i = 0;
	while (i < sym->nsyms)
	{
		if ((symtab[i].n_type & N_STAB) && ++i)
			continue ;
		if ((symtab[i].n_type & N_TYPE) == N_UNDF)
		{
			if ((symtab[i].n_type & N_EXT) && symtab[i].n_value)
				printf("%.16llx %c ", symtab[i].n_value, 'C');
			else
				printf("%16c %c ", ' ', 'U' | (32 * !(symtab[i].n_type & N_EXT)));
		}
		else
		{
			printf("%.16llx ", symtab[i].n_value);
			if ((symtab[i].n_type & N_TYPE) == N_ABS)
				printf("%c ", 'A' | (32 * !(symtab[i].n_type & N_EXT)));
			else if ((symtab[i].n_type & N_TYPE) == N_SECT)
			{
				if (symtab[i].n_sect == sectn[0])
					printf("%c ", 'T' | (32 * !(symtab[i].n_type & N_EXT)));
				else if (symtab[i].n_sect == sectn[1])
					printf("%c ", 'D' | (32 * !(symtab[i].n_type & N_EXT)));
				else if (symtab[i].n_sect == sectn[2])
					printf("%c ", 'B' | (32 * !(symtab[i].n_type & N_EXT)));
				else
					printf("%c ", 'S' | (32 * !(symtab[i].n_type & N_EXT)));
			}
			else if ((symtab[i].n_type & N_TYPE) == N_PBUD)
				printf("%c ", 'P' | (32 * !(symtab[i].n_type & N_EXT)));
			else if ((symtab[i].n_type & N_TYPE) == N_INDR)
				printf("%c ", 'I' | (32 * !(symtab[i].n_type & N_EXT)));
			else
				printf("? ");
		}
		printf("%s\n", strtab + symtab[i].n_un.n_strx);
		i++;
	}
	return (EXIT_SUCCESS);
}
