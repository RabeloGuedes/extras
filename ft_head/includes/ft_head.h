#ifndef FT_HEAD_H
# define FT_HEAD_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <string.h>

# ifdef BUFFER_SIZE
#  if BUFFER_SIZE >= 999999
#   undef BUFFER_SIZE
#   define BUFFER_SIZE 1024
#  endif
# else
#  define BUFFER_SIZE 1024
# endif

#endif
