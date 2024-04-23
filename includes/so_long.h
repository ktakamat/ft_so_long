/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakamat <ktakamat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 19:09:50 by ktakamat          #+#    #+#             */
/*   Updated: 2024/04/23 16:06:46 by ktakamat         ###   ########.fr       */
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
# define FILE_EXTENSION ".ber"
# define MAX_HEI 32
# define MAX_WID 58

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

typedef struct s_game
{
	t_mlx	mlx;
	t_img	img;
	size_t	hei;
	size_t	wid;
	char	*str_line;
	char	col_cnt;
	char	all_col;
	int		walk_cnt;
	int		flag;
	int		top;
	int		now_col;
	int		xi;
	int		yi;
	int		error_item;
}	t_game;

typedef struct s_ma
{
	void		*mlx;
	void		*win;
}	t_ma;

typedef struct s_last
{
	size_t	index;
	size_t	expected_width;
	size_t	last_width;
	size_t	i;
	char	*last_line_start;
	char	*last_line_end;
	char	*ptr;
}	t_last;

void	map_read(char *filename, t_game *game);
void	setting_img(t_game *game);
void	put_img(t_game *game, char alpha, size_t x, size_t y);
char	*get_next_line(int fd);
char	*read_file(int fd, char *save);
char	*get_line(char *save);
char	*reset_save(char *save);
char	*ft_strjoin_new(char const *s1, char const *s2);
int		press_key(int key_code, t_game *game);
void	move_w(t_game *g);
void	move_s(t_game *g);
void	move_a(t_game *g);
void	move_d(t_game *g);
int		clear_game(t_game *game);
int		exit_game(t_game *game);
void	num_chara_goal(t_game *game);
void	no_item(t_game *game);
void	check_first_line(t_game *game);
void	last_line(t_game *game);
void	check_goal_reachable(t_game *game);
void	find_p_position(t_game *game, size_t *p_x, size_t *p_y);
int		can_reach_end(t_game *game, size_t x, size_t y);
bool	check_o(t_game *game, size_t x, size_t y);
bool	check_e(t_game *game, size_t x, size_t y);
void	can_pass(t_game *game, bool *visited, t_stack *stack);
void	terms_pass(t_game *game, bool *visited, t_stack *stack);
bool	reach_goal(t_game *game, size_t x, size_t y);
size_t	find_p(t_game *game);
bool	pass_find1(t_game *game, bool *visited, t_stack *stack);
bool	reach_e(t_game *game);
void	ft_exit(void);
bool	reach_item(t_game *game, size_t x, size_t y);
size_t	find_c(t_game *game);
bool	pass_find2(t_game *game, bool *visited, t_stack *stack);
bool	no_c(t_game *game);
bool	reach_c(t_game *game);
bool	have_ber(const char *filename);
void	map_word(char *map_str);
size_t	count_coin(t_game *game);
void	init_textures(void *mlx, t_game *game, int *img_width, int *img_height);
void	init_game_window(t_game *game, void *mlx, void *win);
bool	check1(const char *filename, t_game *game);
bool	check2(t_game *game);
void	run_game_loop(void *mlx);
void	check_map_edges(t_game *game);
void	map_limit(t_game *game);

#endif
