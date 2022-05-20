/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngobert <ngobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:26:10 by ngobert           #+#    #+#             */
/*   Updated: 2022/05/19 17:05:15 by ngobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brainfuck.h"

void	do_bf(char *str)
{
	int	bf[2048] = {0};
	int	bfptr = 0;
	int	i = 0;
	int	loop = 0;

	while (str[i])
	{
		if (str[i] == '>')
			bfptr++;
		else if (str[i] == '<')
			bfptr--;
		else if (str[i] == '+')
			bf[bfptr]++;
		else if (str[i] == '-')
			bf[bfptr]--;
		else if (str[i] == '.')
			ft_putchar(bf[bfptr]);
		else if (str[i] == '[' && bf[bfptr] == 0)
		{
			loop = 1;
			while (loop != 0)
			{
				i++;
				if (str[i] == ']')
					--loop;
				if (str[i] == '[')
					++loop;
			}
		}
		else if (str[i] == ']' && bf[bfptr] != 0)
		{
			loop = 1;
			while (loop != 0)
			{
				i--;
				if (str[i] == '[')
					--loop;
				if (str[i] == ']')
					++loop;
			}
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2 && ft_strlen(argv[1]) <= 4096)
		do_bf(argv[1]);
}

