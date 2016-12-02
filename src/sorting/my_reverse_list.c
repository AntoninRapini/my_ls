/*
** my_reverse.c for my_ls in /home/antonin.rapini/UnixSystemProgrammation/PSU_2016_my_ls/src/sorting
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Tue Nov 29 10:09:46 2016 Antonin Rapini
** Last update Fri Dec  2 21:03:14 2016 Antonin Rapini
*/

#include <stdlib.h>
#include "my_list.h"

void	my_reverse_list(t_list **list)
{
  t_list *new_prev;

  while ((*list)->next != NULL)
    {
      new_prev = (*list)->previous;
      (*list)->previous = (*list)->next;
      (*list)->next = new_prev;
      (*list) = (*list)->previous;
    }
  new_prev = (*list)->previous;
  (*list)->previous = (*list)->next;
  (*list)->next = new_prev;
}
