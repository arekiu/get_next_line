/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:09:35 by aschmidt          #+#    #+#             */
/*   Updated: 2024/05/21 11:04:38 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_strjoin_bonus(char const *s1, char const *s2);
char	*ft_strchr_bonus(const char *str, int c);
size_t	ft_strlen_b(const char *str);
char	*ft_strdup_bonus(const char *s1);
char	*ft_substr_bonus(char const *str, unsigned int start, size_t len);

#endif
