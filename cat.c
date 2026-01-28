#include <unistd.h>
#include <fcntl.h>

#define ui32 unsigned int
#define CAT_READ_ERROR  "cat: error reading file\n"

ui32  slen(char *s)
{
  ui32  len;

  len = 0;
  while (s && s[len])
    len++;
  return (len);
}

int cat(int fd)
{
  unsigned char  buff[4096];
  int   bytes;

  if (fd < 0)
    return (-1);
  bytes = 1;
  while (bytes)
  {
    bytes = read(fd, buff, 4096);
    if (bytes == -1)
      return (-1);
    write(1, buff, bytes); 
  }
  return (1);
}

int main(int ac, char **av)
{
  int res;

  res = 1;
  if (ac <= 1)
  {
    res = cat(0);
    if (res < 0)
    {
      write(2, CAT_READ_ERROR, slen(CAT_READ_ERROR));
      return (1);
    }
    return (0);
  }
  av++;
  while (--ac)
  {
    int fd = open(*av, O_RDONLY);
    if (fd == -1)
    {
      write(2, CAT_READ_ERROR, slen(CAT_READ_ERROR));
      av++;
      continue;
    }
    else
      res = cat(fd);
    if (res < 0)
      write(2, CAT_READ_ERROR, slen(CAT_READ_ERROR));
    av++;
    }
  return (0);
}
