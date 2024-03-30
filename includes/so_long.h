/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakamat <ktakamat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 19:09:50 by ktakamat          #+#    #+#             */
/*   Updated: 2024/03/30 19:10:27 by ktakamat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <limits.h>
# include <fcntl.h>
# include	"mlx.h"
# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include <stdbool.h>

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define LAND "./textures/land.xpm"
# define WALL "./textures/wall.xpm"
# define CHA "./textures/chara.xpm"
# define CHE "./textures/chest.xpm"
# define RUNE "./textures/rune.xpm"
# define RUNL "./textures/rune_l.xpm"

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 100

# endif

# define MAX_SIZE 1500

typedef struct s_stack{
	int	x;
	int	y;
}	t_stack;

typedef struct s_mlx{
	void	*m_ptr;
	void	*w_ptr;
}	t_mlx;

typedef struct s_img{
	void	*land;
	void	*wall;
	void	*chara;
	void	*chest;
	void	*chest_open;
	void	*rune;
	void	*runl;
	int		width;
	int		height;
}	t_img;

typedef struct s_map{
	t_mlx	mlx;
	t_img	img;
	size_t	height;
	size_t	width;
	char	*str_line;
	char	col_cnt;
	char	all_col;
	int		walk_cnt;
	int		flag;
	int		top;
	int		now_col;
	int		xi;
	int		yi;
}	t_map;

void	map_read(char *map, t_map *game);

#endif