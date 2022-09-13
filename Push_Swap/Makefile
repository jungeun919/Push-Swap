# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/14 07:14:03 by jungchoi          #+#    #+#              #
#    Updated: 2022/09/14 07:26:28 by jungchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

INCLUDES_DIR = ./includes/
LIBS_DIR = ./libs/
SRCS_DIR = ./srcs/
OBJS_DIR = ./objs/

SRCS = $(addprefix $(SRCS_DIR)/, \push_swap.c \
	swap.c \
	push.c \
	rotate.c \
	reverse_rotate.c \
	parsing.c \
	sort.c)
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

LIBFT_NAME = libft
LIBFT_DIR = $(LIBS_DIR)$(LIBFT_NAME)
LIBFT = $(LIBFT_DIR)$(LIBFT_NAME).a

$(LIBFT) :
	make -C $(LIBS_DIR) $(LIBFT_DIR) all

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS) $(INCS)
	$(CC) $(CFLAGS) $(OBJS) -I $(INCLUDES_DIR) -L $(LIBFT_DIR) -l $(LIBFT_NAME) -o $@

$(OBJS_DIR)%.o : %.c
	mkdir $(OBJS_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -I $(LIBFT_DIR) -c $< -o $@

clean :
	rm -rf $(OBJS)
	make -C $(LIBS_DIR)$(LIBFT_DIR) clean

fclean : clean
	rm -rf $(NAME)
	make -C $(LIBS_DIR)$(LIBFT_DIR) fclean

re : fclean all

.PHONY = all clean fclean re
