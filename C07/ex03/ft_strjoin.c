/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 22:58:25 by sdell-er          #+#    #+#             */
/*   Updated: 2023/09/21 22:58:40 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	tot_len(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	l;

	i = 0;
	l = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			j++;
		l += j;
		i++;
	}
	i = 0;
	while (sep[i])
		i++;
	l += i * (size - 1);
	return (l);
}

void	riempi_str(int size, char **strs, char *sep, char *str)
{
	int	i;
	int	j;
	int	cont;

	i = 0;
	cont = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			str[cont] = strs[i][j];
			cont++;
			j++;
		}
		j = 0;
		while (sep[j] && i != size - 1)
		{
			str[cont] = sep[j];
			cont++;
			j++;
		}
		i++;
	}
	str[cont] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		l;
	char	*str;

	if (size <= 0)
	{
		str = malloc(1);
		if (str == NULL)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	l = tot_len(size, strs, sep);
	str = malloc(l * sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	riempi_str(size, strs, sep, str);
	return (str);
}
/*
int main()
{
    char *strs[] = {"Hello", "world", "!", "This", "is", "a", "test"};
    char *sep = " ";
    int size = 7;

    char *result = ft_strjoin(size, strs, sep);

    if (result != NULL) {
        printf("Stringa concatenata: %s\n", result);
        free(result); // Libera la memoria allocata dinamicamente
    } else {
        printf("Errore nell'allocazione di memoria.\n");
    }

    return 0;
}
*/
