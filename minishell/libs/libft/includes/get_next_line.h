/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martiper <martiper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 21:21:32 by mm                #+#    #+#             */
/*   Updated: 2023/05/04 22:53:41 by martiper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_get_next_line_data
{
	bool	defined;
	int		fd;
	char	*buffer;
}			t_get_next_line_data;

char		*get_next_line(int fd);
char		*ft_strjoin_free(char *s1, char *s2);

#endif
