/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:40:17 by hcherpre          #+#    #+#             */
/*   Updated: 2022/02/07 16:59:45 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->lignes)
	{
		free(game->tab[i]);
		i++;
	}
	free(game->tab);
}

void	destroy_img(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_image(game->mlx, game->img_player);
	mlx_destroy_image(game->mlx, game->img_items);
	mlx_destroy_image(game->mlx, game->img_ground);
	mlx_destroy_image(game->mlx, game->img_exit);
}
