#ifndef FT_CAT_H
# define FT_CAT_H

# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
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