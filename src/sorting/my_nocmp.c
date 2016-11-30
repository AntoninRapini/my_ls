/*
** my_nocmp.c for my_ls in /home/antonin.rapini/UnixSystemProgrammation/PSU_2016_my_ls/src/sorting
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Tue Nov 29 10:11:17 2016 Antonin Rapini
** Last update Tue Nov 29 21:59:54 2016 Antonin Rapini
*/

#include "my_fileinfos.h"

int	my_nocmp(t_fileinfos *file1, t_fileinfos *file2)
{
  if (file1->name[0] == file2->name[0])
    return (0);
  return (0);
}
