/*
** my_rev_list.c for CPool_Day11 in /home/antonin.rapini/CPool_Day11/task03
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Mon Oct 17 10:55:30 2016 Antonin Rapini
** Last update Tue Nov 29 10:21:34 2016 Antonin Rapini
*/

#include "../include/mylist.h"
#include <stdlib.h>

t_list		*create_rev_list_element(t_list **previous, char *data)
{
  t_list	*element;

  element = malloc(sizeof(t_list *));
  if (element == NULL)
    exit (84);
  element->data = data;
  element->next = *previous;
  *previous = element;
  return (element);
}

int		my_rev_list(t_list **begin)
{
  t_list	*previous;
  t_list	*holder;

  holder = NULL;
  previous = 0;
  while ((*begin) != NULL)
    {
      holder = create_rev_list_element(&previous, (*begin)->data);
      (*begin) = (*begin)->next;
    }
  (*begin) = holder;
  return (0);
}
