/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crondeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:38:39 by crondeau          #+#    #+#             */
/*   Updated: 2021/06/30 09:30:44 by crondeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*get_line(char *str) // j'obtiens ma ligne avant '\n'
{
	int		i;
	char	*char_return;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	char_return = malloc(sizeof(char) * (i + 1));
	if (!char_return)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		char_return[i] = str[i];
		i++;
	}
	char_return[i] = 0;
	return (char_return);
}

void	init(int *i, int *j)
{
	*i = 0;
	*j = 0;
}

char	*record_line(char *rec_str) // j'enregistre la ligne suivante
{
	int		i;
	int		j;
	char	*char_return;

	init(&i, &j);
	while (!rec_str)
		return (0);
	while (rec_str[i] && rec_str[i] != '\n')
		i++;
	char_return = malloc(sizeof(char) * (ft_strlen(rec_str) - i)); // on malloc notre chaine de caractere - i (i = ce qu'il y a avant '\n') 
	if (!char_return)
		return (0);
	if (rec_str[i])
		i++;
	while (rec_str[i])
	{
		char_return[j] = rec_str[i];
		i++;
		j++;
	}
	char_return[j] = '\0';
	free (rec_str);
	return (char_return);
}

void	send_line(char **str, char **line)
{
	*line = get_line(*str);
	*str = record_line(*str);
}

int	get_next_line(int fd, char **line)
// **line > pointeur sur la string qui doit contenir la ligne
// gnl renvoit un int et non la str, elle doit prendre un pointeur sur la str pour bien modifier la str et non une copie de celle-ci, comme un pointeur sur int en parametre pour modifier cet int en dehors de la fonction line doit contenir la ligne suivante a chaque appel, jusqu'a la fin du fichier

{
	static char	*str;
// variable static qui se souvient de ce qu'il reste du dernier appel de read (pointeur vers un pointeur)
// servira a garder si besoin ce qu'il y a apres le premier \n de buffer qui a read de BUFFER_SIZE
	char		buffer[BUFFER_SIZE + 1]; // buffer de destination
	int			temp; // tampon a ajouter a la ligne de resultat

	temp = 1; // c'est qu'il renvoit qqchose
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, buffer, 0) == -1)
		return (-1);
	while (!return_n(str) && temp != 0)
	{
		temp = read(fd, buffer, BUFFER_SIZE);
		if (temp == -1)
			return (-1);
		buffer[temp] = '\0';
		str = ft_strjoin(str, buffer);
	}
	send_line(&str, line);
	if (temp == 0) // c'est qu'il est a la fin du texte
	{
		if (str)
			free(str);
		str = NULL;
		return (0);
	}
	return (1);
}
