/*
** my_params_in_list.c for my_params_in_list in /home/antonin.rapini/CPool_Day11/task01
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Mon Oct 17 09:13:41 2016 Antonin Rapini
** Last update Sun Nov 27 19:02:51 2016 Antonin Rapini
*/

#include <stdlib.h>
#include "mylist.h"
#include "utils.h"

t_list		*create_list_element(t_list **list, int data)
{
  t_list	*element;

  element = malloc(sizeof(t_list *));
  if (element == NULL)
    exit(84);
  element->nbr = data;
  element->next = *list;
  *list = element;
  return (element);
}

void		set_previous(t_list *list)
{
  t_list	*first;

  first = list;
  while (list->next != NULL)
    {
      list->next->previous = list;
      list = list->next;
    }
  first->previous = list;
}

t_list		*my_params_in_list(int ac, char **av)
{
  int		index;
  t_list	*list;

  list = NULL;
  index = ac - 1;
  while (index-- > 0)
    create_list_element(&list, my_getnbr(av[index + 1]));
  set_previous(list);
  return (list);
}
