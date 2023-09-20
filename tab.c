/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:58:26 by hcherpre          #+#    #+#             */
/*   Updated: 2022/02/14 10:45:40 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	gnl(t_game *game, char *file)
{
	char	*str;
	int		fd;

	game->lignes = 0;
	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	if (fd < 0 || !str)
	{
		free (game->mlx);
		exit (1);
	}
	game->colonnes = ft_strlen(str);
	while (str)
	{	
		free(str);
		game->lignes += 1;
		str = get_next_line(fd);
	}
	free(str);
	close(fd);
}

char	**create_tab(t_game *game, char *file)
{
	int		i;
	int		fd;
	char	**tab;
	char	*str;

	i = 0;
	gnl(game, file);
	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	tab = malloc(sizeof(char *) * (game->lignes + 1));
	if (!tab)
		return (NULL);
	while (str)
	{
		tab[i++] = str;
		str = get_next_line(fd);
	}
	tab[i] = NULL;
	free(str);
	close(fd);
	game->win_width = game->colonnes * 50 - 50;
	game->win_height = game->lignes * 50;
	return (tab);
}

int	check_file(char *file)
{
	if (ft_strlen(file) < 5)
	{
		printf("Error\nFile incorrect\n");
		return (0);
	}
	if (file[ft_strlen(file) - 1] != 'r' || file[ft_strlen(file) - 2] != 'e'
		|| file[ft_strlen(file) - 3] != 'b' || file[ft_strlen(file) - 4] != '.')
	{
		printf("Error\nFile incorrect\n");
		return (0);
	}	
	if (file[0] == '.')
	{
		printf("Error\nFile incorrect\n");
		return (0);
	}
	return (1);
}
