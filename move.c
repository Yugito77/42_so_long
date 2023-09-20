/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:10:09 by hcherpre          #+#    #+#             */
/*   Updated: 2022/02/08 14:30:39 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_move(int keycode, t_game *game)
{
	static int	moves = 1;

	if (keycode == 13)
	{
		if (ft_move_up(game) == 1)
			printf("moves: %d\n", moves++);
	}
	if (keycode == 1)
	{
		if (ft_move_down(game) == 1)
			printf("moves: %d\n", moves++);
	}
	if (keycode == 2)
	{
		if (ft_move_right(game) == 1)
			printf("moves: %d\n", moves++);
	}
	if (keycode == 0)
	{
		if (ft_move_left(game) == 1)
			printf("moves: %d\n", moves++);
	}
	return (0);
}

int	ft_move_up(t_game *game)
{
	char	c;

	if (game->tab[game->pos_x - 1][game->pos_y] == '0')
	{
		c = game->tab[game->pos_x - 1][game->pos_y];
		game->tab[game->pos_x - 1][game->pos_y]
			= game->tab[game->pos_x][game->pos_y];
		game->tab[game->pos_x][game->pos_y] = c;
		create_img(game, PLAYER_BACK);
		create_map_player(game);
		return (1);
	}
	else if (game->tab[game->pos_x - 1][game->pos_y] == 'C')
	{
		game->tab[game->pos_x - 1][game->pos_y]
			= game->tab[game->pos_x][game->pos_y];
		game->tab[game->pos_x][game->pos_y] = '0';
		game->items_collected += 1;
		create_img(game, PLAYER_BACK);
		create_map_player(game);
		return (1);
	}
	else if (game->tab[game->pos_x - 1][game->pos_y] == 'E')
		ft_move_up_2(game);
	return (0);
}

int	ft_move_up_2(t_game *game)
{
	if (game->tab[game->pos_x - 1][game->pos_y] == 'E')
	{
		if (game->items == 0)
		{
			ft_exit(game);
			return (1);
		}
	}
	return (0);
}

int	ft_move_down(t_game *game)
{
	char	c;

	if (game->tab[game->pos_x + 1][game->pos_y] == '0')
	{
		c = game->tab[game->pos_x + 1][game->pos_y];
		game->tab[game->pos_x + 1][game->pos_y]
			= game->tab[game->pos_x][game->pos_y];
		game->tab[game->pos_x][game->pos_y] = c;
		create_img(game, PLAYER_FRONT);
		create_map_player(game);
		return (1);
	}
	else if (game->tab[game->pos_x + 1][game->pos_y] == 'C')
	{
		game->tab[game->pos_x + 1][game->pos_y]
			= game->tab[game->pos_x][game->pos_y];
		game->tab[game->pos_x][game->pos_y] = '0';
		game->items_collected += 1;
		create_img(game, PLAYER_FRONT);
		create_map_player(game);
		return (1);
	}
	else if (game->tab[game->pos_x + 1][game->pos_y] == 'E')
		ft_move_down_2(game);
	return (0);
}

int	ft_move_down_2(t_game *game)
{
	if (game->tab[game->pos_x + 1][game->pos_y] == 'E')
	{
		if (game->items == 0)
		{
			ft_exit(game);
			return (1);
		}
	}
	return (0);
}
