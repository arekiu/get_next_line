/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 12:11:59 by aschmidt          #+#    #+#             */
/*   Updated: 2024/05/16 10:09:51 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*_set_line(int fd, char *buff, char *left_over);
static char	*_clean_line(char *temp_line);
static char	*_set_left_over(char *line, char *left_over);

/*
int	main(void)
{
	int	fd;

	fd = open("read_error.txt", O_RDONLY);
	printf("la linea: %s$\n", get_next_line(fd));
	printf("la linea2: %s$", get_next_line(fd));
	printf("la linea3: %s$\n", get_next_line(fd));
	printf("la linea4: %s$", get_next_line(fd));
	printf("la linea5: %s$", get_next_line(fd));
	//printf("%s", get_next_line(fd));

	close(fd);
	return (0);
}*/

char	*get_next_line(int fd)
{
	char		*buff;
	char		*line;
	static char	*left_over;

	if (fd == -1 || BUFFER_SIZE < -1)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	line = _set_line(fd, buff, left_over);
	free (buff);
	buff = NULL;
	if (!line)
	{
		free (left_over);
		left_over = NULL;
		return (NULL);
	}
	left_over = _set_left_over(line, left_over);
	line = _clean_line(line);
	return (line);
}

static char	*_set_line(int fd, char *buff, char *left_over)
{
	ssize_t	nr_bytes;
	char	*temp;

	nr_bytes = 1;
	while (nr_bytes > 0)
	{
		nr_bytes = read(fd, buff, BUFFER_SIZE);
		if (nr_bytes == -1)
			return (NULL);
		if (nr_bytes == 0)
			break ;
		buff[nr_bytes] = '\0';
		if (!left_over)
			left_over = ft_strdup("");
		temp = left_over;
		left_over = ft_strjoin(temp, buff);
		free (temp);
		temp = NULL;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (left_over);
}

static char	*_set_left_over(char *line, char *left_over)
{
	int		i;

	i = 0;
	if (ft_strchr(line, '\n'))
	{
		while (line[i] != '\n')
			i++;
		left_over = ft_substr(line, (i + 1), ft_strlen(line));
		if (*left_over == '\0')
		{
			free (left_over);
			left_over = NULL;
			return (NULL);
		}
		return (left_over);
	}
	else
		return (NULL);
}

static char	*_clean_line(char *temp_line)
{
	int		i;
	char	*temp;

	i = 0;
	if (temp_line[i] == '\0')
		return (NULL);
	while (temp_line[i] != '\0' && temp_line[i] != '\n')
		i++;
	if (temp_line[i] == '\n')
		i++;
	temp = temp_line;
	temp_line = ft_substr(temp, 0, i);
	free (temp);
	temp = NULL;
	return (temp_line);
}
