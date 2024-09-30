# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tomek <tomek@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/29 19:26:22 by tomek             #+#    #+#              #
#    Updated: 2024/09/30 22:57:37 by tomek            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror -g
RM			=	rm -rf
LIBFT_DIR	=	./libft
LIBFT		=	$(LIBFT_DIR)/libft.a
MLX_DIR		=	./minilibx-linux
MLX_LIB		=	$(MLX_DIR)/libmlx.a
SRCS		=	src/main.c \
				src/init.c \
				src/init_map.c \
				src/cleanup.c \
				src/errors.c \
				src/utils.c \
				src/map_checks.c \
				src/validate_map.c
OBJS		=	$(SRCS:.c=.o)
BONUS_OBJS	=	$(BONUS_SRCS:.c=.o)
LDFLAGS		=	-L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz
INCLUDES	=	-I$(LIBFT_DIR) -I$(MLX_DIR)

all:	$(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

so_long: $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(LDFLAGS)

%.o:	%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re:	fclean all

.PHONY: all clean fclean re