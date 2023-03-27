/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:02:15 by emsoares          #+#    #+#             */
/*   Updated: 2023/03/21 11:02:15 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_animation(t_data *d)
{
	static int	i;
	int			num;

	num = 18000;
	i++;
	if (i == num)
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr,
			d->exit1_img, d->e_x * SIZE, d->e_y * SIZE);
	else if (i == num * 2)
	{
		ft_enemy(d);
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr,
			d->exit2_img, d->e_x * SIZE, d->e_y * SIZE);
	}
	else if (i == num * 3)
	{
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr,
			d->exit3_img, d->e_x * SIZE, d->e_y * SIZE);
		i = 0;
	}
	return (1);
}
