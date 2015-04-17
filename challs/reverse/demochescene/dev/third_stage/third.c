/*
** second.c for second in /home/ampotos/c@h/cq-ctf/challs/reverse/demochescene/dev/second_stage
** 
** Made by 
** Login   <ampotos@epitech.net>
** 
** Started on  Mon Apr 13 21:29:29 2015 
** Last update Wed Apr 15 18:44:23 2015 
*/

#include "../ptr.h"

void third_stage(t_section *sections, t_ptr *ptrs)
{
  unsigned char	buff[8];
  char  enter[] = {'E', 'n', 't', 'e', 'r', ' ', 't', 'h', 'i', 'r', 'd', ' ', 'p', 'a', 's', 's', 'w', 'o', 'r', 'd', 0};
  char  bad[] =  {'B', 'a', 'd', ' ', 'p', 'a', 's', 's', 'w', 'o', 'r', 'd', ' ', 'l', 'e', 'n', 'g', 't', 'h', 0};
  
  ptrs->puts(enter);
  if (ptrs->read(0, buff, 8) != 8)
    {
      ptrs->puts(bad);
      ptrs->exit (0);
    }
  for (int ct = 0; ct < 2; ct++)
    for (int ct2 = 0; ct2 < sections[ct].size; ct2++)
      sections[ct].data[ct2] = (sections[ct].data[ct2] + buff[ct2 % 7]) % 256;
  ((void (*)(t_section *, t_ptr *))(sections->data))(sections + 1, ptrs);
}
