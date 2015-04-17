/*
** send_me_your_secret.c for send_me_your_secret in /home/ampotos/c@h/rev_50
** 
** Made by 
** Login   <ampotos@epitech.net>
** 
** Started on  Tue Mar 24 16:29:00 2015 
** Last update Mon Mar 30 22:30:42 2015 
*/

/* TODO: */
/*    make the asm file with incbin */


#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>

extern unsigned char *secret;

void	cipher(unsigned char *data, size_t len)
{
  for (size_t i = 0; i < len; i++)
    data[(i + data[i]) % len] ^= data[i];
}

int main(int ac, char **av)
{
  unsigned char *data;	
  int		fd;
  struct stat	stat;

  if (ac != 2)
    {
      puts("Usage : ./send_me_your_secret file");
      return (0);
    }
  if ((fd = open(av[1], O_RDONLY)) < 0)
    {
      printf("Can't open %s\n", av[1]);
      return (0);
    }
  if (fstat(fd, &stat))
    {
      printf("Can't fstat %s\n", av[1]);
      return (0);
    }    
  if ((data = mmap(NULL, stat.st_size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
    {
      printf("Can't mmap %s => %m\n", av[1]);
      return (0);
    }        
  cipher(data, stat.st_size);
  if (memcmp(data, &secret, stat.st_size))
    printf("This is not my secret\n");
  else
    printf("Yes this is my secret, take a look to find the flag\n");
  munmap(data, stat.st_size);
  close(fd);
  return (0);
}
