/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurivieiradossantos <yurivieiradossanto    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 22:40:29 by yurivieirad       #+#    #+#             */
/*   Updated: 2024/12/11 22:40:30 by yurivieirad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

typedef struct s_string
{
	char			character;
	struct s_string	*next;
}	t_string;

typedef struct s_buffer
{
	int				fd;
	int				position;
	int				total_read;
	int				length;
	char			buffer[BUFFER_SIZE];
	t_string		*string;
	struct s_buffer	*next;
}	t_buffer;

char		*get_next_line(int fd);
t_buffer	*init_clean_buffer(int fd);
void		clear_string(t_string *str);
void		build_string(t_string **string_head, char character);
char		*alloc_line(t_buffer *buffer);
char		*get_current_line(t_buffer *buffer);
t_buffer	*get_buffer(t_buffer **head, int fd);
void		remove_buffer(t_buffer **head, int fd);

#endif