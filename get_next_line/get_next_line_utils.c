/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:54:04 by hcherpre          #+#    #+#             */
/*   Updated: 2021/12/08 18:10:26 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char	*s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*strchr_str(char *str, int c)
{
	int				i;

	i = 0;
	if (!str)
		return (NULL);
	if (c == '\0')
		return (&str[ft_strlen(str)]);
	while (str[i])
	{
		if (str[i] == (char) c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

char	*strjoin_buf(char *str, char *buf)
{
	char		*final_str;
	size_t		i;
	size_t		j;

	if (!str)
	{
		str = malloc(sizeof(char) * 1);
		str[0] = '\0';
	}
	if (!str || !buf)
		return (NULL);
	final_str = malloc(sizeof(char) * (ft_strlen(str)
				+ ft_strlen(buf) + 1));
	if (!final_str)
		return (NULL);
	i = -1;
	j = 0;
	if (str)
		while (str[++i])
			final_str[i] = str[i];
	while (buf[j])
		final_str[i++] = buf[j++];
	final_str[i] = '\0';
	free(str);
	return (final_str);
}
