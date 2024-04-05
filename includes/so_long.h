/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machi <machi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 19:09:50 by ktakamat          #+#    #+#             */
/*   Updated: 2024/04/05 18:42:32 by machi            ###   ########.fr       */
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
# include	"../mlx/mlx.h"
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
// # define LAND "./textures/land.xpm"
// # define WALL "./textures/wall.xpm"
// # define CHA "./textures/chara.xpm"
// # define CHE "./textures/chest.xpm"
// # define RUNE "./textures/rune.xpm"
// # define RUNL "./textures/rune_l.xpm"

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

typedef struct s_game
{
	t_mlx		mlx;
	t_img		img;
	size_t		hei;
	size_t		wid;
	char		*str_line;
	int	col_cnt;
	int	all_col;
	int		walk_cnt;
}t_game;


void map_read(char *filename, t_game *game);
void	setting_img(t_game game);
char	*get_next_line(int fd);
char	*read_file(int fd, char *save);
char	*get_line(char *save);
char	*reset_save(char *save);
char    *ft_strjoin_new(char const *s1, char const *s2);
int	press_key(int key_code, t_game *game);
void	move_w(t_game *g);
void	move_s(t_game *g);
void	move_a(t_game *g);
void	move_d(t_game *g);
int	clear_game(t_game *game);
int	exit_game(t_game *game);
void	num_chara_goal(t_game *game);
void	no_item(t_game *game);
void check_first_line(t_game *game);
void	last_line(t_game *game);
void check_goal_reachable(t_game *game);
void find_p_position(t_game *game, size_t *p_x, size_t *p_y);
int can_reach_end(t_game *game, size_t x, size_t y);



#endif
