NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

INCLUDES_DIR = includes
LIBS_DIR = libs
SRCS_DIR = srcs
OBJS_DIR = objs

LIBFT_DIR = libs/libft
LIBFT = libft.a

$(LIBFT) :
	make -C $(LIBFT_DIR) all
	
SRCS = $(addprefix $(SRCS_DIR)/, \
	push_swap.c \
	swap.c \
	push.c \
	rotate.c \
	reverse_rotate.c \
	parsing.c \
	sort.c \
	free.c)

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS) $(INCS)
	$(CC) $(CFLAGS) $(OBJS) -I $(INCLUDES_DIR) -L $(LIBFT_DIR) -o $@

%.o : %.c
	mkdir $(OBJS_DIR)
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
