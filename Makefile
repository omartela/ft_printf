# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omartela <omartela@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 15:46:36 by omartela          #+#    #+#              #
#    Updated: 2024/05/01 17:05:51 by omartela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a

SRC = ft_printf.c \
	  ft_print_ptr.c \
	  ft_print_unsnbr.c \
	  ft_printf_utils.c \
	  ft_print_hex.c

OBJS = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I. -I$(LIBFT_DIR)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(AR) $(NAME) $(OBJS)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

%.o:%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

