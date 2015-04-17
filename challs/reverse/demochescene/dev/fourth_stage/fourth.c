/*
** second.c for second in /home/ampotos/c@h/cq-ctf/challs/reverse/demochescene/dev/second_stage
** 
** Made by 
** Login   <ampotos@epitech.net>
** 
** Started on  Mon Apr 13 21:29:29 2015 
** Last update Wed Apr 15 19:44:31 2015 
*/

#include "../ptr.h"
#include <fcntl.h>
#include <sys/stat.h>

void fourth_stage(t_section *sections, t_ptr *ptrs)
{
  unsigned char	buff[8];
  int	fd;
  char  enter[] = {'E', 'n', 't', 'e', 'r', ' ', 'f', 'o', 'u', 'r', 't', 'h', ' ', 'p', 'a', 's', 's', 'w', 'o', 'r', 'd', 0};
  char  shm[] = {'/', 'd', 'e', 'm', 'o', 'c', 'h', 'e', 's', 'c', 'e', 'n', 'e', 0};
  char	exec[] = {'/', 'd', 'e', 'v', '/', 's', 'h', 'm', '/', 'd', 'e', 'm', 'o', 'c', 'h', 'e', 's', 'c', 'e', 'n', 'e', 0};
  int fd_exec;
  
  ptrs->puts(enter);
  ptrs->read(0, buff, 8);
  for (int ct2 = 0; ct2 < sections->size; ct2++)
    if (sections->data[ct2] - buff[ct2 % 7] >= 0)
      sections->data[ct2] -= buff[ct2 % 7];
    else
      sections->data[ct2] -= buff[ct2 % 7] + 256;
  fd = ptrs->shm_open(shm, O_CREAT | O_RDWR, S_IRWXU);
  ptrs->write(fd, sections->data, sections->size);
  ptrs->close(fd);
  fd_exec = ptrs->fork();
  if (!fd_exec)
    ptrs->execl(exec, exec, 0);
  ptrs->waitpid(-1, NULL, 0);
  ptrs->shm_unlink(shm);
}
