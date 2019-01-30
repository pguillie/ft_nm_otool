# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/08 15:27:58 by pguillie          #+#    #+#              #
#    Updated: 2019/01/30 20:14:28 by pguillie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_nm

CC	= gcc
CFLAGS	= -Wall -Werror -Wextra

LFT	= libft/libft.a

INCDIR := includes/
SRCDIR := sources/
GETDIR := getters/

INCLUDES = \
$(addprefix $(INCDIR), \
	ft_nm.h \
	getters.h \
	libft.h \
	macho_info.h \
	nm_sort.h \
	symtree.h \
)

SOURCES = \
$(addprefix $(SRCDIR), \
	is_ascii_sorted_64.c \
	is_ascii_sorted.c \
	main.c \
	nm_arch_header.c \
	nm_check_header.c \
	nm_fat_header.c \
	nm_mach_header_64.c \
	nm_mach_header.c \
	nm_map_file.c \
	nm_symtab_64.c \
	nm_symtab.c \
	symtree_add_64.c \
	symtree_add.c \
	symtree_create_64.c \
	symtree_create.c \
	symtree_delete_64.c \
	symtree_delete.c \
	write_symbols_64.c \
	write_symbols.c \
) \
$(addprefix $(GETDIR), \
	get_arch_header.c \
	get_fat_arch.c \
	get_fat_header.c \
	get_load_command.c \
	get_mach_header_64.c \
	get_mach_header.c \
	get_nlist_64.c \
	get_nlist.c \
	get_section_64.c \
	get_section.c \
	get_segment_command_64.c \
	get_segment_command.c \
	get_symtab_command.c \
)

OBJECTS = $(SOURCES:%.c=%.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LFT) $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c Makefile $(INCLUDES)
	$(CC) $(CFLAGS) -I includes -c -o $@ $<

$(LFT):
	make -C $(dir $(LFT))

clean:
	make -C $(dir $(LFT)) clean
	rm -f $(OBJECTS)

fclean:
	make -C $(dir $(LFT)) fclean
	rm -f $(OBJECTS)
	rm -f $(NAME)

re: fclean all
