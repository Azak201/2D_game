/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amismail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:42:57 by amismail          #+#    #+#             */
/*   Updated: 2025/01/16 15:43:01 by amismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	counter(char mc, int *c, int *p, int *e);
static void	eadges_validating(t_map **tmap);
static void	validate_map_contant(char **map, t_map **main_map);

/*this function check if there empty lines in the map at first
then it convert the map string called "line" to 2D array and check
if it rectangeluer and return the 2D array*/
char	**handling_map_shape(char **line)
{
	char	**tmp;
	int		i;
	int		cmp;
	int		len;

	check_empty_lines(&(*line));
	tmp = ft_split(*line, '\n');
	if (!tmp)
	{
		free(*line);
		ft_exit_fd(2, "Failure in allocation", 0);
	}
	i = 0;
	cmp = ft_strlen(tmp[0]);
	while (tmp[i] != NULL)
	{
		len = ft_strlen(tmp[i]);
		if ((cmp != len) || (tmp[i + 1] == NULL && i < 2) || len < 3)
		{
			free(*line);
			ft_free(1, tmp, "invalid  map shape");
		}
		i++;
	}
	return (tmp);
}

/*this func. check for the contant of map thats only "ECP01"
and create struct map then its check on the eadges thats
only 1s and create copy of map and apply the flood_fill on it
then return the struct pointer*/
t_map	*map_validation(char **map)
{
	int		i;
	t_map	*main_map;

	i = 0;
	main_map = define_struct(map);
	validate_map_contant(map, &main_map);
	while (main_map->map[i] != NULL)
		i++;
	main_map->row_num = i;
	main_map->col_num = ft_strlen(main_map->map[0]);
	eadges_validating(&main_map);
	find_p(&(*main_map));
	find_e(&(*main_map));
	main_map->fmap = create_fmap(&main_map);
	flood_fill(&main_map, main_map->row_p, main_map->col_p);
	if ((find_c((main_map)) == 1))
		ft_free_map_struct(1, &main_map, "C OR E is not reachable");
	return (main_map);
}

/*this function check for ECP01 and its numbers */
static void	validate_map_contant(char **map, t_map **main_map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (ft_strchr("01EPC", map[i][j]) == NULL)
				ft_free_map_struct(1, main_map, "map contant not valid");
			counter(map[i][j], &((*main_map)->c), &((*main_map)->p),
				&((*main_map)->e));
			j++;
		}
		i++;
	}
	if ((*main_map)->c < 1 || (*main_map)->e != 1 || (*main_map)->p != 1)
		ft_free_map_struct(1, main_map, "invalid number of E, P or C");
}

static void	counter(char mc, int *c, int *p, int *e)
{
	if (mc == 'C')
		*c = *c + 1;
	if (mc == 'P')
		*p = *p + 1;
	if (mc == 'E')
		*e = *e + 1;
}

/*this function check for first and last row/column that they all 1s */
static void	eadges_validating(t_map **tmap)
{
	int	i;
	int	j;

	i = 0;
	while ((*tmap)->map[i] != NULL)
	{
		j = 0;
		while ((*tmap)->map[i][j] != '\0')
		{
			if ((*tmap)->map[0][j] != '1'
				|| (*tmap)->map[(*tmap)->row_num - 1][j] != '1')
				ft_free_map_struct(1, tmap, " rowe adge are not 1 !!?");
			j++;
		}
		if ((*tmap)->map[i][0] != '1'
			|| (*tmap)->map[i][(*tmap)->col_num - 1] != '1')
			ft_free_map_struct(1, tmap, "colums are not 1 !!?");
		i++;
	}
}
