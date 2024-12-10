/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:34:49 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/10 17:03:22 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define WALL 1
#define FREE 0

int	main(int ac, char **av)
{
	t_map	map;
	t_vars	mlx;
	t_data	img;

	mlx.mlx = mlx_init();
	if (ac != 2)
		return (ft_putstr_fd("Error from Arguments\n", 2), 1);
	if (ft_init_map(&map, av[1]) == 1)
		return (1);
	else
		ft_printf("Map Valide, Launch The Game .....\n");

	map.texture[WALL] = mlx_xpm_file_to_image(mlx.mlx, "terrain.xpm", 70, 70);
    map.texture[FREE] = mlx_xpm_file_to_image(mlx.mlx, "water.xpm", 70, 70);

	mlx.win = mlx_new_window(mlx.mlx, 1920, 1080, "Hello world!");
	mlx_key_hook(mlx.win, key_press, mlx.mlx);
	mlx_loop(mlx.mlx);

		
	return (0);
}
	void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int key_press(int keycode, void *param)
{
    if (keycode == 65307)  // Code de la touche 'Esc'
    {
        ft_printf("Touche ESC capturée !\n");
        mlx_loop_end(param);  // Quitte la boucle d'événements
    }
    else
    {
        ft_printf("Touche pressée: %d\n", keycode);
    }
    return (0);
}
