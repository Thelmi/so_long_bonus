/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:12:16 by thelmy            #+#    #+#             */
/*   Updated: 2024/07/22 00:07:11 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



void printer(t_game str)
{
	int i = 0;
	while (str.map[i])
		printf("%s\n", str.map[i++]);
}
void b_painter(t_game **game, void *win, int *i, int *j)
{
	char **map;
	int x;
	int y;

	map = (*game)->map;
	x = *j * 128;
	y = *i * 128;
	if (map[*i][*j] == 'C')
		(*game)->z = mlx_put_image_to_window((*game)->mlx, win,
											 (*game)->graphics[0].img, x, y);
	else if (map[*i][*j] == 'E')
		(*game)->z = mlx_put_image_to_window((*game)->mlx, win,
											 (*game)->graphics[1].img, x, y);
	else if (map[*i][*j] == '0')
		(*game)->z = mlx_put_image_to_window((*game)->mlx, win,
											 (*game)->graphics[2].img, x, y);
	else if (map[*i][*j] == 'P')
		(*game)->z = mlx_put_image_to_window((*game)->mlx, win,
											 (*game)->graphics[3].img, x, y);
	else if (map[*i][*j] == '1')
		(*game)->z = mlx_put_image_to_window((*game)->mlx, win,
											 (*game)->graphics[4].img, x, y);
	else if (map[*i][*j] == 'N' && (*game)->direction == 1)
		(*game)->z = mlx_put_image_to_window((*game)->mlx, win,
											 (*game)->graphics[5].img, x, y);
	else if (map[*i][*j] == 'N' && (*game)->direction == 2)
		(*game)->z = mlx_put_image_to_window((*game)->mlx, win,
											 (*game)->graphics[6].img, x, y);
	else if (map[*i][*j] == 'N' && (*game)->direction == 3)
		(*game)->z = mlx_put_image_to_window((*game)->mlx, win,
											 (*game)->graphics[7].img, x, y);
	else if (map[*i][*j] == 'N' && (*game)->direction == 0)
		(*game)->z = mlx_put_image_to_window((*game)->mlx, win,
											 (*game)->graphics[8].img, x, y);
	if (!(*game)->z)
		no_crash(game, NULL, 5);
}

void bt_drawer(t_game *game, void *win)
{
	char **map;
	int i;
	int j;

	i = 0;
	j = 0;
	map = game->map;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			b_painter(&game, win, &i, &j);
			j++;
		}
		i++;
	}
}
void b_storing_images(t_game *images)
{
	int i;
	char *image_paths[9];

	image_paths[0] = "./images/apple.xpm";
	image_paths[1] = "./images/exit.xpm";
	image_paths[2] = "./images/floor.xpm";
	image_paths[3] = "./images/player.xpm";
	image_paths[4] = "./images/wall.xpm";
	image_paths[5] = "./images/roachleft.xpm";
	image_paths[6] = "./images/roachdown.xpm";
	image_paths[7] = "./images/roachright.xpm";
	image_paths[8] = "./images/roachup.xpm";

	i = 0;
	while (i < 9)
	{
		images->graphics[i].img = mlx_xpm_file_to_image(images->mlx, image_paths[i],
														&(images->graphics[i].img_width),
														&(images->graphics[i].img_height));
		if (!images->graphics[i].img)
			no_crash(NULL, images, i);
		i++;
	}
}

void catch_him_if_you_can(t_game *map)
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	// printer(map->map);
	map->enemy_x[0] = 0;
	map->enemy_y[0] = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'N')
			{
				map->enemy_x[count] = i;
				map->enemy_y[count] = j;
				count++;
			}
			j++;
		}
		i++;
	}
	map->enemy_x[count] = -1;
	map->enemy_y[count] = -1;
}


#include <time.h>
//int enemy(t_game *game)
//{
//    static int count = 0;
	
//    count++;
//    if (count < 5000) 
//        return 0;         
//    count = 0;
//	static int flag = 0;
//    //static time_t saved_time = 0; 

//    //time_t current_time = time(NULL);
//    //if (saved_time && (current_time - saved_time) < 1)
//    //{
//    //    return 0;
//    //}
//    //saved_time = current_time;
//	//usleep(1000000);
//    if (flag == 0 && (game->map[game->enemy_x][game->enemy_y - 1] == '0' || game->map[game->enemy_x][game->enemy_y - 1] == 'P'))
//    {
		
//		if (game->map[game->enemy_x][game->enemy_y - 1] == 'P')
//		{
//			write(1, "Game over\n", 10);
//			exit(0);
//		}
//			game->map[game->enemy_x][game->enemy_y] = '0';
//			game->map[game->enemy_x][game->enemy_y - 1] = 'N';
//			game->enemy_y--;
//			bt_drawer(game, game->win);
//			if (flag == 0 && (game->map[game->enemy_x][game->enemy_y - 1] != '0')) 
//				flag = 1;
//    }
//    else if (flag == 1 && (game->map[game->enemy_x + 1][game->enemy_y] == '0' || game->map[game->enemy_x + 1][game->enemy_y] == 'P'))
//    {
//		if (game->map[game->enemy_x + 1][game->enemy_y] == 'P')
//		{
//			write(1, "Game over\n", 10);
//			exit(0);
//		}
//        game->map[game->enemy_x][game->enemy_y] = '0';
//        game->map[game->enemy_x + 1][game->enemy_y] = 'N';
//        game->enemy_x++;
//        bt_drawer(game, game->win);
//		if (flag == 1 && (game->map[game->enemy_x + 1][game->enemy_y] != '0'))
//		flag = 0;
//    }
//    else if (flag == 0 && (game->map[game->enemy_x][game->enemy_y + 1] == '0' || game->map[game->enemy_x][game->enemy_y + 1] == 'P'))
//    {
//        if (game->map[game->enemy_x][game->enemy_y + 1] == 'P')
//		{
//			write(1, "Game over\n", 10);
//			exit(0);
//		}
//        game->map[game->enemy_x][game->enemy_y] = '0';
//        game->map[game->enemy_x][game->enemy_y + 1] = 'N';
//        game->enemy_y++;
//        bt_drawer(game, game->win);
//		if (flag == 0 && (game->map[game->enemy_x][game->enemy_y + 1] != '0'))
//			flag = 1;
//    }
//    else if (flag == 1 && (game->map[game->enemy_x - 1][game->enemy_y] == '0' || game->map[game->enemy_x - 1][game->enemy_y] == 'P'))
//    {
//		if (game->map[game->enemy_x - 1][game->enemy_y] == 'P')
//		{
//			write(1, "Game over\n", 10);
//			exit(0);
//		}
//        game->map[game->enemy_x][game->enemy_y] = '0';
//        game->map[game->enemy_x - 1][game->enemy_y] = 'N';
//        game->enemy_x--;
//        bt_drawer(game, game->win);
//		if (flag == 1 && (game->map[game->enemy_x - 1][game->enemy_y] != '0'))
//		flag = 0;
//    }
//	else if (flag == 1 && (game->map[game->enemy_x][game->enemy_y - 1] == '0' || game->map[game->enemy_x][game->enemy_y - 1] == 'P'))
//    {
		
//		if (game->map[game->enemy_x][game->enemy_y - 1] == 'P')
//		{
//			write(1, "Game over\n", 10);
//			exit(0);
//		}
//			game->map[game->enemy_x][game->enemy_y] = '0';
//			game->map[game->enemy_x][game->enemy_y - 1] = 'N';
//			game->enemy_y--;
//			bt_drawer(game, game->win);
//			if (flag == 1 && (game->map[game->enemy_x][game->enemy_y - 1] != '0')) 
//				flag = 0;
//    }
//	else if (flag == 0 && (game->map[game->enemy_x + 1][game->enemy_y] == '0' || game->map[game->enemy_x + 1][game->enemy_y] == 'P'))
//   	 {
//		if (game->map[game->enemy_x + 1][game->enemy_y] == 'P')
//		{
//			write(1, "Game over\n", 10);
//			exit(0);
//		}
//        game->map[game->enemy_x][game->enemy_y] = '0';
//        game->map[game->enemy_x + 1][game->enemy_y] = 'N';
//        game->enemy_x++;
//        bt_drawer(game, game->win);
//		if (flag == 0 && (game->map[game->enemy_x + 1][game->enemy_y] != '0'))
//		flag = 1;
//     }
//	else if (flag == 1 && (game->map[game->enemy_x][game->enemy_y + 1] == '0' || game->map[game->enemy_x][game->enemy_y + 1] == 'P'))
//    	{
//        if (game->map[game->enemy_x][game->enemy_y + 1] == 'P')
//		{
//			write(1, "Game over\n", 10);
//			exit(0);
//		}
//        game->map[game->enemy_x][game->enemy_y] = '0';
//        game->map[game->enemy_x][game->enemy_y + 1] = 'N';
//        game->enemy_y++;
//        bt_drawer(game, game->win);
//		if (flag == 1 && (game->map[game->enemy_x][game->enemy_y + 1] != '0'))
//			flag = 0;
//    	}
//		else if (flag == 0 && (game->map[game->enemy_x - 1][game->enemy_y] == '0' || game->map[game->enemy_x - 1][game->enemy_y] == 'P'))
//    	{
//			if (game->map[game->enemy_x - 1][game->enemy_y] == 'P')
//			{
//				write(1, "Game over\n", 10);
//				exit(0);
//			}
//			game->map[game->enemy_x][game->enemy_y] = '0';
//			game->map[game->enemy_x - 1][game->enemy_y] = 'N';
//			game->enemy_x--;
//			bt_drawer(game, game->win);
//			if (flag == 0 && (game->map[game->enemy_x - 1][game->enemy_y] != '0'))
//			flag = 1;
//    	}
//	 mlx_string_put(game->mlx, game->win, 50, 50, 0xFFFFFFF, ft_itoa(game->moves));
//	 mlx_string_put(game->mlx, game->win, 7, 50, 0xFFFFFFF, "Moves:");
//    return 0;
	
//}
//int enemy(t_game *game)
//{
//    static int count = 0;
//    static int flag = 0;

//    count++;
//    if (count < 5000)
//        return 0;

//    count = 0;

//    int new_x = game->enemy_x;
//    int new_y = game->enemy_y;

//    if (flag == 0) {
//        if (game->map[new_x][new_y - 1] == '0' || game->map[new_x][new_y - 1] == 'P') {
//            new_y--;
//            if (game->map[new_x][new_y] != '0' && game->map[new_x][new_y] != 'P') flag = 1;
//        } else if (game->map[new_x + 1][new_y] == '0' || game->map[new_x + 1][new_y] == 'P') {
//            new_x++;
//            if (game->map[new_x][new_y] != '0' && game->map[new_x][new_y] != 'P') flag = 1;
//        }
//    } else {
//        if (game->map[new_x][new_y + 1] == '0' || game->map[new_x][new_y + 1] == 'P') {
//            new_y++;
//            if (game->map[new_x][new_y] != '0' && game->map[new_x][new_y] != 'P') flag = 0;
//        } else if (game->map[new_x - 1][new_y] == '0' || game->map[new_x - 1][new_y] == 'P') {
//            new_x--;
//            if (game->map[new_x][new_y] != '0' && game->map[new_x][new_y] != 'P') flag = 0;
//        }
//    }

//    if (game->map[new_x][new_y] == 'P') {
//        write(1, "Game over\n", 10);
//        exit(0);
//    }

//    game->map[game->enemy_x][game->enemy_y] = '0';
//    game->map[new_x][new_y] = 'N';
//    game->enemy_x = new_x;
//    game->enemy_y = new_y;

//    bt_drawer(game, game->win);

//    mlx_string_put(game->mlx, game->win, 50, 50, 0xFFFFFFF, ft_itoa(game->moves));
//    mlx_string_put(game->mlx, game->win, 7, 50, 0xFFFFFFF, "Moves:");

//    return 0;
//}


//t_game	*opposite_flags(t_game *game, int *flag, int *count)
//{
//	if (*count < 10000)
//        return game;
//	(*count)++;
//	if (game->map[game->enemy_x - 1][game->enemy_y] != '1' && game->map[game->enemy_x - 1][game->enemy_y] != 'E' && *flag == 1)
//	{
//		while (game->map[game->enemy_x - 1][game->enemy_y] != '1' && game->map[game->enemy_x - 1][game->enemy_y] != 'E')
//		{
//			game->map[game->enemy_x][game->enemy_y] = '0';
//			game->map[game->enemy_x - 1][game->enemy_y] = 'N';
//			game->enemy_x--;
//			bt_drawer(game, game->win);
//		}
//		*flag = 0;
//	}
//	else if (game->map[game->enemy_x][game->enemy_y - 1] != '1' && game->map[game->enemy_x][game->enemy_y - 1] != 'E' && *flag == 0)
//	{
//		while (game->map[game->enemy_x][game->enemy_y - 1] != '1' && game->map[game->enemy_x][game->enemy_y - 1] != 'E')
//		{
//			game->map[game->enemy_x][game->enemy_y] = '0';
//			game->map[game->enemy_x][game->enemy_y - 1] = 'N';
//			game->enemy_y--;
//			bt_drawer(game, game->win);
//		}
//		*flag = 1;
//	}
//	else if (game->map[game->enemy_x + 1][game->enemy_y] != '1' && game->map[game->enemy_x + 1][game->enemy_y] != 'E' && *flag == 1)
//	{
//		while (game->map[game->enemy_x + 1][game->enemy_y] != '1' && game->map[game->enemy_x + 1][game->enemy_y] != 'E')
//		{
//			game->map[game->enemy_x][game->enemy_y] = '0';
//			game->map[game->enemy_x + 1][game->enemy_y] = 'N';
//			game->enemy_x++;
//			bt_drawer(game, game->win);
//		}
//		*flag = 0;
//	}
//	else if (game->map[game->enemy_x][game->enemy_y + 1] != '1' && game->map[game->enemy_x][game->enemy_y + 1] != 'E' && *flag == 0)
//	{
//		while (game->map[game->enemy_x][game->enemy_y + 1] != '1' &&
//		game->map[game->enemy_x][game->enemy_y + 1] != 'E')
//		{
//			game->map[game->enemy_x][game->enemy_y] = '0';
//			game->map[game->enemy_x][game->enemy_y + 1] = 'N';
//			game->enemy_y++;
//			bt_drawer(game, game->win);
//		}
//		*flag = 1;
//	}
//	else 
//		exit(0);
//	return (game);
//}
//}
//t_game *opposite_flags(t_game *game, int *flag)
//{
//    if (*flag == 0) // Moving left
//    {
//        if (game->map[game->enemy_x][game->enemy_y - 1] != '1' && game->map[game->enemy_x][game->enemy_y - 1] != 'E')
//        {
//            game->map[game->enemy_x][game->enemy_y] = '0';
//            game->map[game->enemy_x][game->enemy_y - 1] = 'N';
//            game->enemy_y--;
//            bt_drawer(game, game->win);
//        }
//        else
//        {
//            *flag = 1; // Change direction to down
//        }
//    }
//    else if (*flag == 1) // Moving down
//    {
//        if (game->map[game->enemy_x + 1][game->enemy_y] != '1' && game->map[game->enemy_x + 1][game->enemy_y] != 'E')
//        {
//            game->map[game->enemy_x][game->enemy_y] = '0';
//            game->map[game->enemy_x + 1][game->enemy_y] = 'N';
//            game->enemy_x++;
//            bt_drawer(game, game->win);
//        }
//        else
//        {
//            *flag = 2; // Change direction to right
//        }
//    }
//    else if (*flag == 2) // Moving right
//    {
//        if (game->map[game->enemy_x][game->enemy_y + 1] != '1' && game->map[game->enemy_x][game->enemy_y + 1] != 'E')
//        {
//            game->map[game->enemy_x][game->enemy_y] = '0';
//            game->map[game->enemy_x][game->enemy_y + 1] = 'N';
//            game->enemy_y++;
//            bt_drawer(game, game->win);
//        }
//        else
//        {
//            *flag = 3; // Change direction to up
//        }
//    }
//    else if (*flag == 3) // Moving up
//    {
//        if (game->map[game->enemy_x - 1][game->enemy_y] != '1' && game->map[game->enemy_x - 1][game->enemy_y] != 'E')
//        {
//            game->map[game->enemy_x][game->enemy_y] = '0';
//            game->map[game->enemy_x - 1][game->enemy_y] = 'N';
//            game->enemy_x--;
//            bt_drawer(game, game->win);
//        }
//        else
//        {
//            *flag = 0; // Change direction to left
//        }
//    }
    
//    return game;
//}

//int enemy(t_game *game)
//{
//    static int flag = 0;
//    static int count = 0;
//    const int move_frequency = 10000; // Adjust this value for desired delay

//    // Increment count to control enemy's speed
//    count++;
//    if (count < move_frequency)
//    {
//        return 0;
//    }
//    count = 0;

//    game = opposite_flags(game, &flag);

//    return 0;
//}

//int main(int argc, char **argv) {
//    srand_custom(12345); // Set a custom seed if necessary
//    t_game game = game_engine(argc, argv);
//    return 0;
//}s
//int draw_text(t_game *game)
//{
//    int x = 50;
//    int y = 50;
//    int color = 0xFF0000F;

//    mlx_string_put(game->mlx, game->win, x, y, color, ft_itoa(game->moves));
//	return 0;
//}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#include <time.h>
//int enemy(t_game *game)
//{
//    static int count = 0;
	
//    count++;
//    if (count < 5000) 
//        return 0;         
//    count = 0;
//	static int flag = 0;
//    //static time_t saved_time = 0; 

//    //time_t current_time = time(NULL);
//    //if (saved_time && (current_time - saved_time) < 1)
//    //{
//    //    return 0;
//    //}
//    //saved_time = current_time;
//	//usleep(1000000);

//    if (flag == 0 && (game->map[game->enemy_x][game->enemy_y - 1] == '0' || game->map[game->enemy_x][game->enemy_y - 1] == 'P'))
//    {
		
//		if (game->map[game->enemy_x][game->enemy_y - 1] == 'P')
//		{
//			write(1, "Game over\n", 10);
//			exit(0);
//		}
//			game->map[game->enemy_x][game->enemy_y] = '0';
//			game->map[game->enemy_x][game->enemy_y - 1] = 'N';
//			game->enemy_y--;
//			bt_drawer(game, game->win);
//			if (flag == 0 && (game->map[game->enemy_x][game->enemy_y - 1] != '0')) 
//				flag = 1;
//    }
//    else if (flag <= 1 && (game->map[game->enemy_x + 1][game->enemy_y] == '0' || game->map[game->enemy_x + 1][game->enemy_y] == 'P'))
//    {
//		if (game->map[game->enemy_x + 1][game->enemy_y] == 'P')
//		{
//			write(1, "Game over\n", 10);
//			exit(0);
//		}
//        game->map[game->enemy_x][game->enemy_y] = '0';
//        game->map[game->enemy_x + 1][game->enemy_y] = 'N';
//        game->enemy_x++;
//        bt_drawer(game, game->win);
//		if (flag <= 1 && (game->map[game->enemy_x + 1][game->enemy_y] != '0'))
//		flag = 2;
//    }
//    else if (flag <= 2 && (game->map[game->enemy_x][game->enemy_y + 1] == '0' || game->map[game->enemy_x][game->enemy_y + 1] == 'P'))
//    {
//        if (game->map[game->enemy_x][game->enemy_y + 1] == 'P')
//		{
//			write(1, "Game over\n", 10);
//			exit(0);
//		}
//        game->map[game->enemy_x][game->enemy_y] = '0';
//        game->map[game->enemy_x][game->enemy_y + 1] = 'N';
//        game->enemy_y++;
//        bt_drawer(game, game->win);
//		if (flag <= 2 && (game->map[game->enemy_x][game->enemy_y + 1] != '0'))
//			flag = 3;
//    }
//    else if (flag <= 3 && (game->map[game->enemy_x - 1][game->enemy_y] == '0' || game->map[game->enemy_x - 1][game->enemy_y] == 'P'))
//    {
//		if (game->map[game->enemy_x - 1][game->enemy_y] == 'P')
//		{
//			write(1, "Game over\n", 10);
//			exit(0);
//		}
//        game->map[game->enemy_x][game->enemy_y] = '0';
//        game->map[game->enemy_x - 1][game->enemy_y] = 'N';
//        game->enemy_x--;
//        bt_drawer(game, game->win);
//		if (flag <= 3 && (game->map[game->enemy_x - 1][game->enemy_y] != '0'))
//		flag = 0;
//    }
//	 mlx_string_put(game->mlx, game->win, 50, 50, 0xFFFFFFF, ft_itoa(game->moves));
//	 mlx_string_put(game->mlx, game->win, 7, 50, 0xFFFFFFF, "Moves:");
//    return 0;
//}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#include <time.h>
//int enemy(t_game *game)
//{
//    static int count = 0;
	
//    count++;
//    if (count < 5000) 
//        return 0;         
//    count = 0;
//	static int flag = 0;
//    //static time_t saved_time = 0; 

//    //time_t current_time = time(NULL);
//    //if (saved_time && (current_time - saved_time) < 1)
//    //{
//    //    return 0;
//    //}
//    //saved_time = current_time;
//	//usleep(1000000);
//    if (flag == 0 && (game->map[game->enemy_x][game->enemy_y - 1] == '0' || game->map[game->enemy_x][game->enemy_y - 1] == 'P'))
//    {
		
//		if (game->map[game->enemy_x][game->enemy_y - 1] == 'P')
//		{
//			write(1, "Game over\n", 10);
//			exit(0);
//		}
//			game->map[game->enemy_x][game->enemy_y] = '0';
//			game->map[game->enemy_x][game->enemy_y - 1] = 'N';
//			game->enemy_y--;
//			bt_drawer(game, game->win);
//			if (flag == 0 && (game->map[game->enemy_x][game->enemy_y - 1] != '0')) 
//				flag = 1;
//    }
//    else if (flag <= 1 && (game->map[game->enemy_x + 1][game->enemy_y] == '0' || game->map[game->enemy_x + 1][game->enemy_y] == 'P'))
//    {
//		if (game->map[game->enemy_x + 1][game->enemy_y] == 'P')
//		{
//			write(1, "Game over\n", 10);
//			exit(0);
//		}
//        game->map[game->enemy_x][game->enemy_y] = '0';
//        game->map[game->enemy_x + 1][game->enemy_y] = 'N';
//        game->enemy_x++;
//        bt_drawer(game, game->win);
//		if (flag <= 1 && (game->map[game->enemy_x + 1][game->enemy_y] != '0'))
//		flag = 2;
//    }
//    else if (flag <= 2 && (game->map[game->enemy_x][game->enemy_y + 1] == '0' || game->map[game->enemy_x][game->enemy_y + 1] == 'P'))
//    {
//        if (game->map[game->enemy_x][game->enemy_y + 1] == 'P')
//		{
//			write(1, "Game over\n", 10);
//			exit(0);
//		}
//        game->map[game->enemy_x][game->enemy_y] = '0';
//        game->map[game->enemy_x][game->enemy_y + 1] = 'N';
//        game->enemy_y++;
//        bt_drawer(game, game->win);
//		if (flag <= 2 && (game->map[game->enemy_x][game->enemy_y + 1] != '0'))
//			flag = 3;
//    }
//    else if (flag <= 3 && (game->map[game->enemy_x - 1][game->enemy_y] == '0' || game->map[game->enemy_x - 1][game->enemy_y] == 'P'))
//    {
//		if (game->map[game->enemy_x - 1][game->enemy_y] == 'P')
//		{
//			write(1, "Game over\n", 10);
//			exit(0);
//		}
//        game->map[game->enemy_x][game->enemy_y] = '0';
//        game->map[game->enemy_x - 1][game->enemy_y] = 'N';
//        game->enemy_x--;
//        bt_drawer(game, game->win);
//		if (flag <= 3 && (game->map[game->enemy_x - 1][game->enemy_y] != '0'))
//		flag = 0;
//    }
//	 mlx_string_put(game->mlx, game->win, 50, 50, 0xFFFFFFF, ft_itoa(game->moves));
//	 mlx_string_put(game->mlx, game->win, 7, 50, 0xFFFFFFF, "Moves:");
//    return 0;
//}
//#include <stdlib.h>

//int enemy(t_game *game)
//{
//    static time_t saved_time = 0;
//    static int directions[4][2] = {
//        {0, -1}, // Move left
//        {1, 0},  // Move down
//        {0, 1},  // Move right
//        {-1, 0}  // Move up
//    };

//    time_t current_time = time(NULL);
//    if (saved_time && (current_time - saved_time) <= 1)
//    {
//        return 0;
//    }
//    saved_time = current_time;

//    int move_made = 0;
//    while (!move_made)
//    {
//        int rand_index = rand() % 4; // Choose a random direction
//        int new_x = game->enemy_x + directions[rand_index][0];
//        int new_y = game->enemy_y + directions[rand_index][1];

//        if (game->map[new_x][new_y] == '0' || game->map[new_x][new_y] == 'P')
//        {
//            if (game->map[new_x][new_y] == 'P')
//            {
//                write(1, "Game over\n", 10);
//                exit(0);
//            }
//            game->map[game->enemy_x][game->enemy_y] = '0';
//            game->map[new_x][new_y] = 'N';
//            game->enemy_x = new_x;
//            game->enemy_y = new_y;
//            bt_drawer(game, game->win);
//            move_made = 1;
//        }
//    }

//    mlx_string_put(game->mlx, game->win, 50, 50, 0xFFFFFF, ft_itoa(game->moves));
//    mlx_string_put(game->mlx, game->win, 7, 50, 0xFFFFFF, "Moves:");
//    return 0;
//}

int enemy(t_game *game)
{
    static int count = 0;
    static int flag = 0;
	int enemies_counter = 0;

	//static int direction = 0;
    count++;
    if (count < 5000)
        return 0;

    count = 0;
    int new_x = game->enemy_x[0]; 
    int new_y = game->enemy_y[0];

	while(game->enemy_x[enemies_counter] != -1)
	{
		if (flag == 0) 
		{
			if (game->map[new_x][new_y - 1] == '0' || game->map[new_x][new_y - 1] == 'P') 
			{
				new_y--;
				game->direction = 1; 
				if (game->map[new_x][new_y] != '0' && game->map[new_x][new_y] != 'P') 
				flag = 1;
			} 
			else if (game->map[new_x + 1][new_y] == '0' || game->map[new_x + 1][new_y] == 'P') 
			{
				new_x++;
				game->direction = 2;
				if (game->map[new_x][new_y] != '0' && game->map[new_x][new_y] != 'P') 
				flag = 1;
			}
			else 
				flag = 1;
    	} 
		else 
		{
			if (game->map[new_x][new_y + 1] == '0' || game->map[new_x][new_y + 1] == 'P') 
			{
				new_y++;
				game->direction = 3;
				if (game->map[new_x][new_y] != '0' && game->map[new_x][new_y] != 'P') 
				flag = 0;
			} 
			else if (game->map[new_x - 1][new_y] == '0' || game->map[new_x - 1][new_y] == 'P') 
			{
				new_x--;
				game->direction = 0; 
				if (game->map[new_x][new_y] != '0' && game->map[new_x][new_y] != 'P') 
				flag = 0;
			} 
			else 
				flag = 0;
		}
		if (game->map[new_x][new_y] == 'P')
		{
			write(1, "Game over\n", 10);
			exit(0);
		}
		game->map[game->enemy_x[enemies_counter]][game->enemy_y[enemies_counter]] = '0';
		game->map[new_x][new_y] = 'N';
		game->enemy_x[enemies_counter] = new_x;
		game->enemy_y[enemies_counter] = new_y;

		bt_drawer(game, game->win);
		enemies_counter++;
		new_x = game->enemy_x[enemies_counter]; 
    	new_y = game->enemy_y[enemies_counter];
	}
    mlx_string_put(game->mlx, game->win, 50, 50, 0xFFFFFFF, ft_itoa(game->moves));
    mlx_string_put(game->mlx, game->win, 7, 50, 0xFFFFFFF, "Moves:");
    return 0;
}

t_game game_engine(int ac, char **av)
{
	t_game game;
	void *win;

	win = NULL;
	game = parsing(ac, av);
	game.direction = 0;
	game.mlx = mlx_init();
	if (!game.mlx)
	{
		printf("unintialized\n");
		free_arr(game.map);
		exit(1);
	}
	win = mlx_new_window(game.mlx, game.width * 128,
						 game.height * 128, "My Game");
	if (!win)
		no_crash(NULL, &game, 0);
	game.win = win;
	b_storing_images(&game);
	bt_drawer(&game, win);
	game.moves = 0;
	game.key = mlx_key_hook(win, key_hook, &game);
	if (!game.key)
		no_crash(NULL, &game, 6);
	mlx_hook(game.win, 17, 0L, close_window, &game);
	catch_him_if_you_can(&game);
	// srand(time(NULL)); 
	mlx_loop_hook(game.mlx, enemy, &game);
	//mlx_loop_hook(game.mlx, draw_text, &game);
	//enemy(&game);
	mlx_loop(game.mlx);
	return (game);
}

int main(int ac, char **av)
{
	t_game game;
	game.direction = 0;
	game = game_engine(ac, av);
	
	// printer(game);
	// catch_him_if_you_can(&game);
	// enemy(&game);
	// mlx_loop(game.mlx);
}


// make it work on multiple cockroaches
// try to make moves doesnt flinch
// parse cases
// test and then norminette