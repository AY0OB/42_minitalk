# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amairia <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 13:28:33 by amairia           #+#    #+#              #
#    Updated: 2024/11/25 18:51:13 by amairia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
AR = ar rcs

SRC =	ft_isascii.c ft_memset.c ft_memcmp.c ft_memchr.c ft_strlcpy.c ft_substr.c\
	ft_bzero.c ft_isdigit.c ft_strchr.c ft_strnstr.c ft_strlen.c ft_tolower.c\
	ft_calloc.c ft_isprint.c ft_strdup.c ft_strncmp.c ft_toupper.c ft_isalnum.c\
	ft_memcpy.c ft_strjoin.c ft_strrchr.c ft_isalpha.c ft_memmove.c ft_strlcat.c\
	ft_strtrim.c ft_split.c ft_itoa.c ft_atoi.c ft_strmapi.c ft_striteri.c\
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJ = $(SRC:.c=.o)

BNS =	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ_BNS = $(BNS:.c=.o)

PF =	ft_printf.c ft_put_c_to_i.c ft_put_u_to_none.c

OBJ_PF = $(PF:.c=.o)

GNL =	get_next_line.c get_next_line_utils.c

OBJ_GNL = $(GNL:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) $@ $^

$(OBJ) : $(SRC)
	$(CC) $(CFLAGS) -c $^

$(OBJ_BNS) : $(BNS)
	$(CC) $(CFLAGS) -c $^

$(OBJ_PF) : $(PF)
	$(CC) $(CFLAGS) -c $^

$(OBJ_GNL) : $(GNL)
	$(CC) $(CFLAGS) -c $^

bonus : $(NAME) $(OBJ) $(OBJ_BNS)
	$(AR) $(NAME) $(OBJ) $(OBJ_BNS)

pfgnl : $(NAME) $(OBJ) $(OBJ_BNS) $(OBJ_PF) $(OBJ_GNL)
	$(AR) $(NAME) $(OBJ) $(OBJ_BNS) $(OBJ_PF) $(OBJ_GNL)

clean :
	rm -f $(OBJ) $(OBJ_BNS) $(OBJ_PF) $(OBJ_GNL)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus so pfgnl
