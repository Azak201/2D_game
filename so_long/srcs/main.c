/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amismail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:38:33 by amismail          #+#    #+#             */
/*   Updated: 2025/01/25 18:19:12 by amismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	fail_join(char *tmp, char *tmp2, int fd);
static char	*file_read(int fd);

/*void print_maps(t_map *map)
{
	int i;

	i = 0;
	while (map->map[i] != NULL)
	{
		ft_printf("%s\n", map->map[i]);
		i++;
	}
	i = 0;
	ft_printf("\n------------------\n");
	while (map->fmap[i] != NULL)
	{
		ft_printf("%s\n", map->fmap[i]);
		i++;
	}
}*/
/*in the main function we cheak the arg num and the extention of the file
then read the map from its file and create 2d array from it and check that its
valid then creat structed map with its atribute and then send it to create_game
function
*/
int	main(int arc, char **argv)
{
	int		fd;
	char	*line;
	char	**map;
	int		len;
	t_map	*tmap;

	if (arc != 2)
		ft_exit_fd(2, "invalid args number", 0);
	len = ft_strlen(argv[1]);
	if ((ft_strncmp(argv[1] + (len - 4), ".ber", 5) != 0))
		ft_exit_fd(2, "invalid File extention", 0);
	fd = open(argv[1], O_RDONLY);
	line = file_read(fd);
	close(fd);
	map = handling_map_shape(&line);
	free(line);
	tmap = map_validation(&(*map));
	create_the_game(&tmap);
}

/* this function read the map from its file file and check for reading and fd
 errors and joining the map to create one long string represent the whole
 map */
static char	*file_read(int fd)
{
	int		i;
	char	*tmp;
	char	*tmp2;
	char	*line;

	if (fd < 0)
		ft_exit_fd(2, "failure in opening file", 0);
	line = NULL;
	i = 0;
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp && i == 0)
			ft_exit_fd(1, "failure in read or file is empty", fd);
		tmp2 = line;
		line = ft_strjoin(tmp2, tmp);
		if (i++ > 0)
			free(tmp2);
		if (!line)
			fail_join(tmp, tmp2, fd);
		if (!tmp)
			return (line);
		free(tmp);
	}
}
/*this function work only if the file_read have problem in its join between
 the get_next_line and the next one of it , keep reading the file to reach
  EOF so doesn't have the still reachable inner static variable */

static void	fail_join(char *tmp, char *tmp2, int fd)
{
	if (tmp)
		free(tmp);
	if (tmp2)
		free(tmp2);
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		free(tmp);
		tmp = get_next_line(fd);
	}
	ft_exit_fd(1, "failure in reading file", fd);
}

static t_game	*define_game(t_map **map)
{
	t_game	*s;

	s = (t_game *)malloc(sizeof(t_game));
	if (!s)
		ft_free_map_struct(1, &(*map), "fail in maloc t_game");
	s->tmap = map;
	s->mlx_ptr = NULL;
	s->win_ptr = NULL;
	s->g_img = NULL;
	s->w_img = NULL;
	s->p_img = NULL;
	s->c_img = NULL;
	s->c_e_img = NULL;
	s->op_e_img = NULL;
	s->p_a = NULL;
	s->p_d = NULL;
	s->p_s = NULL;
	s->p_w = NULL;
	s->count = 0;
	return (s);
}

/*this is the main function that run the GUI by connecting with X server
and upload the map and handle the keys to play game and keep it runnig*/
void	create_the_game(t_map **tmap)
{
	t_game	*s_l;
	int		x;
	int		y;

	s_l = define_game(tmap);
	x = s_l->tmap[0]->col_num * 50;
	y = s_l->tmap[0]->row_num * 50;
	s_l->mlx_ptr = mlx_init();
	if (s_l->mlx_ptr == NULL)
		ft_free_game(1, &s_l, "fail in create connection");
	s_l->win_ptr = mlx_new_window(s_l->mlx_ptr, x, y, "so_long");
	if (s_l->win_ptr == NULL)
	{
		ft_printf("Error\nfail in create window");
		destroy_win(&(*s_l));
	}
	upload_images(&(*s_l));
	upload_map(&(*s_l));
	mlx_key_hook(s_l->win_ptr, input_handle, &(*s_l));
	mlx_hook(s_l->win_ptr, 17, 0L, destroy_win, &(*s_l));
	mlx_loop(s_l->mlx_ptr);
}
