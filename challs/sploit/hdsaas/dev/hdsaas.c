#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>

char cmd[] = "/usr/bin/hexdump -Cv /tmp/hexdump_XXXXXX";
char *name = cmd + 21;

int	main(int argc, char **argv)
{
  int done, sz, fd;
  char data[1234];

  done = 0;
  while (done < sizeof data)
    {

      if (read(0, &sz, sizeof sz) <= 0)
	errx(EXIT_FAILURE, "error: no size");
      if ((sz = read(0, &data, sz)) < 0)
	errx(EXIT_FAILURE, "error: no data");

      done += sz;

      memset(name + 13, 'X', 6);
      if ((fd = mkstemp(name)) < 0)
	err(EXIT_FAILURE, "mkstemp");

      write(fd, data, sizeof data);

      system(cmd);

      if (unlink(name))
	err(EXIT_FAILURE, "unlink");
      close(fd);
    }

  return EXIT_SUCCESS;
}
