/*
** my_sort_list.c for CPool_Day11 in /home/antonin.rapini/CPool_Day11/task10
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Mon Oct 17 14:16:13 2016 Antonin Rapini
** Last update Wed Nov 30 18:21:42 2016 Antonin Rapini
*/

#include <stdlib.h>
#include "my_sorting.h"

void		my_sort_list(t_list **begin, t_options *options)
{
  int		sorted;
  t_fileinfos	*holder;
  t_list	*first;

  first = *begin;
  sorted = 0;
  holder = NULL;
  while (sorted == 0)
    {
      sorted = 1;
      while ((*begin)->next != NULL)
	{
	  if (options->my_compfnc((*begin)->fileinfos, (*begin)->next->fileinfos))
	    {
	      holder = (*begin)->next->fileinfos;
	      (*begin)->next->fileinfos = (*begin)->fileinfos;
	      (*begin)->fileinfos = holder;
	      sorted = 0;
	    }
	  (*begin) = (*begin)->next;
	}
      (*begin) = first;
    }
  if (options->reversed || (options->my_compfnc == my_nocmp && !options->reversed))
    my_reverse_list(begin);
}
