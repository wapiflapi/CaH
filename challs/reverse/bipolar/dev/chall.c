
#include <math.h>
#include <err.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define NB_CHAR (5)

int	hash(int val)
{
  int	i;
  int	j;
  int	tmp;
  int	sum;

  tmp = 0;
  sum = 0;
  tmp = val;

  sum = 0;
  for (i = 0 ; i < 8 ; i++)
    {
      tmp = 0;
      for (j = 0 ; j < 8 ; j++)
	{
	  tmp += (((val >> i) >> j) & 1) * pow(2, i);
	}
      sum += tmp;
    }
  return sum;
}

int	check(unsigned char *s)
{
  int	i;
  int	len;
  int	res;
 
  len = strlen(s);
  if (len != NB_CHAR)
    return 0;

  res = 1;
  for (i = 0 ; i < NB_CHAR ; i++)
    {
      res += s[i] ^ 42;
      res += s[i] & 0x7;
      res += s[i] & 0xf;
    }
  if (hash(*s) != 424)
    return 0;
  return res;
}

int	main(int ac, char **av)
{
  if (ac != 2)
    errx(EXIT_FAILURE, "Usage: %s password", *av);

  if (check(av[1]) != 1337)
    errx(EXIT_FAILURE, "Bad password");
  puts("This is not the droid you're looking for. I swear.");
  return 0;
}

int	main_hidden(int ac, char **av)
{
  int	i;
  char	flag[] = {0xb1, 0xbb, 0xb6, 0xb0, 0xac, 0x83, 0xbf, 0xe6, 0xa4, 0x88, 0xe6, 0xa4, 0x88, 0xa3, 0xbf, 0xb2, 0x88, 0xb2, 0xb9, 0xa3, 0xa5, 0xae, 0x88, 0xa7, 0xe7, 0xbe, 0xb9, 0xa3, 0x88,0xae, 0xb8, 0xa2, 0x88, 0xb6, 0xa5, 0xb2, 0x88, 0xbb, 0xe7, 0xe7, 0xbc, 0xbe, 0xb9, 0xb0, 0x88, 0xb1, 0xb8, 0xa5, 0xaa, 0x00};
    
  if (ac != 2)
    errx(EXIT_FAILURE, "Usage: %s password", *av);

  if (check(av[1]) != 1336)
    errx(EXIT_FAILURE, "Bad password");

  for (i = 0 ; i < sizeof flag ; i++)
    flag[i] ^= av[1][0];

  flag[sizeof(flag) - 1] = 0;
  
  puts(flag);
}

void	start_hidden()
{
  asm volatile ("pop %rbp");
  asm volatile ("xor %ebp, %ebp");
  asm volatile ("mov %rdx, %r9");
  asm volatile ("pop %rsi");
  asm volatile ("mov %rsp, %rdx");
  asm volatile ("and $0xfffffffffffffff0, %rsp");
  asm volatile ("push %rax");
  asm volatile ("push %rsp");
  asm volatile ("mov $__libc_csu_fini, %r8");
  asm volatile ("mov $__libc_csu_init, %rcx");
  asm volatile ("mov $main_hidden, %rdi");
  asm volatile ("callq __libc_start_main");
  asm volatile ("hlt");
}
