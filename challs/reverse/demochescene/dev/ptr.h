//
// ptr.h for ptr in /home/ampotos/c@h/cq-ctf/challs/reverse/demochescene/dev
// 
// Made by 
// Login   <ampotos@epitech.net>
// 
// Started on  Sun Apr 12 17:47:28 2015 
// Last update Wed Apr 15 19:50:36 2015 
//

#ifndef PTR_h_
#define PTR_h_

#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

typedef struct
{
  int (*puts)(const char*);
  int (*execl)(const char *, const char *, ...);
  int (*shm_open)(const char *name, int , mode_t);
  ssize_t (*write)(int, const void *, size_t);
  ssize_t (*read)(int, void *, size_t);
  int (*close)(int);
  void	(*exit)(int);
  pid_t (*fork)(void);
  pid_t (*waitpid)(pid_t, int*, int);
  int  (*shm_unlink)(const char *);
} t_ptr;

typedef struct
{
  int		size;
  unsigned char	*data;
} t_section;

#endif
