# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amairia <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/30 07:23:57 by amairia           #+#    #+#              #
#    Updated: 2025/01/20 18:43:34 by amairia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

LIBFT_DIR = libft_with_gnl_printf/
LIBFT = $(LIBFT_DIR)libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

SRC_SRV =	src/server.c src/utils.c

SRC_CLT =	src/client.c src/utils.c

OBJ_SRV = $(SRC_SRV:.c=.o)

OBJ_CLT = $(SRC_CLT:.c=.o)

all : $(SERVER) $(CLIENT)

$(SERVER) : $(OBJ_SRV) $(LIBFT)
	$(CC) -o $@ $^ $(CFLAGS)

$(CLIENT) : $(OBJ_CLT) $(LIBFT)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR) pfgnl

clean :
	rm -f $(OBJ_CLT)
	rm -f $(OBJ_SRV)
	rm -f $(LIBFT)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean : clean
	rm -f $(SERVER)
	rm -f $(CLIENT)

re : fclean all

.PHONY : all clean fclean re
