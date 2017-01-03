#include "libft.h"
#include "fillit.h"

int	solve(t_list *pieces, t_list *map)
{
  if (!pieces || !pieces->content)
    return (1);
  if (fits(pieces->content, map))
    return (solve(ft_lst_butlast(ft_lst_rot(pieces, 1)), map));
  else if (map->next)
    return (solve(pieces, map->next));
  level_map(map);
  return (0);
}
