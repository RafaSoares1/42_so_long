/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 22:16:44 by emsoares          #+#    #+#             */
/*   Updated: 2023/03/15 22:16:44 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_check_elements(t_data *d)
{
	if (d->p != 1)
	{
		ft_putstr_fd("\033[0;31mError\nWrong number of player elements!\n", 2);
		ft_finish2(d);
		exit (0);
	}
	else if (d->e != 1)
	{
		ft_putstr_fd("\033[0;31mError\nWrong number of exit elements!\n", 2);
		ft_finish2(d);
		exit (0);
	}
	else if (d->collect < 1)
	{
		ft_putstr_fd("\033[0;31mError\nWrong number of collectibles!\n", 2);
		ft_finish2(d);
		exit (0);
	}
	ft_check_path(d);
}

void	ft_map_dup(t_data *d)
{
	int	i;

	i = 0;
	d->map_dup = ft_calloc(d->lines + 1, sizeof(char *));
	while (i < d->lines)
	{
		d->map_dup[i] = ft_strdup(d->map[i]);
		i++;
	}
}

int	ft_flood_fill(t_data *d, char **map, int x, int y)
{
	static int	c;
	static int	e;

	if (y < 0 || x < 0 || y > d->lines || x > d->columns
		|| map[y][x] == '1' || map[y][x] == 'X')
		return (0);
	if (map[y][x] == 'E')
	{	
		e++;
		map[y][x] = 'X';
		return (0);
	}
	if (map[y][x] == 'C')
		c++;
	map[y][x] = 'X';
	ft_flood_fill(d, map, x + 1, y);
	ft_flood_fill(d, map, x - 1, y);
	ft_flood_fill(d, map, x, y + 1);
	ft_flood_fill(d, map, x, y - 1);
	if (e == 1 && c == d->collect)
		return (1);
	else
		return (0);
}

void	ft_check_path(t_data *d)
{
	ft_map_dup(d);
	if (ft_flood_fill(d, d->map_dup, d->p_x, d->p_y) != 1)
	{
		ft_putstr_fd("\033[0;31mError\nInvalid Map Path\n", 2);
		ft_free_map2(d);
		ft_finish2(d);
	}
	else
		ft_free_map2(d);
}
