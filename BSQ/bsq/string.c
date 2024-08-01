#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	str_len;

	str_len = 0;
	while (str[str_len] != '\0')
		str_len++;
	return (str_len);
}

void	duplicate(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	*ft_strdup(char *src)
{
	char	*str;
	int		str_len;

	str_len = ft_strlen(src);
	str = malloc(sizeof(char) * (str_len + 1));
	if (str == NULL)
		return (NULL);
	duplicate(str, src);
	return (str);
}
