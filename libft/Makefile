# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pguillie <pguillie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/24 11:24:18 by pguillie          #+#    #+#              #
#    Updated: 2019/02/08 22:34:56 by pguillie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

AR	= ar
CC	= gcc
CFLAGS	= -Wall -Werror -Wextra

INCDIR := includes/
SRCDIR := sources/

INCLUDES = \
$(addprefix $(INCDIR), \
	libft.h \
)

SOURCES = \
$(addprefix $(SRCDIR), \
	ft_memcpy.c \
	ft_memset.c \
	ft_putstr.c \
	ft_strcmp.c \
	ft_strlen.c \
	ft_strncmp.c \
)

OBJECTS = $(SOURCES:%.c=%.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) -rc $@ $^

%.o: %.c Makefile $(INCLUDES)
	$(CC) $(CFLAGS) -I$(INCDIR) -c -o $@ $<

clean:
	rm -f $(OBJECTS)

fclean:
	rm -f $(OBJECTS)
	rm -f $(NAME)

re: fclean all
