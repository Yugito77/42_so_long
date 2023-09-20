/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:34:25 by hcherpre          #+#    #+#             */
/*   Updated: 2022/02/08 14:31:29 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_move_right(t_game *game)
{
	char	c;

	if (game->tab[game->pos_x][game->pos_y + 1] == '0')
	{
		c = game->tab[game->pos_x][game->pos_y + 1];
		game->tab[game->pos_x][game->pos_y + 1]
			= game->tab[game->pos_x][game->pos_y];
		game->tab[game->pos_x][game->pos_y] = c;
		create_img(game, PLAYER_RIGHT);
		create_map_player(game);
		return (1);
	}
	else if (game->tab[game->pos_x][game->pos_y + 1] == 'C')
	{
		game->tab[game->pos_x][game->pos_y + 1]
			= game->tab[game->pos_x][game->pos_y];
		game->tab[game->pos_x][game->pos_y] = '0';
		game->items_collected += 1;
		create_img(game, PLAYER_RIGHT);
		create_map_player(game);
		return (1);
	}
	else if (game->tab[game->pos_x][game->pos_y + 1] == 'E')
		ft_move_right_2(game);
	return (0);
}

int	ft_move_right_2(t_game *game)
{
	if (game->tab[game->pos_x][game->pos_y + 1] == 'E')
	{
		if (game->items == 0)
		{
			ft_exit(game);
			return (1);
		}
	}
	return (0);
}

int	ft_move_left(t_game *game)
{
	char	c;

	if (game->tab[game->pos_x][game->pos_y - 1] == '0')
	{
		c = game->tab[game->pos_x][game->pos_y - 1];
		game->tab[game->pos_x][game->pos_y - 1]
			= game->tab[game->pos_x][game->pos_y];
		game->tab[game->pos_x][game->pos_y] = c;
		create_img(game, PLAYER_LEFT);
		create_map_player(game);
		return (1);
	}
	else if (game->tab[game->pos_x][game->pos_y - 1] == 'C')
	{
		game->tab[game->pos_x][game->pos_y - 1]
			= game->tab[game->pos_x][game->pos_y];
		game->tab[game->pos_x][game->pos_y] = '0';
		game->items_collected += 1;
		create_img(game, PLAYER_LEFT);
		create_map_player(game);
		return (1);
	}
	else if (game->tab[game->pos_x][game->pos_y - 1] == 'E')
		ft_move_left_2(game);
	return (0);
}

int	ft_move_left_2(t_game *game)
{
	if (game->tab[game->pos_x][game->pos_y - 1] == 'E')
	{
		if (game->items == 0)
		{
			ft_exit(game);
			return (1);
		}
	}
	return (0);
}
