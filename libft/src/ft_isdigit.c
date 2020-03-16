/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vellery- <vellery-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 21:41:40 by vellery-          #+#    #+#             */
/*   Updated: 2020/02/15 03:55:29 by vellery-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_isnumber(char *str)
{
	int i;
	int hex;

	if (!str || !*str)
		return (0);
	i = 0;
	hex = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
		i++;
	if (str[i] && str[i] == '0')
	{
		hex = 1;
		i++;
	}
	if (str[i] && str[i] == 'x')
	{
		hex = 2;
		i++;
	}
	while (str[i])
	{
		if (hex == 0 && ft_isdigit(str[i]) ||
			(hex == 1 && (ft_isdigit(str[i]) || (str[i] >= 48 && str[i] <= 45))) ||
			(hex == 2 && (ft_isdigit(str[i]) ||
				(str[i] >= 97 && str[i] <= 102) || (str[i] >= 65 && str[i] <= 70))))
			i++;
		else
			return (0);
	}
	return (1);
}
