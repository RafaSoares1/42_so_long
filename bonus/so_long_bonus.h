/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:51:28 by emsoares          #+#    #+#             */
/*   Updated: 2023/03/27 18:42:47 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <X11/X.h>
# include <fcntl.h>
# include <time.h>
# include <unistd.h>

# define WALL "./bonus/textures/WALL.xpm"
# define FLOOR "./bonus/textures/FLOOR.xpm"
# define PLAYERA "./bonus/textures/RickA.xpm"
# define PLAYERD "./bonus/textures/RickD.xpm"
# define PLAYERW "./bonus/textures/RickW.xpm"
# define PLAYERS "./bonus/textures/RickS.xpm"
# define COLLECT "./bonus/textures/COLLECT.xpm"
# define PORTAL1 "./bonus/textures/PORTAL1.xpm"
# define PORTAL2 "./bonus/textures/PORTAL2.xpm"
# define PORTAL3 "./bonus/textures/PORTAL3.xpm"
# define ENEMYS "./bonus/textures/MORTYS.xpm"
# define ENEMYW "./bonus/textures/MORTYW.xpm"
# define ENEMYA "./bonus/textures/MORTYA.xpm"
# define ENEMYD "./bonus/textures/MORTYD.xpm"
# define BLACK "./bonus/textures/black.xpm"
# define SIZE 45

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		y;
	void	*wall_img;
	void	*floor_img;
	void	*collect_img;
	void	*playera_img;
	void	*playerd_img;
	void	*playerw_img;
	void	*players_img;
	void	*exit1_img;
	void	*exit2_img;
	void	*exit3_img;
	void	*enemys;
	void	*enemyw;
	void	*enemya;
	void	*enemyd;
	void	*black;
	int		fd;
	int		lines;
	int		columns;
	char	**map;
	char	**map_dup;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	int		collect;
	int		moves;
	int		p;
	int		e;
}				t_data;

//main
void	ft_check_map_file(t_data *d, char *file_name);

//map_utils
void	ft_fill_map_index(t_data *data);
void	ft_fill_window(t_data *d, int i, int j);
void	ft_read_map(t_data *data, char *argv);
void	ft_fill_image(t_data *d, int i, int j);

//utils
int		ft_len(char const *str);
void	ft_init_stack(t_data *d);
void	ft_init_stack2(t_data *d);
int		ft_count_lines(t_data *d);

//check
void	ft_check_columns(t_data *d);
void	ft_check_lines(t_data *d);
void	ft_check_letters(t_data *d);
void	ft_check_walls(t_data *d);
void	ft_check_rectangle(t_data *d);

//check_path
void	ft_check_elements(t_data *d);
void	ft_map_dup(t_data *d);
int		ft_flood_fill(t_data *d, char **map, int x, int y);
void	ft_check_path(t_data *d);

//get
void	ft_get_player_coordinates(t_data *data);
void	ft_get_imgs(t_data *d, char *argv);
void	ft_get_exit_coord(t_data *d, int j, int i);

//free
int		ft_finish(t_data *d);
int		ft_finish2(t_data *d);
void	ft_free_map(t_data *data);
void	ft_free_map2(t_data *data);

//move
void	ft_put_image(t_data *d, int y, int x, char flag);
int		ft_move_player(t_data *d, int y, int x, char flag);
int		handle_input(int keysym, t_data *data);

//animation
int		ft_animation(t_data *d);

//enemy
void	ft_put_enemy(t_data *d, int y, int x, char flag);
int		ft_move_enemy(t_data *d, int y, int x, char flag);
void	ft_check_move(t_data *d, int r, int y, int x);
void	ft_enemy(t_data *d);

#endif