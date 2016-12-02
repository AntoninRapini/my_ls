/*
** my_atimecmp.c for my_ls in /home/antonin.rapini/UnixSystemProgrammation/PSU_2016_my_ls/src/sorting
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Tue Nov 29 10:10:53 2016 Antonin Rapini
** Last update Fri Dec  2 21:03:47 2016 Antonin Rapini
*/

#include <sys/stat.h>
#include "my_fileinfos.h"

int	my_mtimecmp(t_fileinfos *file1, t_fileinfos *file2)
{
  return (file1->stat_data->st_mtime < file2->stat_data->st_mtime);
}
