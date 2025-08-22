/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_params_converter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merazafi <merazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:25:49 by merazafi          #+#    #+#             */
/*   Updated: 2025/06/12 13:46:22 by merazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_new_strdup(char *s)
{
	int		len;
	char	*a;

	len = 0;
	while (s[len])
		len++;
	a = malloc((len + 1) * sizeof(char));
	if (a == NULL)
		return (NULL);
	len = 0;
	while (s[len])
	{
		a[len] = s[len];
		len++;
	}
	a[len] = '\0';
	return (a);
}

static int	ft_count(char *str)
{
	int	k;

	k = 0;
	while (str[k])
		k++;
	return (k);
}

static char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len_total;
	char	*str;
	char	*string;

	len_total = ft_count(s);
	string = (char *)s;
	if (!string)
		return (NULL);
	else if (start >= len_total)
		return (ft_new_strdup(""));
	else if (len > len_total - start)
		len = len_total - start;
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = string[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static unsigned int	count_word(char *s, char c)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c
				|| s[i + 1] == '\0'))
			k++;
		i++;
	}
	return (k);
}

char	**ft_split(char *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	start;
	char			**new_str;

	new_str = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	start = 0;
	j = -1;
	while (s[i] && (++j < count_word(s, c)))
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		new_str[j] = ft_substr(s, start, (i - start));
	}
	new_str[j] = NULL;
	free(s);
	return (new_str);
}
