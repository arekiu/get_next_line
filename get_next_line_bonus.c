/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:12:20 by aschmidt          #+#    #+#             */
/*   Updated: 2024/05/21 11:28:10 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*_check_left_over(char *left_over, int fd);
static char	*_set_line(int fd, char *buff, char *temp_line);
static char	*_set_left_over(char *line);
static char	*_clean_line(char *line);
/*
int main() {
    int fd, fd1, fd2;
    char *line, *line1, *line2;

    fd = open("example.txt", O_RDONLY);
    fd1 = open("example1.txt", O_RDONLY);
    fd2 = open("example2.txt", O_RDONLY);

    int more_lines = 1;
    while (more_lines) {
        more_lines = 0;

        line = get_next_line(fd);
        line1 = get_next_line(fd1);
        line2 = get_next_line(fd2);

        if (line != NULL) {
            printf("%s$\n", line);
            free(line);
            more_lines = 1;
        }
        if (line1 != NULL) {
            printf("%s$\n", line1);
            free(line1);
            more_lines = 1;
        }
        if (line2 != NULL) {
            printf("%s$\n", line2);
            free(line2);
            more_lines = 1;
        }
    }

    close(fd);
    close(fd1);
    close(fd2);
    return 0;
}*/

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_over[FOPEN_MAX];

	if (fd < 0 || fd >= FOPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	line = _check_left_over(left_over[fd], fd);
	if (!line)
	{
		free (left_over[fd]);
		left_over[fd] = NULL;
		return (NULL);
	}
	left_over[fd] = _set_left_over(line);
	line = _clean_line(line);
	if (!line)
	{
		free (left_over[fd]);
		left_over[fd] = NULL;
		return (NULL);
	}
	return (line);
}

static char	*_check_left_over(char *left_over, int fd)
{
	char	*buff;
	char	*combined_line;

	if (left_over != NULL && ft_strchr_bonus(left_over, '\n'))
		return (left_over);
	else
	{
		buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return (NULL);
		combined_line = _set_line(fd, buff, left_over);
		free (buff);
		buff = NULL;
		if (!combined_line)
			return (NULL);
	}
	return (combined_line);
}

static char	*_set_line(int fd, char *buff, char *temp_line)
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
		if (!temp_line)
			temp_line = ft_strdup_bonus("");
		if (!temp_line)
			return (NULL);
		temp = temp_line;
		temp_line = ft_strjoin_bonus(temp, buff);
		free (temp);
		temp = NULL;
		if (ft_strchr_bonus(buff, '\n'))
			break ;
	}
	return (temp_line);
}

static char	*_set_left_over(char *line)
{
	int		i;
	char	*left_over;

	i = 0;
	if (ft_strchr_bonus(line, '\n'))
	{
		while (line[i] != '\n' && line[i] != '\0')
			i++;
		if (line[i] == '\n')
			i++;
		if (line[i] == '\0')
			return (NULL);
		left_over = ft_substr_bonus(line, i, ft_strlen_b(line));
		if (!left_over)
			return (NULL);
		return (left_over);
	}
	else
		return (NULL);
}

static char	*_clean_line(char *line)
{
	char	*temp;
	int		i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\n')
		i++;
	temp = line;
	line = ft_substr_bonus(temp, 0, i);
	free (temp);
	temp = NULL;
	if (!line)
		return (NULL);
	return (line);
}
