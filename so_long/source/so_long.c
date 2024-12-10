/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:34:49 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/10 16:10:15 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

		
	mlx.mlx= mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, 8, 8, 0x00FF0000);
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
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
