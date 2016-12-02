/*
** my_get_typespecifier.c for my_ls in /home/antonin.rapini/UnixSystemProgrammation/PSU_2016_my_ls/src/display
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Thu Dec  1 17:30:50 2016 Antonin Rapini
** Last update Fri Dec  2 15:13:18 2016 Antonin Rapini
*/

#include "my_options.h"
#include <sys/stat.h>
#include <fcntl.h>

char my_get_typespecifier(t_options *options, mode_t st_mode)
{
  if (options->show_filetype)
    {
      if (S_ISDIR(st_mode))
	return ('/');
      if (S_ISLNK(st_mode))
	return ('@');
    }
  return ('\0');
}
