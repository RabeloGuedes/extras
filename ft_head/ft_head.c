#include <ft_head.h>

size_t ft_strlen(char *s) {
    size_t i;

    i = 0;
    while (s && s[i])
        i++;
    return (i);
}

char *ft_strjoin(char *buffer, char *tmp) {
    size_t len;
    char   *new_buffer;
    size_t i;

	len = ft_strlen(buffer) + ft_strlen(tmp);
	new_buffer = (char *)malloc(sizeof(char) * len + 1);
    i = 0;
    if (!new_buffer)
        return (NULL);
    while (buffer && buffer[i]) {
        new_buffer[i] = buffer[i];
        i++;
    }
    free(buffer);
    while (tmp && *tmp)
        new_buffer[i++] = *tmp++;
    new_buffer[i] = '\0';
    return (new_buffer);
}

char *ft_strchr(char *buffer, char c) {
    while (buffer && *buffer) {
        if (*buffer == c)
            return (buffer);
        buffer++;
    }
    if (buffer && *buffer == c)
        return (buffer);
    return (NULL);
}

void update_line_counter(char *buffer, size_t *line_counter) {
    while (buffer && *buffer && line_counter && *line_counter) {
        buffer = ft_strchr(buffer, '\n');
        if (buffer) {
            buffer++;
            (*line_counter)--;
        }
    }
    if (buffer && *buffer && line_counter && !(*line_counter))
            *buffer = '\0';
}

char *read_file(int fd, size_t line_counter) {
    char 	*buffer;
    char 	tmp[BUFFER_SIZE];
    int  	read_status;
	char	*err;

    buffer = NULL;
    read_status = 1;
    while (read_status && line_counter) {
        read_status = read(fd, tmp, BUFFER_SIZE - 1);
        if (read_status == -1) {
			err = strerror(errno);
			write(2, err, ft_strlen(err));
			write(2, "\n", 1);
            free(buffer);
            return (NULL);
        }
        tmp[read_status] = '\0';
        update_line_counter(tmp, &line_counter);
        buffer = ft_strjoin(buffer, tmp);
    }
    return (buffer);
}

void put_buffer(char *buffer) {
    if (!buffer)
        write(1, "(nil)", 5);
    while (buffer && *buffer)
        write(1, buffer++, 1);
}

int main( int ac, char **av ) {
    int 	fd;
    char 	*buffer;
	char	*err;

    fd = 0;
    if (ac > 1) {
        fd = open(av[1], O_RDONLY);
        if (fd == -1) {
			err = strerror(errno);
            write(2, err, ft_strlen(err));
			write(2, "\n", 1);
            return (1);
        }
    }
    buffer = read_file(fd, 10);
    put_buffer(buffer);
    free(buffer);
    return (0);
}
