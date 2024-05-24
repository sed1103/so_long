#include "../Includes/so_long.h"
#include "../Includes/get_next_line.h"

int	check_chars(char *line)
{
	int	i;

	i = -1;
	while (line[i++])
	{
		if (line[i] && (line[i] != '0' && line[i] != '1' && line[i] != 'P' && line[i] != 'C' && line[i] != 'E' && line[i] != '\n'))
			exit(1 && write(2, "Error\n", 6));
		//printf("%c\n", line[i]);
		
	}
	return (1);
}

void	get_map(fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		printf("%s\n", line);
		line = get_next_line(fd);
		check_chars(line);
	}
}

int main(int argc,char **argv)
{
	if (argc != 2)
		exit(1 && write(2, "Error\n", 6));
	int	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit(1 && write(2, "FD Error\n", 9));
	get_map(fd);
	return (0);
}