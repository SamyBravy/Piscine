/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:20:39 by sdell-er          #+#    #+#             */
/*   Updated: 2023/09/25 11:20:43 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	separatore_o_len(char *str, char *charset, int i, int len)
{
	int	l;
	int	j;
	int	sep;

	l = 0;
	while (charset[l])
		l++;
	if (len)
		return (l);
	j = 0;
	sep = 1;
	while (j < l && sep)
	{
		if (str[i + j] != charset[j])
			sep = 0;
		j++;
	}
	return (sep);
}

struct s_ogg
{
	int		i;
	int		cont;
	int		indice;
	int		opz;
	int		ottenuto;
	int		poss;
	char	*str;
	char	*charset;
};

int	if_else_while(struct s_ogg *o)
{
	if (!separatore_o_len(o->str, o->charset, o->i, 0))
	{
		if (o->poss == 1)
			o->cont++;
		if (o->cont == o->indice + 1 && o->opz == 3)
			o->ottenuto = 1;
		else if (o->cont == o->indice + 1 && o->opz == 2)
			return (o->i);
		o->poss = 0;
	}
	else
	{
		if (o->ottenuto == 1 && o->opz == 3)
			return (o->i - 1);
		o->poss = 1;
		o->i += separatore_o_len(o->str, o->charset, o->i, 1) - 1;
	}
	return (-42);
}

int	opz_parola(char *str, int indice, char *charset, int opz)
{
	int				ret;
	struct s_ogg	o;
	struct s_ogg	*ptr;

	ptr = &o;
	o.ottenuto = 0;
	o.poss = 1;
	o.str = str;
	o.indice = indice;
	o.charset = charset;
	o.opz = opz;
	o.i = 0;
	o.cont = 0;
	while (str[o.i])
	{
		ret = if_else_while(ptr);
		if (ret != -42)
			return (ret);
		o.i++;
	}
	if (o.opz == 1)
		return (o.cont);
	return (o.i - 1);
}

void	riempi(char *dest, char *str, int start, int fine)
{
	int	i;

	i = 0;
	while (start <= fine)
	{
		dest[i] = str[start];
		start++;
		i++;
	}
	dest[i] = '\0';
}

char	**ft_split(char *str, char *charset)
{
	int		parole;
	int		i;
	char	**mat;

	if (str == NULL)
		return (NULL);
	parole = opz_parola(str, 0, charset, 1);
	mat = malloc(parole * sizeof(char *));
	if (mat == NULL || parole < 1)
		return (NULL);
	i = 0;
	while (i < parole)
	{
		mat[i] = malloc(sizeof(char)
				* (opz_parola(str, i, charset, 3)
					- opz_parola(str, i, charset, 2) + 2));
		if (mat[i] == NULL)
			return (NULL);
		riempi(mat[i], str, opz_parola(str, i, charset, 2),
			opz_parola(str, i, charset, 3));
		i++;
	}
	return (mat);
}

int main()
{
	char *str = "nonna10nonnavedrainonnonnasononnaquantinonnaanninonna";
	char *sep = "nonna";
	char **mat = ft_split(str, sep);
	int i = 0;
	while (i < opz_parola(str, 0, sep, 1))
	{
		printf("%s\n", mat[i]);
		i++;
	}
	
	return 0;
}

