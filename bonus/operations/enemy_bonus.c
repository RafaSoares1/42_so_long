/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:18:43 by emsoares          #+#    #+#             */
/*   Updated: 2023/03/21 17:18:43 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_put_enemy(t_data *d, int y, int x, char flag)
{
	if (flag == 'A')
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->enemya,
			x * SIZE, y * SIZE);
	else if (flag == 'W')
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->enemyw,
			x * SIZE, y * SIZE);
	else if (flag == 'S')
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->enemys,
			x * SIZE, y * SIZE);
	else
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->enemyd,
			x * SIZE, y * SIZE);
}

int	ft_move_enemy(t_data *d, int y, int x, char flag)
{
	if (d->map[y][x] == '0')
	{
		ft_put_enemy(d, y, x, flag);
		d->map[y][x] = 'M';
		return (1);
	}
	else if (d->map[y][x] == 'P')
	{
		ft_printf("\033[0;31m😵 YOU GOT INFECTED 😵 \n");
		ft_finish (d);
	}
	return (0);
}

void	ft_check_move(t_data *d, int r, int y, int x)
{
	int	i;

	i = 0;
	if (r == 0)
		i = ft_move_enemy(d, y - 1, x, 'W');
	else if (r == 1)
		i = ft_move_enemy(d, y + 1, x, 'S');
	else if (r == 2)
		i = ft_move_enemy(d, y, x - 1, 'A');
	else if (r == 3)
		i = ft_move_enemy(d, y, x + 1, 'D');
	if (i == 1)
	{
		d->map[y][x] = '0';
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr,
			d->floor_img, x * SIZE, y * SIZE);
	}
}

void	ft_enemy(t_data *d)
{
	int	random;
	int	x;
	int	y;

	y = 0;
	while (y < d->lines)
	{
		x = 0;
		while (x < d->columns)
		{
			if (d->map[y][x] == 'M')
			{
				random = rand() % 4;
				ft_check_move(d, random, y, x);
				if (random == 3)
					x++;
				if (random == 1)
					y++;
			}
			x++;
		}
		y++;
	}
}
