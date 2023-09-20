/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:59:00 by hcherpre          #+#    #+#             */
/*   Updated: 2022/02/08 14:29:07 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_map_player(t_game *game)
{
	game->i = 0;
	game->y = 0;
	while (game->tab[game->i])
	{
		game->x = 0;
		game->j = 0;
		while (game->tab[game->i][game->j])
		{
			if (game->tab[game->i][game->j] == 'P')
			{
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->img_player, game->x, game->y);
				break ;
			}
			game->j += 1;
			game->x += 50;
		}
		if (game->tab[game->i][game->j] == 'P')
			break ;
		game->i += 1;
		game->y += 50;
	}
	game->pos_x = game->i;
	game->pos_y = game->j;
	create_map_wall(game);
}

void	create_map_wall(t_game *game)
{
	game->i = 0;
	game->y = 0;
	while (game->tab[game->i])
	{
		game->x = 0;
		game->j = 0;
		while (game->tab[game->i][game->j])
		{
			if (game->tab[game->i][game->j] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->img_wall, game->x, game->y);
			game->j += 1;
			game->x += 50;
		}
		game->i += 1;
		game->y += 50;
	}
	create_map_ground(game);
}

void	create_map_ground(t_game *game)
{
	game->i = 0;
	game->y = 0;
	while (game->tab[game->i])
	{
		game->x = 0;
		game->j = 0;
		while (game->tab[game->i][game->j])
		{
			if (game->tab[game->i][game->j] == '0')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->img_ground, game->x, game->y);
			game->j += 1;
			game->x += 50;
		}
		game->i += 1;
		game->y += 50;
	}
	create_map_items(game);
}

void	create_map_items(t_game *game)
{
	game->i = 0;
	game->y = 0;
	game->items = 0;
	while (game->tab[game->i])
	{
		game->x = 0;
		game->j = 0;
		while (game->tab[game->i][game->j])
		{
			if (game->tab[game->i][game->j] == 'C')
			{
				game->items += 1;
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->img_items, game->x, game->y);
			}
			game->j += 1;
			game->x += 50;
		}
		game->i += 1;
		game->y += 50;
	}
	create_map_exit(game);
}

void	create_map_exit(t_game *game)
{
	game->i = 0;
	game->y = 0;
	while (game->tab[game->i])
	{
		game->x = 0;
		game->j = 0;
		while (game->tab[game->i][game->j])
		{
			if (game->tab[game->i][game->j] == 'E')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->img_exit, game->x, game->y);
			game->j++;
			game->x += 50;
		}
		game->i += 1;
		game->y += 50;
	}
}
