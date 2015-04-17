/*
** test.c for test in /home/ampotos/c@h/rev_stage
** 
** Made by 
** Login   <ampotos@epitech.net>
** 
** Started on  Sat Mar 28 11:42:35 2015 
** Last update Wed Apr 15 19:56:20 2015 
*/

#include <unistd.h>
#include <elf.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include "../ptr.h"

Elf64_Shdr *get_section(Elf64_Ehdr *header, char *file, int idx)
{
  return (Elf64_Shdr*)((Elf64_Ehdr*)(file + header->e_shoff + header->e_shentsize * idx));
}

char *get_string(Elf64_Word idx, Elf64_Ehdr *header, char *file)
{
  return file + get_section(header, file, header->e_shstrndx)->sh_offset + idx;
}

char*	map_section(char *file, Elf64_Shdr *section)
{
  char	*map;

  if ((map = mmap(NULL, (section->sh_size / 4096 + 1) * 4096, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0)) == MAP_FAILED)
    {
      printf("Mmap error : %m\n");
      exit (0);
    }
  memcpy(map, file + section->sh_offset, section->sh_size);
  return (map);
}

void	load_section(Elf64_Ehdr *header, char *file, char *section_name, t_section *section_ptr)
{
  Elf64_Half nb_entry;
  
  Elf64_Shdr	*section;
  char	*name;
  
  nb_entry = header->e_shnum;
  for (int i = 0; i < nb_entry; i++)
    {
      section = get_section(header, file, i);
      name = get_string(section->sh_name, header, file);
      if (!strcmp(name, section_name))
	{
	  section_ptr->data = map_section(file, section);
	  section_ptr->size = section->sh_size;
	  break;
	}
    }
}

void 	load_all_section(Elf64_Ehdr *header, char *file, t_section *sections)
{
  load_section(header, file, "hidden1", sections);
  load_section(header, file, "hidden2", sections + 1);
  load_section(header, file, "hidden3", sections + 2);
  load_section(header, file, "demochescene", sections + 3);
}

void	setup_ptr(t_ptr *ptrs)
{
  ptrs->puts = &puts;
  ptrs->execl = &execl;
  ptrs->shm_open = &shm_open;
  ptrs->write = &write;
  ptrs->read = &read;
  ptrs->exit = &exit;
  ptrs->close = &close;
  ptrs->fork = &fork;
  ptrs->waitpid = &waitpid;
  ptrs->shm_unlink = &shm_unlink;
}

void		uncipher_stage1(t_section *sections, t_ptr *ptrs)
{
  unsigned char	buff[8];

  puts("Enter first password");
  if (read(0, buff, 8) != 8)
    {
      puts("Bad password length");
      exit(0);
    }
  for (int ct = 0; ct < 4; ct++)
      for (int ct2 = 0; ct2 < sections[ct].size; ct2++)
	sections[ct].data[ct2] ^= buff[ct2 % 7];
  ((void (*)(t_section *, t_ptr *))(sections->data))(sections + 1, ptrs);
}

int main(int ac, char **ag)
{
  int	fd;
  char	*file;
  int	size;
  Elf64_Ehdr	*header;
  t_section	sections[4];
  t_ptr		ptrs;
  
  if ((fd = open(ag[0], O_RDONLY)) < 0)
    {
      printf("open error : %m\n");
      exit (0);
    }
  if (ioctl(fd, FIONREAD, &size))
    {
      printf("ioctl error\n");
      exit (0);
    }
  file = malloc(size);
  read(fd, file, size);
  header = (Elf64_Ehdr*)file;
  load_all_section(header, file, sections);
  setup_ptr(&ptrs);
  close(fd);
  uncipher_stage1(sections, &ptrs);
  return (0);
}
