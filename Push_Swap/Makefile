# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jungchoi <jungchoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 14:46:19 by jungchoi          #+#    #+#              #
#    Updated: 2022/09/28 15:44:07 by jungchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

INCLUDES_DIR = includes
LIBS_DIR = libs
SRCS_DIR = srcs
OBJS_DIR = objs

LIBFT_DIR = libs/libft
LIBFT = libft.a

SRCS = $(addprefix $(SRCS_DIR)/, \
	push_swap.c \
	swap.c \
	push.c \
	rotate.c \
	reverse_rotate.c \
	parsing.c \
	parsing_utils.c \
	sort.c \
	sort_under_five.c \
	sort_over_five.c \
	free.c)

OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I $(INCLUDES_DIR) -L $(LIBFT_DIR) -lft -o $@


$(LIBFT) :
	make -C $(LIBFT_DIR) all
	
$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c
	@mkdir $(OBJS_DIR) 2> /dev/null || true
	$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -I $(LIBFT_DIR) -c $< -o $@

clean :
	rm -rf $(OBJS_DIR)
	make -C $(LIBFT_DIR) clean

fclean : clean
	rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean

re :
	make fclean
	make all

.PHONY = all clean fclean re
