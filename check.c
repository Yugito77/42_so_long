/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:53:43 by hcherpre          #+#    #+#             */
/*   Updated: 2022/02/08 14:12:15 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(t_game *game)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(game->tab[0]);
	while (game->tab[i + 1])
	{
		if (ft_strlen(game->tab[i]) != len)
			return (0);
		i++;
	}
	if ((ft_strlen(game->tab[i]) + 1) != len)
		return (0);
	return (1);
}

int	check_char(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->tab[i])
	{
		j = 0;
		while (game->tab[i][j])
		{
			if (game->tab[i][j] != '1' && game->tab[i][j] != 'P'
				&& game->tab[i][j] != 'C' &&
				game->tab[i][j] != 'E' && game->tab[i][j] != '0'
				&& game->tab[i][j] != '\n' &&
				game->tab[i][j] != '\0')
				return (0);
			j++;
		}
		i++;
	}	
	return (1);
}

int	check_nb_char(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->nb_player = 0;
	game->nb_items = 0;
	game->nb_exit = 0;
	while (game->tab[i])
	{
		j = 0;
		while (game->tab[i][j])
		{
			if (game->tab[i][j] == 'P')
				game->nb_player += 1;
			else if (game->tab[i][j] == 'C')
				game->nb_items += 1;
			else if (game->tab[i][j] == 'E')
				game->nb_exit += 1;
			j++;
		}
		i++;
	}
	if (game->nb_player != 1 || game->nb_items == 0 || game->nb_exit == 0)
		return (0);
	return (1);
}

int	check_wall(t_game *game)
{
	int	j;

	j = 0;
	while (game->tab[0][j])
	{
		if (game->tab[0][j] != '1' && game->tab[0][j] != '\n')
			return (0);
		j++;
	}
	j = 0;
	while (game->tab[game->lignes - 1][j])
	{
		if (game->tab[game->lignes - 1][j] != '1' &&
			game->tab[game->lignes - 1][j] != '\n')
			return (0);
		j++;
	}
	j = 0;
	while (game->tab[j])
	{
		if (game->tab[j][0] != '1' || game->tab[j][game->colonnes - 2] != '1')
			return (0);
		j++;
	}
	return (1);
}
