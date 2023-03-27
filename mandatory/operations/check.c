/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:19:11 by emsoares          #+#    #+#             */
/*   Updated: 2023/03/16 09:19:11 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check_columns(t_data *d)
{
	if (d->columns < 3)
	{
		ft_putstr_fd("Error\nYou will need more columns in your map!\n", 2);
		ft_finish2(d);
		exit (0);
	}
}

void	ft_check_lines(t_data *d)
{
	if (d->lines < 3)
	{
		ft_putstr_fd("Error\nYou will need more lines in your map!\n", 2);
		ft_finish2(d);
		exit (0);
	}
	ft_check_columns(d);
}

void	ft_check_rectangle(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	while (i < d->lines)
	{
		j = 0;
		while (d->map[i][j])
			j++;
		if (j == d->columns)
			i++;
		else
		{
			ft_putstr_fd("Error\nThis map is not a rectangle!\n", 2);
			ft_finish2(d);
			exit(0);
		}
	}
	ft_check_letters(d);
}

void	ft_check_letters(t_data *d)
{
	int	y;
	int	x;

	y = 0;
	while (y < d->lines)
	{
		x = 0;
		while (x < d->columns)
		{
			if (d->map[y][x] == '1' || d->map[y][x] == '0' ||
				d->map[y][x] == 'C' || d->map[y][x] == 'P' ||
				d->map[y][x] == 'E')
				x++;
			else
			{
				ft_putstr_fd("Error\n Invalid elements in the map\n", 2);
				ft_finish2(d);
			}
		}
		y++;
	}
	ft_check_walls(d);
}

void	ft_check_walls(t_data *d)
{
	int	i;

	i = 0;
	while (i < d->columns)
	{
		if (d->map[0][i] != '1' || d->map[d->lines - 1][i] != '1')
		{
			ft_putstr_fd("Error\nWall not valid!\n", 2);
			ft_finish2(d);
		}
		i++;
	}
	i = 1;
	while (i < d->lines - 1)
	{
		if (d->map[i][0] != '1' || d->map[i][d->columns - 1] != '1')
		{
			ft_putstr_fd("Error\nWall not valid!\n", 2);
			ft_finish2(d);
		}
		i++;
	}
	ft_get_player_coordinates(d);
}
