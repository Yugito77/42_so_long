/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:58:24 by hcherpre          #+#    #+#             */
/*   Updated: 2022/02/08 20:40:01 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_img(t_game *game, char *player)
{
	game->img_player = mlx_xpm_file_to_image(game->mlx, player,
			&game->img_width, &game->img_height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, WALL,
			&game->img_width, &game->img_height);
	game->img_ground = mlx_xpm_file_to_image(game->mlx, GROUND,
			&game->img_width, &game->img_height);
	game->img_items = mlx_xpm_file_to_image(game->mlx, ITEMS,
			&game->img_width, &game->img_height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, PORTAL,
			&game->img_width, &game->img_height);
	create_map_player(game);
}

void	ft_exit(t_game *game)
{
	printf("Congratulations !!!");
	destroy_img(game);
	mlx_destroy_window(game->mlx, game->mlx_win);
	ft_free(game);
	free(game->mlx);
	exit(0);
}

int	ft_close(t_game *game)
{
	printf("GAME CLOSED!\n");
	destroy_img(game);
	mlx_destroy_window(game->mlx, game->mlx_win);
	ft_free(game);
	free(game->mlx);
	exit(0);
}

int	ft_close_esc(int keycode, t_game *game)
{
	if (keycode == 53)
	{
		printf("GAME CLOSED!\n");
		destroy_img(game);
		mlx_destroy_window(game->mlx, game->mlx_win);
		ft_free(game);
		free(game->mlx);
		exit(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2 || !check_file(argv[1]))
		return (0);
	game.mlx = mlx_init();
	game.tab = create_tab(&game, argv[1]);
	if (!check_map(&game) || !check_char(&game)
		|| !check_nb_char(&game) || !check_wall(&game))
	{
		printf("Error\nCarte incorrect !\n");
		ft_free(&game);
		free(game.mlx);
		return (0);
	}
	game.mlx_win = mlx_new_window(game.mlx, game.win_width, game.win_height,
			"so_long");
	create_img(&game, PLAYER_FRONT);
	mlx_hook(game.mlx_win, 2, 1L << 0, ft_close_esc, &game);
	mlx_hook(game.mlx_win, 17, 0L, ft_close, &game);
	mlx_key_hook(game.mlx_win, ft_move, &game);
	mlx_loop(game.mlx);
	return (0);
}
