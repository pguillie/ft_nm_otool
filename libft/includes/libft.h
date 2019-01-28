/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 11:26:57 by pguillie          #+#    #+#             */
/*   Updated: 2019/01/28 18:42:01 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdint.h>

void	*ft_memset(void *s, int c, size_t n);
char	*ft_strncpy(char *dest, const char *src, size_t n);

size_t	ft_strlen(const char *str);
int	ft_strcmp(const char *s1, const char *s2);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

// int	ft_atoi(const char *str);

// int	ft_isdigit(int c);
// int	ft_isspace(int c);

#endif
