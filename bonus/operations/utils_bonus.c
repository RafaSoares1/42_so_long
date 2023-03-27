/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:37:53 by emsoares          #+#    #+#             */
/*   Updated: 2023/03/16 09:37:53 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_len(char const *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_init_stack(t_data *d)
{
	d->collect_img = 0;
	d->fd = 0;
	d->floor_img = 0;
	d->lines = 0;
	d->columns = 0;
	d->map = 0;
	d->map_dup = 0;
	d->mlx_ptr = 0;
	d->playera_img = 0;
	d->playerd_img = 0;
	d->playerw_img = 0;
	d->players_img = 0;
	d->enemys = 0;
	d->enemyw = 0;
	ft_init_stack2(d);
}

void	ft_init_stack2(t_data *d)
{
	d->enemya = 0;
	d->enemyd = 0;
	d->wall_img = 0;
	d->exit1_img = 0;
	d->exit2_img = 0;
	d->exit3_img = 0;
	d->black = 0;
	d->win_ptr = 0;
	d->x = 0;
	d->y = 0;
	d->p_x = 0;
	d->p_y = 0;
	d->e_x = 0;
	d->e_y = 0;
	d->collect = 0;
	d->moves = 0;
	d->e = 0;
	d->p = 0;
}

int	ft_count_lines(t_data *d)
{
	int		i;
	char	*str;

	i = 0;
	while (1)
	{
		str = get_next_line(d->fd);
		if (!str)
		{
			break ;
		}
		free(str);
		i++;
	}
	free (str);
	return (i);
}
