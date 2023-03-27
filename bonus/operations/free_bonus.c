/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:19:30 by emsoares          #+#    #+#             */
/*   Updated: 2023/03/16 09:19:30 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_finish(t_data *d)
{
	mlx_destroy_image(d->mlx_ptr, d->floor_img);
	mlx_destroy_image(d->mlx_ptr, d->wall_img);
	mlx_destroy_image(d->mlx_ptr, d->playera_img);
	mlx_destroy_image(d->mlx_ptr, d->playerd_img);
	mlx_destroy_image(d->mlx_ptr, d->playerw_img);
	mlx_destroy_image(d->mlx_ptr, d->players_img);
	mlx_destroy_image(d->mlx_ptr, d->exit1_img);
	mlx_destroy_image(d->mlx_ptr, d->exit2_img);
	mlx_destroy_image(d->mlx_ptr, d->exit3_img);
	mlx_destroy_image(d->mlx_ptr, d->collect_img);
	mlx_destroy_image(d->mlx_ptr, d->enemys);
	mlx_destroy_image(d->mlx_ptr, d->enemyw);
	mlx_destroy_image(d->mlx_ptr, d->enemya);
	mlx_destroy_image(d->mlx_ptr, d->enemyd);
	mlx_destroy_image(d->mlx_ptr, d->black);
	ft_free_map(d);
	mlx_destroy_window(d->mlx_ptr, d->win_ptr);
	mlx_destroy_display(d->mlx_ptr);
	free(d->mlx_ptr);
	exit(0);
}

int	ft_finish2(t_data *d)
{
	mlx_destroy_image(d->mlx_ptr, d->floor_img);
	mlx_destroy_image(d->mlx_ptr, d->wall_img);
	mlx_destroy_image(d->mlx_ptr, d->playera_img);
	mlx_destroy_image(d->mlx_ptr, d->playerd_img);
	mlx_destroy_image(d->mlx_ptr, d->playerw_img);
	mlx_destroy_image(d->mlx_ptr, d->players_img);
	mlx_destroy_image(d->mlx_ptr, d->exit1_img);
	mlx_destroy_image(d->mlx_ptr, d->exit2_img);
	mlx_destroy_image(d->mlx_ptr, d->exit3_img);
	mlx_destroy_image(d->mlx_ptr, d->collect_img);
	mlx_destroy_image(d->mlx_ptr, d->enemys);
	mlx_destroy_image(d->mlx_ptr, d->enemyw);
	mlx_destroy_image(d->mlx_ptr, d->enemya);
	mlx_destroy_image(d->mlx_ptr, d->enemyd);
	mlx_destroy_image(d->mlx_ptr, d->black);
	mlx_destroy_display(d->mlx_ptr);
	if (d->map != 0)
		ft_free_map(d);
	free(d->mlx_ptr);
	exit(0);
}

void	ft_free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}

void	ft_free_map2(t_data *data)
{
	int	i;

	i = 0;
	while (data->map_dup[i])
	{
		free(data->map_dup[i]);
		i++;
	}
	free(data->map_dup);
}
