/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merazafi <merazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 09:44:31 by merazafi          #+#    #+#             */
/*   Updated: 2025/07/30 11:29:32 by merazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_new_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}

static void	error_join(char *s1, char *str)
{
	free(s1);
	free(str);
	return_error();
}

static char	*ft_new_strjoin(char *s1, char *s2)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;
	size_t			len[2];

	len[0] = ft_new_strlen(s1);
	len[1] = ft_new_strlen(s2);
	str = malloc(sizeof(char) * (len[0] + len[1] + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = -1;
	while (++i < len[0])
		str[i] = s1[i];
	while (++j < len[1])
	{
		if (((s2[j] >= '0' && s2[j] <= '9')
				|| (s2[j] == ' ') || ((s2[j] == '-') || s2[j] == '+')))
		{
			str[i + j] = s2[j];
		}
		else
			error_join(s1, str);
	}
	return (str[i + j] = '\0', free(s1), (char *)str);
}

char	*join_args(int argc, char **argv)
{
	char	*joined;
	int		i;

	joined = ft_new_strdup("");
	i = 1;
	while (i < argc)
	{
		check_void(argv[i], joined);
		i++;
	}
	i = 1;
	while (i < argc)
	{
		joined = ft_new_strjoin(joined, argv[i]);
		joined = ft_new_strjoin(joined, " ");
		i++;
	}
	return (joined);
}
