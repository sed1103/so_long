#include "../Includes/so_long.h"
#include "../Includes/get_next_line.h"

int	check_chars(char *line)
{
	int	i;

	i = -1;
	while (line[i++])
	{
		if ((line[i] != '0' && line[i] != '1' && line[i] != 'P' && line[i] != 'C' && line[i] != 'E' && line[i] != '\n'))
			exit(1 && write(2, "Error\n", 6));
		//printf("%c\n", line[i]);
	}
	return (1);
}
void	check_newline(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && str[i+1] == '\n')
			exit(1 && write(1, "Invalid map.\n", 14));
		i++;
	}
}

void	check_newline_again(char **str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i])
	{
		tmp = str[i];
		str[i] = ft_strtrim2(str[i], " \t\v\f\r");
		free(tmp);
		i++;
	}
	str[i] = NULL;
}

char	**get_map(int fd)
{
	char	*line;
	char	*join;
	char	*temp;
	char	**splited;

	join = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		if (!line)
			check_chars(line);
		temp = join;
		join = ft_strjoin(join, line);
		free(temp);
		free(line);
		line = get_next_line(fd);
	}
	temp = join;
	join = ft_strtrim(join, " \t\n\v\f\r");
	free(temp);
	check_newline(join);
	splited = ft_split(join);
	check_newline_again(splited);
	free(join);
	return (splited);
}

int main(int argc,char **argv)
{
	int	fd;

	if (argc != 2)
		exit(1 && write(2, "Error\n", 6));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit(1 && write(2, "FD Error\n", 9));
	char **res = get_map(fd);
	int	i = 0;
	while (res[i])
		printf("%s \n", res[i++]);
	free_all(res);
	return (0);
}
