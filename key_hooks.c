/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 20:38:39 by thelmy            #+#    #+#             */
/*   Updated: 2024/07/21 23:36:00 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	w_key_hook(t_game **game)
{
	if ((*game)->map[(*game)->x - 1][(*game)-> y] == 'C')
		(*game)->apple--;
	if (((*game)->map[(*game)->x - 1][(*game)-> y] == 'E' && (*game)->apple == 0) || ((*game)->map[(*game)->x - 1][(*game)-> y] == 'N'))
	{
		mlx_destroy_window((*game)->mlx, (*game)->win);
		delete_images(game, NULL, 4);
		free_arr((*game)->map);
		if ((*game)->map[(*game)->x - 1][(*game)-> y] == 'N')
		{
			write(1, "Game over\n", 10);
			exit(0);
		}
		write(1, "Congrats u did it", 17);
		exit(0);
	}
	else if ((*game)->map[(*game)->x - 1][(*game)-> y] != 'E')
	{
		(*game)->map[(*game)->x][(*game)->y] = '0';
		(*game)->map[(*game)->x - 1][(*game)->y] = 'P';
		(*game)->x--;
		bt_drawer((*game), (*game)->win);
		(*game)->moves++;
		printf("moves: %d\n", (*game)->moves);
	}
}

void	s_key_hook(t_game **game)
{
	if ((*game)->map[(*game)->x + 1][(*game)-> y] == 'C')
		(*game)->apple--;
	if (((*game)->map[(*game)->x + 1][(*game)-> y] == 'E' && (*game)->apple == 0) || (*game)->map[(*game)->x + 1][(*game)-> y] == 'N')
	{
		mlx_destroy_window((*game)->mlx, (*game)->win);
		delete_images(game, NULL, 4);
		free_arr((*game)->map);
		if((*game)->map[(*game)->x + 1][(*game)-> y] == 'N')
		{
			write(1, "Game over\n", 10);
			exit(0);
		}
		write(1, "Congrats u did it", 17);
		exit(0);
	}
	else if ((*game)->map[(*game)->x + 1][(*game)-> y] != 'E')
	{
		(*game)->map[(*game)->x][(*game)->y] = '0';
		(*game)->map[(*game)->x + 1][(*game)->y] = 'P';
		(*game)->x++;
		bt_drawer((*game), (*game)->win);
		(*game)->moves++;
		printf("moves: %d\n", (*game)->moves);
	}
}

void	d_key_hook(t_game **game)
{
	if ((*game)->map[(*game)->x][(*game)-> y + 1] == 'C')
		(*game)->apple--;
	if (((*game)->map[(*game)->x][(*game)-> y + 1] == 'E' && (*game)->apple == 0) || (*game)->map[(*game)->x][(*game)-> y + 1] == 'N')
	{
		mlx_destroy_window((*game)->mlx, (*game)->win);
		delete_images(game, NULL, 4);
		free_arr((*game)->map);
		if ((*game)->map[(*game)->x][(*game)-> y + 1] == 'N')
		{
			write(1, "Game over\n", 10);
			exit(0);
		}
		write(1, "Congrats u did it", 17);
		exit(0);
	}
	else if ((*game)->map[(*game)->x][(*game)-> y + 1] != 'E')
	{
		(*game)->map[(*game)->x][(*game)->y] = '0';
		(*game)->map[(*game)->x][(*game)->y + 1] = 'P';
		(*game)->y++;
		bt_drawer((*game), (*game)->win);
		(*game)->moves++;
		printf("moves: %d\n", (*game)->moves);
	}
}

void	a_key_hook(t_game **game)
{
	if ((*game)->map[(*game)->x][(*game)-> y - 1] == 'C')
		(*game)->apple--;
	if (((*game)->map[(*game)->x][(*game)-> y - 1] == 'E' && (*game)->apple == 0) || (*game)->map[(*game)->x][(*game)-> y - 1] == 'N')
	{
		mlx_destroy_window((*game)->mlx, (*game)->win);
		delete_images(game, NULL, 4);
		free_arr((*game)->map);
		if ((*game)->map[(*game)->x][(*game)-> y - 1] == 'N')
		{
			write(1, "Game over\n", 10);
			exit(0);
		}
		write(1, "Congrats u did it", 17);
		exit(0);
	}
	else if ((*game)->map[(*game)->x][(*game)-> y - 1] != 'E')
	{
		(*game)->map[(*game)->x][(*game)->y] = '0';
		(*game)->map[(*game)->x][(*game)->y - 1] = 'P';
		(*game)->y--;
		bt_drawer((*game), (*game)->win);
		(*game)->moves++;
		printf("moves: %d\n", (*game)->moves);
	}
}

void	empty_map(char *str, char *s, int fd)
{
	if (!str || str[0] == '\n')
	{
		write(2, "empty map\n", 10);
		if (str)
			free(str);
		if (s)
			free(s);
		close(fd);
		exit(1);
	}
}
