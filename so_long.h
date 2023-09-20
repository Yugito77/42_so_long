/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:58:29 by hcherpre          #+#    #+#             */
/*   Updated: 2022/02/08 18:52:29 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <stdio.h> 
# include <stdlib.h>
# include <fcntl.h>

/*************************** DEFINE *******************/

# define GROUND			"./assets/ground.xpm"
# define WALL			"./assets/wall.xpm"
# define ITEMS			"./assets/items.xpm"
# define PORTAL			"./assets/portal.xpm"
# define PLAYER_FRONT	"./assets/player_front.xpm"
# define PLAYER_BACK	"./assets/player_back.xpm"
# define PLAYER_RIGHT	"./assets/player_right.xpm"
# define PLAYER_LEFT	"./assets/player_left.xpm"

/************************** STRUCTURE ****************/

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	void	*img_player;
	void	*img_wall;
	void	*img_items;
	void	*img_ground;
	void	*img_exit;
	int		lignes;
	int		colonnes;
	int		x;
	int		y;
	int		i;
	int		j;
	int		items_collected;
	int		items;
	int		nb_player;
	int		nb_exit;
	int		nb_items;
	int		win_width;
	int		win_height;
	int		img_width;
	int		img_height;
	int		pos_x;
	int		pos_y;
	char	**tab;
}				t_game;

/****************************** MAP CREATION ******************/

void	gnl(t_game *game, char *file);
char	**create_tab(t_game *game, char *file);
void	create_map_wall(t_game *game);
void	create_map_ground(t_game *game);
void	create_map_items(t_game *game);
void	create_map_exit(t_game *game);
void	create_map_player(t_game *game);
void	create_img(t_game *game, char *player);

/******************************* HOOKS ************************/

int		ft_close(t_game *game);
int		ft_close_esc(int keycode, t_game *game);
void	ft_exit(t_game *game);

/******************************* MOVES ************************/

int		ft_move(int keycode, t_game *game);
int		ft_move_up(t_game *game);
int		ft_move_up_2(t_game *game);
int		ft_move_down(t_game *game);
int		ft_move_down_2(t_game *game);
int		ft_move_right(t_game *game);
int		ft_move_right_2(t_game *game);
int		ft_move_left(t_game *game);
int		ft_move_left_2(t_game *game);

/******************************* CHECK ***********************/

int		check_map(t_game *game);
int		check_char(t_game *game);
int		check_nb_char(t_game *game);
int		check_wall(t_game *game);
int		check_file(char *file);

/******************************* FREE ***********************/

void	ft_free(t_game *game);
void	destroy_img(t_game *game);

#endif