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

#include "../so_long.h"

void	ft_get_player_coordinates(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->lines)
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				data->p_x = j;
				data->p_y = i;
				data->p ++;
			}
			if (data->map[i][j] == 'C')
				data->collect++;
			if (data->map[i][j] == 'E')
				data->e++;
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
	d->exit_img = mlx_xpm_file_to_image(d->mlx_ptr, EXIT, &d->x, &d->y);
	d->collect_img = mlx_xpm_file_to_image(d->mlx_ptr, COLLECT, &d->x, &d->y);
	ft_read_map(d, argv);
}
