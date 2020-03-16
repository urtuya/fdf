#include "libft.h"
#include "stdint.h"

void	get_hex(char *str, int *i)
{
	if (str[*i] == '0')
		*i ++;
	if (str[*i] == 'x')
		*i ++;
	else if (str[*i] == 'b')
		*i ++;
}

intmax_t	ft_atointmax(char *str, int base)
{
	intmax_t ret;
	int	len;
	int	digit;
	int i;
	int	sign;

	sign = 1;
	ret = 0;
	len = ft_strlen(str) - 1;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		sign = str[i] == '-' ? -1 : sign;
		i++;
	}
	get_hex(str, &i);
	while (str[i])
	{
		digit = str[len] + '0';
		printf("digit = %d\n", digit);
		exit(0);
		// if (str[i])
	}
}