/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amismail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:42:44 by amismail          #+#    #+#             */
/*   Updated: 2025/01/25 18:17:41 by amismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/*this function apply the flood fill alg. on the map sent to it*/
void	flood_fill(t_map **map, int p_row, int p_col)
{
	if (p_row < 0 || p_col < 0 || p_col >= (*map)->col_num
		|| p_row >= (*map)->row_num)
		return ;
	if ((*map)->fmap[p_row][p_col] == '1' ||
		(*map)->fmap[p_row][p_col] == 'F')
		return ;
	(*map)->fmap[p_row][p_col] = 'F';
	flood_fill(&(*map), p_row - 1, p_col);
	flood_fill(&(*map), p_row + 1, p_col);
	flood_fill(&(*map), p_row, p_col + 1);
	flood_fill(&(*map), p_row, p_col - 1);
}

void	check_empty_lines(char **line)
{
	int	i;

	i = 0;
	while ((*line)[i] != '\0')
	{
		if ((((*line)[i] == '\n') && ((*line)[i + 1] == '\n')) ||
			((*line)[0] == '\n'))
		{
			free(*line);
			ft_exit_fd(2, "there is empty lines", 0);
		}
		i++;
	}
}

void	fail_up_img(t_game *s_l)
{
	img_dest(&(*s_l));
	if (s_l->win_ptr)
		mlx_destroy_window(s_l->mlx_ptr, s_l->win_ptr);
	if (s_l->mlx_ptr)
		mlx_destroy_display(s_l->mlx_ptr);
	ft_free_game(1, &s_l, "error in uploading images");
	exit(1);
}

void	img_dest(t_game *s_l)
{
	if (s_l->g_img)
		mlx_destroy_image(s_l->mlx_ptr, s_l->g_img);
	if (s_l->w_img)
		mlx_destroy_image(s_l->mlx_ptr, s_l->w_img);
	if (s_l->p_img)
		mlx_destroy_image(s_l->mlx_ptr, s_l->p_img);
	if (s_l->c_img)
		mlx_destroy_image(s_l->mlx_ptr, s_l->c_img);
	if (s_l->p_a)
		mlx_destroy_image(s_l->mlx_ptr, s_l->p_a);
	if (s_l->p_d)
		mlx_destroy_image(s_l->mlx_ptr, s_l->p_d);
	if (s_l->p_s)
		mlx_destroy_image(s_l->mlx_ptr, s_l->p_s);
	if (s_l->p_w)
		mlx_destroy_image(s_l->mlx_ptr, s_l->p_w);
	if (s_l->c_e_img)
		mlx_destroy_image(s_l->mlx_ptr, s_l->c_e_img);
	if (s_l->op_e_img)
		mlx_destroy_image(s_l->mlx_ptr, s_l->op_e_img);
}
