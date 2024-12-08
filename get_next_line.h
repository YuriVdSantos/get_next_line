/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_netx_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvieira- <yvieira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:58:51 by yvieira-          #+#    #+#             */
/*   Updated: 2024/12/08 18:13:47 by yvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42

#	include <unistd.h>
#	include <stdlib.h>
#	include <fcntl.h>
#	include <stdio.h>

int get_next_line(int fd);


	
#endif