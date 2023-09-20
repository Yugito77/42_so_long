/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:12:38 by hcherpre          #+#    #+#             */
/*   Updated: 2021/12/09 10:44:30 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*back_line(char *str);
char	*new_line(char *str);
char	*read_bytes(int fd, char *str);
size_t	ft_strlen(char	*s);
char	*strchr_str(char *str, int c);
char	*strjoin_buf(char *str, char *buf);

#endif