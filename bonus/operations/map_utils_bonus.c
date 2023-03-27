/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:04:42 by emsoares          #+#    #+#             */
/*   Updated: 2023/03/27 18:47:00 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_fill_map_index(t_data *data)
{
	int		i;
	char	*str;

	i = 0;
	while (i <= data->lines)
	{
		str = get_next_line(data->fd);
		if (!str)
		{
			free(str);
			break ;
		}
		data->map[i] = ft_strtrim(str, "\n");
		free (str);
		i++;
	}
	data->columns = ft_strlen(data->map[0]);
	ft_check_lines(data);
	ft_check_rectangle(data);
}

void	ft_fill_window(t_data *d, int i, int j)
{
	while (i < d->lines)
	{
		j = 0;
		while (d->map[i][j] != '\n' && d ->map[i][j] != '\0')
		{
			ft_fill_image(d, i, j);
			j++;
		}
		i++;
	}
}

void	ft_read_map(t_data *d, char *argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	d->fd = open(argv, O_RDONLY);
	d->lines = ft_count_lines(d);
	close (d->fd);
	d->fd = open(argv, O_RDONLY);
	d->map = ft_calloc(d->lines + 1, sizeof(char *));
	ft_fill_map_index(d);
	d->win_ptr = mlx_new_window(d->mlx_ptr, ft_len(d->map[0]) * SIZE,
			d->lines * SIZE + 25, "so_long_bonus");
	if (d->win_ptr == NULL)
	{
		free(d->win_ptr);
		return ;
	}
	ft_fill_window(d, i, j);
	close (d->fd);
}

void	ft_fill_image(t_data *d, int i, int j)
{
	if (d->map[i][j] == '1')
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr,
			d->wall_img, j * SIZE, i * SIZE);
	else if (d->map[i][j] == '0')
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr,
			d->floor_img, j * SIZE, i * SIZE);
	else if (d->map[i][j] == 'C')
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr,
			d->collect_img, j * SIZE, i * SIZE);
	else if (d->map[i][j] == 'P')
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr,
			d->playerd_img, j * SIZE, i * SIZE);
	else if (d->map[i][j] == 'E')
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr,
			d->exit1_img, j * SIZE, i * SIZE);
	else if (d->map[i][j] == 'M')
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr,
			d->enemys, j * SIZE, i * SIZE);
}
