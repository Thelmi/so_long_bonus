/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thelmy <thelmy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 23:36:59 by thelmy            #+#    #+#             */
/*   Updated: 2024/07/22 00:19:16 by thelmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(SO_LONG)
#define SO_LONG
# define W 13
# define S 1
# define D 2
# define A 0
# define ESC 53

#include "stdlib.h"
#include "fcntl.h"
# include "stdio.h"
#include "./minilibx/mlx.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

typedef struct images
{
	void	*img;
	int		img_width;
	int		img_height;
}			t_images;

typedef struct node
{
	int			enemy_counter;
	int			direction;
	int			height;
	int			width;
	char		**map;
	char		**copy;
	char		*read;
	int			x;
	int			y;
	int			enemy_x[200];
	int			enemy_y[200];
	int			end;
	int			player;
	int			key;
	int			exit;
	int			coins;
	int			apple;
	int			*size;
	void		*mlx;
	void		*win;
	int			moves;
	int			z;
	int			fd;
	t_images	graphics[9];
}				t_game;

size_t	t_strlen(char *str);
int		t_strncmp( char *s1, char *s2, size_t n);
int		t_strnstr(char *haystack, char *needle);
t_game	map_parsing(int fd);
t_game	parsing(int ac, char **av);
void	w_key_hook(t_game **game);
void	s_key_hook(t_game **game);
void	a_key_hook(t_game **game);
void	d_key_hook(t_game **game);
void	t_drawer(t_game *game, void *win);
int		valid_letters_count(char **str, t_game *game, char *read, int fd);
char	**free_arr(char **arr);
int		is_fully_one(char *str);
int		is_one(char *str);
int		t_strchr(const char *s, int c);
void	catch_me_if_you_can(t_game *map);
void	flood_fill(t_game *game, int x, int y);
void	empty_map(char *str, char *s, int fd);
void	ouch(char **str, t_game game);
void	no_crash(t_game **game, t_game *image, int i);
void	delete_images(t_game **game, t_game *image, int i);
int		close_window(t_game *game);
int		key_hook(int keycode, t_game *game);
void	bt_drawer(t_game *game, void *win);

#endif
//-fsanitize=address -g3