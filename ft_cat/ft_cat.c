#include <ft_cat.h>


size_t	ft_strlen(char *s) {
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

void	put_buffer(char *s) {
	while (s && *s)
		write(1, s++, 1);
}

void	read_file(int fd) {
	char	tmp[BUFFER_SIZE];
	int		read_status;
	char	*err;

	read_status = 1;
	while (read_status) {
		read_status = read(fd, tmp, BUFFER_SIZE - 1);
		if (read_status == -1) {
			err = strerror(errno);
			write(2, err, ft_strlen(err));
			write(2, "\n", 1);
			return ;
		}
		tmp[read_status] = '\0';
		put_buffer(tmp);
	}
}

int	main( int ac, char **av ) {
	int		fd;
	char	*err;

	(void)ac;
	fd = STDIN_FILENO;
	if (av)
		av++;
	while (av && *av) {
		fd = open(*av, O_RDONLY);
		if (fd == -1) {
			err = strerror(errno);
			write(2, err, ft_strlen(err));
			write(2, "\n", 1);
		}
		else
			read_file(fd);
		av++;
	}
	return (0);
}