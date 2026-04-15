/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segribas <segribas@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 18:51:25 by segribas          #+#    #+#             */
/*   Updated: 2026/04/15 14:39:24 by segribas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static const char	*skip_delims(char const *p, char c)
{
	while (*p == c)
		p++;
	return (p);
}

static void	free_all(char **out, size_t i_out)
{
	while (i_out > 0)
		free(out[--i_out]);
	free(out);
}

static size_t	count_words(char const *s, char c)
{
	size_t	counter;
	int		in_word;

	counter = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == c)
			in_word = 0;
		else if (in_word == 0)
		{
			in_word = 1;
			counter++;
		}
		s++;
	}
	return (counter);
}

static size_t	word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	return (len);
}

char	**ft_split(char const *s, char c)
{
	const char	*p;
	char		**out;
	size_t		i_out;
	size_t		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	out = (char **)malloc((words + 1) * sizeof(char *));
	if (!out)
		return (NULL);
	p = s;
	i_out = 0;
	while (i_out < words)
	{
		p = skip_delims(p, c);
		out[i_out] = (char *)malloc(word_len(p, c) + 1);
		if (!out[i_out])
			return (free_all(out, i_out), NULL);
		ft_strlcpy(out[i_out], p, word_len(p, c) + 1);
		p += word_len(p, c);
		i_out++;
	}
	out[i_out] = NULL;
	return (out);
}
