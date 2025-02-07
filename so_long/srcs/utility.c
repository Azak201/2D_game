/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amismail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:43:42 by amismail          #+#    #+#             */
/*   Updated: 2025/01/16 15:44:02 by amismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_map	*define_struct(char **map_str)
{
	t_map	*main_map;

	main_map = (t_map *)malloc(sizeof(t_map));
	if (!main_map)
		ft_free(1, map_str, "fail in malloc");
	main_map->map = map_str;
	main_map->col_p = 0;
	main_map->row_p = 0;
	main_map->c = 0;
	main_map->p = 0;
	main_map->e = 0;
	main_map->col_num = 0;
	main_map->row_num = 0;
	main_map->fmap = NULL;
	return (main_map);
}

void	find_p(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j] != '\0')
		{
			if (map->map[i][j] == 'P')
			{
				map->col_p = j;
				map->row_p = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	find_e(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j] != '\0')
		{
			if (map->map[i][j] == 'E')
			{
				map->col_e = j;
				map->row_e = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

char	**create_fmap(t_map **main_map)
{
	int		i;
	char	**fmap;

	i = 0;
	while ((*main_map)->map[i] != NULL)
		i++;
	fmap = (char **)malloc(sizeof(char *) * (i + 1));
	if (!fmap)
		ft_free_map_struct(1, &(*main_map), "fail Alocation in fmap");
	i = 0;
	while ((*main_map)->map[i] != NULL)
	{
		fmap[i] = ft_strdup((*main_map)->map[i]);
		if (!fmap[i])
		{
			ft_free(0, fmap, 0);
			ft_free_map_struct(1, &(*main_map), "fail Alocation in fmap");
		}
		i++;
	}
	fmap[i] = NULL;
	return (fmap);
}

int	find_c(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->fmap[i] != NULL)
	{
		j = 0;
		while (map->fmap[i][j] != '\0')
		{
			if (map->fmap[i][j] == 'C' || map->fmap[i][j] == 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
