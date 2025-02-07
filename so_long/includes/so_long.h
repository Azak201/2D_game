/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amismail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:42:32 by amismail          #+#    #+#             */
/*   Updated: 2024/12/21 03:33:28 by amismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <libft.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <mlx.h>

typedef struct s_map
{
	char	**map;
	char	**fmap;
	int		col_p;
	int		row_p;
	int		col_e;
	int		row_e;
	int		c;
	int		p;
	int		e;
	int		row_num;
	int		col_num;
}	t_map;

typedef struct s_game
{
	t_map	**tmap;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*p_img;
	void	*w_img;
	void	*c_img;
	void	*c_e_img;
	void	*op_e_img;
	void	*g_img;
	void	*p_w;
	void	*p_s;
	void	*p_d;
	void	*p_a;
	int		count;
}	t_game;

char	**handling_map_shape(char **line);
void	ft_exit_fd(int flag, char *message, int fd);
void	ft_free(int flag, char **arr, char *message);
t_map	*map_validation(char **map);
t_map	*define_struct(char **map_str);
void	find_p(t_map *map);
int		find_c(t_map *map);
void	find_e(t_map *map);
void	check_empty_lines(char **line);
void	ft_free(int flag, char **arr, char *message);
void	ft_free_map_struct(int flag, t_map **stru, char *message);
char	**create_fmap(t_map **main_map);
void	flood_fill(t_map **map, int p_row, int p_col);
void	create_the_game(t_map **tmap);
void	upload_images(t_game *so_long);
int		destroy_win(t_game *so_long);
int		input_handle(int key, t_game *so_long);
void	upload_map(t_game *s_l);
void	put_image(t_game *s_l, char c, int x, int y);
void	ft_free_game(int flag, t_game **s_l, char *message);
void	up(t_game *s);
void	down(t_game *s);
void	right(t_game *s);
void	left(t_game *s);
void	fail_up_img(t_game *s_l);
void	img_dest(t_game *s_l);
#endif
