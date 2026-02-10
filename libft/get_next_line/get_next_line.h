/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hammeah <hammeah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 19:41:13 by hammeah           #+#    #+#             */
/*   Updated: 2026/01/20 22:22:16 by hammeah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}					t_list;

char				*get_next_line(int fd);

int					ft_checking_backslast(t_list *list);

t_list				*ft_lstlast(t_list *list);

int					ft_len_line(t_list *list);

void				ft_free_list(t_list *list);

int					ft_strlen2(char *str);

void				ft_create_str(int fd, t_list **list);

void				ft_add_to_list(char *buffer, t_list **list, int byte_read);

void				ft_return_line(t_list *list, char **ret);

void				ft_next_ret(t_list **list);

#endif