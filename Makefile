# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktakamat <ktakamat@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/30 17:11:04 by ktakamat          #+#    #+#              #
#    Updated: 2024/04/18 18:04:42 by ktakamat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
INCLUDES_DIR = ./Includes
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES_DIR)

SRCS = main.c \
		map.c \
		get_next_line.c \
		move.c\
		move_key.c\
		error.c\
		error2.c\
		tansaku_error1.c\
		tansaku_error2.c\
		tansaku_item.c


OBJS = $(SRCS:%.c=%.o)

LIBDIR = ./libft
LIBFT = $(LIBDIR)/libft.a

MLXDIR = ./mlx
MLX = $(MLXDIR)/libmlx.a

MLX_SRC = mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c mlx_png.c mlx_mouse.m
MLX_OBJ = $(MLX_SRC:.c=.o) $(MLX_SRC:.m=.o)

CFLAGS += -O2 -DSTRINGPUTX11

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBDIR)


$(MLX):
	$(MAKE) -C $(MLXDIR)

clean:
	$(MAKE) clean -C $(LIBDIR)
	$(MAKE) clean -C $(MLXDIR)
	$(RM) $(OBJS) $(MLX_OBJ)

fclean: clean
	$(MAKE) fclean -C $(LIBDIR)
	$(RM) $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re