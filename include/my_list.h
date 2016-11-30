/*
** my_list.h for my_ls in /home/antonin.rapini/UnixSystemProgrammation/PSU_2016_my_ls/include
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Tue Nov 29 09:28:08 2016 Antonin Rapini
** Last update Tue Nov 29 22:05:06 2016 Antonin Rapini
*/

#ifndef MY_LIST_H_
# define MY_LIST_H_

#include "my_fileinfos.h"

typedef struct	s_list
{
  t_fileinfos	*fileinfos;
  struct s_list *next;
  struct s_list *previous;
}		t_list;

#endif /* !MY_LIST_H_ */
