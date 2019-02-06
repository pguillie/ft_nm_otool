/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symtree_delete_64.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 19:11:27 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/30 20:29:57 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void
symtree_delete_64(struct symtree_64 *node)
{
	if (node) {
		symtree_delete_64(node->left);
		symtree_delete_64(node->right);
		free(node);
	}
}
