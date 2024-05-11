/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 12:11:59 by aschmidt          #+#    #+#             */
/*   Updated: 2024/05/11 12:28:03 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
char	*get_next_line(int fd);

int	main(void)
{
	int	fd;
	int	i = 0;
	char	buf[50];
	ssize_t nr_bytes;

	fd = open("example.txt", O_RDONLY);

	if(fd == -1)
	{
		printf("Error opening the file \n");
	}
	else
	{
		nr_bytes = read(fd, buf, 50);
		close(fd);
		if (nr_bytes == 0)
		{
			printf("empty file \n");
		}
		else
		{
			printf("Number of char: %d, content: ", (int)nr_bytes);
            while (buf[i] != '\0')
            {
                if (buf[i] == '\n')
                {
                    printf("\\n");
                }
                else
                {
                    printf("%c", buf[i]);
                }
				i++;
			}
		}
	}
	return (0);
}
