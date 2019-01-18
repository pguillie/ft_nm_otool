# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/08 15:27:58 by pguillie          #+#    #+#              #
#    Updated: 2019/01/18 23:19:28 by pguillie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_nm

CC	= gcc
CFLAGS	= -Wall -Werror -Wextra

INCLUDES = \
$(addprefix includes/, \
	ft_nm.h \
)

SOURCES = \
$(addprefix sources/, \
	get_load_command.c \
	get_mach_header.c \
	get_nlist.c \
	get_section.c \
	get_segment_command.c \
	get_symtab_command.c \
	main.c \
	nm_check_header.c \
	nm_mach_header.c \
	nm_map_file.c \
	nm_symtab.c \
)

OBJECTS = $(SOURCES:%.c=%.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) -o $@ $^

%.o: %.c Makefile $(INCLUDES)
	$(CC) $(CFLAGS) -I includes -c -o $@ $<

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
