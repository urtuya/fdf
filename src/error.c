/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <oargrave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 16:12:39 by oargrave          #+#    #+#             */
/*   Updated: 2019/10/27 16:12:59 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void		print_error(char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
	exit(1);
}

void		check_malloc(void *data)
{
	if (!data)
		print_error("malloc error");
}
