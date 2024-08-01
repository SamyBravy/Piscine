/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 00:06:23 by sdell-er          #+#    #+#             */
/*   Updated: 2023/09/28 00:06:32 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(char *src, int s_word)
{
	char	*dest;
	int		i;

	dest = malloc(sizeof(char) * (s_word + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i] && i < s_word)
	{
		dest[i] = src[i];
		i += 1;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_in_str(char charstr, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == charstr)
			return (1);
		i += 1;
	}
	return (0);
}

int	ft_sizeword(char *str, char *charset)
{
	int	i;

	i = 0;
	while (*str && ft_in_str(*str, charset) == 0)
	{
		i += 1;
		str += 1;
	}
	return (i);
}

int	ft_nbrword(char *str, char *charset)
{
	int	s_word;
	int	nbrword;

	s_word = 0;
	nbrword = 0;
	while (*str)
	{
		while (*str && ft_in_str(*str, charset))
			str += 1;
		s_word = ft_sizeword(str, charset);
		str += s_word;
		if (s_word)
			nbrword += 1;
	}
	return (nbrword);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		i;
	int		s_result;
	int		s_word;

	i = 0;
	s_result = ft_nbrword(str, charset);
	result = malloc(sizeof(char *) * (s_result + 1));
	if (!result)
		return (NULL);
	while (i < s_result)
	{
		while (*str && ft_in_str(*str, charset))
			str += 1;
		s_word = ft_sizeword(str, charset);
		result[i] = ft_strdup(str, s_word);
		str += s_word;
		i += 1;
	}
	result[i] = NULL;
	return (result);
}
/*
int main(void)
{
	char	*str = "kcaccakchekschiffok";
	char	*charset = "k";
	int		i;
	char	**result;

	result = ft_split(str, charset);
	i = 0;
	while (result[i])
		printf("%s\n", result[i++]);
	return (0);
} */
