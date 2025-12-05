/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiida <tiida@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 22:53:29 by tiida             #+#    #+#             */
/*   Updated: 2025/12/05 22:03:28 by tiida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

//IMPROVEMENT

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/*
// ft_swap() does not work cuz s1 and s2 are local copies of the pointers passed in. -> chaging them does not modify argv[].
void	ft_swap(char *s1, char *s2)
{
	char	*temp;

	temp = s1;
	s1 = s2;
	s2 = temp;
}
*/

void	ft_print_argv(int argc, char *argv[])
{
	int	x;
	int	y;

	y = 1;
	while (y < argc)
	{
		x = 0;
		while (argv[y][x] != '\0')
		{
			ft_putchar(argv[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}

/*
int	main(int argc, char *argv[])
{
	int	x;
	int	y;

	y = 1;
	while (argc > 1 && y < argc)
	{
		x = 0;
// you stop the comparison when you reach the end of the characters of argument 1.
// sorting should not depend on characters!
		while (argv[y][x] != '\0')
		{
			ft_strcmp(argv[x], argv[x + 1]);
			if (ft_strcmp(argv[x], argv[x + 1]) > 0)
				ft_swap(argv[x], argv[x + 1]);
			x++;
		}
		y++;
	}
	ft_print_argv(argc, argv);
	return (0);
}
*/

// REFERENCE: C01 ex08 "ft_sort_int_tab"
int	main(int argc, char *argv[])
{
	int	x;
	int	y;
	char	*temp;

	x = 1;
	while (x < argc - 1)
	{
		y = 1;
		while (y < argc - 1)
		{
			if (ft_strcmp(argv[y], argv[y + 1]) > 0)
			{
				temp = argv[y];
				argv[y] = argv[y + 1];
				argv[y + 1] = temp;
			}
			y++;
		}
		x++;
	}
// until here, just think about comparing and swaping arguments.
// basically it must be the same way as ft_sort_int_tab.
	ft_print_argv(argc, argv);
	return (0);
}
