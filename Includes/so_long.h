#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

//char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char *str);
//size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
void	*free_all(char **out);
char	*ft_strtrim(char *s1, char *set);
char	*ft_strtrim2(char *s1, char *set);

# endif