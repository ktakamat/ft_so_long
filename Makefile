# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: machi <machi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/30 17:11:04 by ktakamat          #+#    #+#              #
#    Updated: 2024/04/13 19:04:05 by machi            ###   ########.fr        #
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
		error.c\
		tansaku_error1.c\
		tansaku_error2.c\
		tansaku_item.c


OBJS = $(SRCS:%.c=%.o)

LIBDIR = ./libft
LIBFT = $(LIBDIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBDIR)

clean:
	$(MAKE) clean -C $(LIBDIR)
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBDIR)
	$(RM) $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean rearch -x86_64 gcc -L./mlx -lmlx -framework OpenGL -framework AppKit main.c