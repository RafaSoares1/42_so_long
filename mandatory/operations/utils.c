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

#include "../so_long.h"

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
	d->exit_img = 0;
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
	d->wall_img = 0;
	d->win_ptr = 0;
	d->x = 0;
	d->y = 0;
	d->p_x = 0;
	d->p_y = 0;
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
			break ;
		free(str);
		i++;
	}
	free (str);
	return (i);
}
