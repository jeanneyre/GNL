/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crondeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:49:35 by crondeau          #+#    #+#             */
/*   Updated: 2021/06/18 13:46:31 by crondeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 42

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stddef.h>

int		get_next_line(int fd, char **line);
int		ft_strlen(const char *str);
char	*ft_strdup(char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		return_n(char *str);
char	*get_line(char *str);

#endif
