/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countRow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:05:38 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/01/12 14:36:43 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_row(int fd)
{
	int		i;
	char	*str;

	i = 0;
	str = get_next_line(fd);
	while (str != NULL)
	{
		i++;
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	return (i);
}
