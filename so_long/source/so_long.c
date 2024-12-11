/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:34:49 by tle-saut          #+#    #+#             */
/*   Updated: 2024/12/11 15:23:13 by tle-saut         ###   ########.fr       */
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
	else if(ft_init_img(&mlx, &img) == 1)
		return (1);
	ft_printf("Map Valide, Launch The Game .....\n");
	int y = 0;
	int x = 0;
	while (map.map[y])
	{
		x = 0;
		while (map.map[y][x])
		{
			ft_printf("%c", map.map[y][x]);
			x++;
		}
		write(1,"\n",1);
		y++;
	}

	mlx.win = mlx_new_window(mlx.mlx, map.column * 70, map.line * 70, "Hello world!");
	mlx_key_hook(mlx.win, key_press, mlx.mlx);
	draw_map(mlx.mlx, mlx.win, &map, &img);
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
