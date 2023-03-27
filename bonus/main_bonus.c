/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:55:35 by emsoares          #+#    #+#             */
/*   Updated: 2023/03/24 09:50:08 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_check_map_file(t_data *d, char *file_name)
{
	int	i;

	i = 0;
	d->fd = open(file_name, O_RDONLY);
	i = ft_strlen(file_name) - 1;
	while (file_name[i] != '.')
		i--;
	if (ft_strncmp((file_name + i), ".ber", 4) != 0)
	{
		ft_putstr_fd("\033[0;31mError\nInvalid file type\n", 2);
		close(d->fd);
		exit(1);
	}
	if (d->fd < 0)
	{
		ft_putstr_fd("\033[0;31mError\nInvalid FD\n", 2);
		close(d->fd);
		exit(1);
	}
	close(d->fd);
	d->fd = 0;
}

int	main(int argc, char **argv)
{
	t_data	d;

	if (argc != 2)
	{
		ft_putstr_fd("\033[0;31mError\nCheck the input->./so_long Map_path\n", 2);
		return (0);
	}	
	ft_init_stack(&d);
	if (argc == 2)
	{
		srand(time(0));
		ft_check_map_file(&d, argv[1]);
		d.mlx_ptr = mlx_init();
		if (d.mlx_ptr == NULL)
			return (0);
		ft_get_imgs(&d, argv[1]);
		mlx_hook(d.win_ptr, KeyPress, KeyPressMask, handle_input, &d);
		mlx_hook(d.win_ptr, DestroyNotify, ButtonPressMask, ft_finish, &d);
		mlx_loop_hook(d.mlx_ptr, ft_animation, &d);
		mlx_loop(d.mlx_ptr);
	}
	return (0);
}
