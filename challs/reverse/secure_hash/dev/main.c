#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "md5.h"

#define MD5_DIGEST_LENGTH 16

int is_printable(unsigned char *hash) {
  int i;

  for (i = 0; i < MD5_DIGEST_LENGTH; ++i) {
    if (hash[i] <= 32 || hash[i] >= 127) {
      return 0;
    }
  }
  return 1;
}

int main(int argc, char *argv[])
{
  int i = 0;

  md5_state_t c;
  unsigned char hash[MD5_DIGEST_LENGTH];
  char hexhash[MD5_DIGEST_LENGTH * 2 + 1];

  if (argc < 2) {
    fprintf(stderr,"Usage: %s <password>\n",argv[0]);
    return 1;
  }

  md5_init(&c);
  md5_append(&c, (const md5_byte_t *) argv[1], strlen(argv[1]));
  md5_finish(&c, hash);

  for (i = 0; i < MD5_DIGEST_LENGTH; ++i) {
    snprintf(&hexhash[i*2], 3, "%02x", hash[i]);
  }
  hexhash[i*2] = '\0';

  fprintf(stdout, "Secure hash validator:\n");
  fprintf(stdout, "\x1B[31m  - bruteforce is slow, don't do it! :D\033[0m\n\n");
  if (strcmp(hexhash, "5205255253c54b322876b4441666cb0b") == 0) {
    fprintf(stdout, "All right, valid the flag now ;)\n");
  }
  else if (is_printable(hash)) {
    fprintf(stdout, "debug(%.16s)\n", hash);
  }
  else {
    fprintf(stdout, "Bad input, you current hash is: %s.\n", hexhash);
    fprintf(stdout, "I'm sure your computer is enough powerful to do it.\n");
  }
  return 0;
}
