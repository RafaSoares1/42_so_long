/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:51:28 by emsoares          #+#    #+#             */
/*   Updated: 2023/03/27 18:41:01 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <X11/X.h>
# include <fcntl.h>
# include <unistd.h>

# define WALL "./mandatory/textures/WALL.xpm"
# define FLOOR "./mandatory/textures/FLOOR.xpm"
# define PLAYERA "./mandatory/textures/RickA.xpm"
# define PLAYERD "./mandatory/textures/RickD.xpm"
# define PLAYERW "./mandatory/textures/RickW.xpm"
# define PLAYERS "./mandatory/textures/RickS.xpm"
# define COLLECT "./mandatory/textures/COLLECT.xpm"
# define EXIT "./mandatory/textures/EXIT.xpm"
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
	void	*exit_img;
	int		fd;
	int		lines;
	int		columns;
	char	**map;
	char	**map_dup;
	int		p_x;
	int		p_y;
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

//utils
int		ft_len(char const *str);
void	ft_init_stack(t_data *d);
int		ft_count_lines(t_data *d);

//check
void	ft_check_columns(t_data *d);
void	ft_check_lines(t_data *d);
void	ft_check_rectangle(t_data *d);
void	ft_check_letters(t_data *d);
void	ft_check_walls(t_data *d);

//check_path
void	ft_check_elements(t_data *d);
void	ft_map_dup(t_data *d);
int		ft_flood_fill(t_data *d, char **map, int x, int y);
void	ft_check_path(t_data *d);

//get
void	ft_get_player_coordinates(t_data *data);
void	ft_get_imgs(t_data *d, char *argv);

//free
int		ft_finish(t_data *d);
int		ft_finish2(t_data *d);
void	ft_free_map(t_data *data);
void	ft_free_map2(t_data *data);

//move
void	ft_put_image(t_data *d, int y, int x, char flag);
int		ft_move_player(t_data *d, int y, int x, char flag);
int		handle_input(int keysym, t_data *data);
#endif