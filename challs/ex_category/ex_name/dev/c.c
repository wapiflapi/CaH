#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	main()
{
  int	fd;
  int	r;
  char	buf[42];
  
  fd = open("flag", O_RDONLY);
  if (fd < 0)
    err(EXIT_FAILURE, "open");

  r = read(fd, buf, 42);
  if (r < 0)
    err(EXIT_FAILURE, "read");

  buf[r] = 0;
  puts(buf);
  
  return 0;
}
