/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 22:24:06 by emsoares          #+#    #+#             */
/*   Updated: 2023/03/15 22:24:06 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_get_player_coordinates(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->lines)
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				data->p_x = j;
				data->p_y = i;
				data->p += 1;
			}
			if (data->map[i][j] == 'C')
				data->collect += 1;
			if (data->map[i][j] == 'E')
				ft_get_exit_coord(data, j, i);
			j++;
		}
		i++;
	}
	ft_check_elements(data);
}

void	ft_get_imgs(t_data *d, char *argv)
{
	d->floor_img = mlx_xpm_file_to_image(d->mlx_ptr, FLOOR, &d->x, &d->y);
	d->wall_img = mlx_xpm_file_to_image(d->mlx_ptr, WALL, &d->x, &d->y);
	d->playera_img = mlx_xpm_file_to_image(d->mlx_ptr, PLAYERA, &d->x, &d->y);
	d->playerd_img = mlx_xpm_file_to_image(d->mlx_ptr, PLAYERD, &d->x, &d->y);
	d->playerw_img = mlx_xpm_file_to_image(d->mlx_ptr, PLAYERW, &d->x, &d->y);
	d->players_img = mlx_xpm_file_to_image(d->mlx_ptr, PLAYERS, &d->x, &d->y);
	d->exit1_img = mlx_xpm_file_to_image(d->mlx_ptr, PORTAL1, &d->x, &d->y);
	d->exit2_img = mlx_xpm_file_to_image(d->mlx_ptr, PORTAL2, &d->x, &d->y);
	d->exit3_img = mlx_xpm_file_to_image(d->mlx_ptr, PORTAL3, &d->x, &d->y);
	d->collect_img = mlx_xpm_file_to_image(d->mlx_ptr, COLLECT, &d->x, &d->y);
	d->enemys = mlx_xpm_file_to_image(d->mlx_ptr, ENEMYS, &d->x, &d->y);
	d->enemyw = mlx_xpm_file_to_image(d->mlx_ptr, ENEMYW, &d->x, &d->y);
	d->enemya = mlx_xpm_file_to_image(d->mlx_ptr, ENEMYA, &d->x, &d->y);
	d->enemyd = mlx_xpm_file_to_image(d->mlx_ptr, ENEMYD, &d->x, &d->y);
	d->black = mlx_xpm_file_to_image(d->mlx_ptr, BLACK, &d->x, &d->y);
	ft_read_map(d, argv);
}

void	ft_get_exit_coord(t_data *d, int j, int i)
{
	d->e_x = j;
	d->e_y = i;
	d->e += 1;
}
