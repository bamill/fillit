#include "libft.h"
#include "fillit.h"

void	alphabeterizer(t_list *pieces, size_t s, size_t n)
{
  int i;

  i = 0;
  if (!pieces || !(pieces->content) || size == 0)
    return ;
  while (pieces->content[i])
    {
      if (pieces->content[i] == '#')
	pieces->content[i] = ('A' + n);
      i++;
    }
  alphabeterizer(pieces->next, s - 1, n + 1);
}
