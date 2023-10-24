#include "get_next_line.h"
#include  <fcntl.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
    int		fd;
    char	*line;
    int		i;
    
    if(argc != 2)
        return (1);
    fd = open(argv[1], O_RDONLY);

    i = 0;
    while (1)
    {
        if(!(line = get_next_line(fd)))
            break;
        printf("%s", line);
        if (line)
            free(line);
        i++;
    }
    close(fd);
    return (0);
}