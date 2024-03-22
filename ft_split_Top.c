/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_Top.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plesukja <plesukja@42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:14:35 by plesukja          #+#    #+#             */
/*   Updated: 2024/03/22 13:27:49 by plesukja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char *ptr, char c);
static int	add_word(char **result, char *str, char sep);
static char	*copy_word(char *src, int len);
void		free_result(char **result);

char	**ft_split(char const *s, char c)
{
	char	*ptr;
	int		word_count;
	char	**result;

	ptr = (char *)s;
	word_count = count_word(ptr, c);
	result = (char **)malloc((word_count + 1) * (sizeof(char *)));
	if (!result)
	{
		free (result);
		return (NULL);
	}
	if (add_word(result, ptr, c))
		return (result);
	return (NULL);
}

static int	count_word(char *str, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != sep && (str[i + 1] == '\0' || str[i + 1] == sep))
			count++;
		i++;
	}
	return (count);
}

static int	add_word(char **result, char *str, char sep)
{
	int	i;
	int word_index;
	int word_len;

	i = 0;
	word_index = 0;
	while (str[i])
	{
		if (str[i] != sep)
		{
			word_len = 0;
			while (str[i + word_len] && str[i + word_len] != sep)
				word_len++;
			result[word_index] = copy_word(&str[i], word_len);
			if (!result[word_index])
			{
				free_result(result);
				free(result);
				return (0);
			}
			i += word_len;
			word_index++;
		}
		i++;
	}
	result[word_index] = NULL;
	return (1);
}

static char	*copy_word(char *src, int len)
{
	int		i;
	char	*word;

	i = 0;
	word = malloc((len + 1) * sizeof(char));
	if (!word)
	{
		free (word);
		return (NULL);
	}
	while (i < len)
	{
		word[i] = src[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

void	free_result(char **result)
{
	while (*result != NULL)
	{
		free (*result);
		result++;
	}
}
/*
int main(void)
{
    char **result = ft_split("0123,4", ',');

    if (!result)
    {
        printf("Error in ft_split\n");
        return 1;
    }
    for (int i = 0; result[i] != NULL; i++)
    {
        printf("Result[%d]: %s\n", i, result[i]);
    }
    for (int i = 0; result[i] != NULL; i++)
    {
        free(result[i]);
    }
    free(result);
    return 0;
}
*/