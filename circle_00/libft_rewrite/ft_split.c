/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:21:46 by fhiedi            #+#    #+#             */
/*   Updated: 2022/12/02 09:49:13 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

static int get_number_of_rows(char const *s, unsigned char c)
{
    int i;
    int number_of_rows;

    i = 0;
    number_of_rows = 0;
    while (s[i])
    {
        while(s[i] == c)
            i++;
        if (s[i] != c && s[i])
            number_of_rows++;
        while (s[i] != c && s[i])
            i++;
    }
    return number_of_rows;
}

/*static void free_splited_row(char **splited_row, char const *s, unsigned char c)
{
    int i;
    int number_of_rows;

    number_of_rows = get_number_of_rows(s, c);
    i = 0;
    while (i < number_of_rows)
    {
        if (splited_row[i])
            free(splited_row[i]);
        i++;
    }
    free(splited_row);
}*/



static void get_splited_row(char *row, char const *s, unsigned char c)
{
    static int i;
    int j;
    
    j = 0;
    while (s[i])
    {
        while(s[i] != c && s[i])
        {
            row = malloc(1);
            if (!row)
                free_splited_;
            row[j++] = s[i++]; 
            if (s[i] == c || !s[i])
                return ;
        }
    }



            i++;
        start = i;
        while(s[i] != c && s[i])
        {
            i++;
            if (s[i] == c || !s[i])
            {
                len = i - start;
                splited_row[j] = ft_substr(s, start, len);
                printf("%s\n", splited_row[j]);
                if (!splited_row[j])
                {
                     while (j > 0)
                         free(splited_row[j--]);
                     free(splited_row);
                     return ;
                }
            }
        }
        j++;
    }
    splited_row[j] = NULL;
}


char **ft_split(char const *s, char c)
{
    int number_of_rows;
    char **splited_row;

    if (!s)
        return 0;
    number_of_rows = get_number_of_rows(s, c);
    printf("number of rows: %d\n", number_of_rows + 1);
    splited_row = malloc(sizeof(char **) * number_of_rows);
    if (!splited_row)
        return NULL;
    while (number_of_rows-- > 0)
        get_row(splited_row[i++], c, s);
    return splited_row;
}


int main(void) {
    char *splitme;
    char **splited_row;

    splitme = strdup("Tripouille ");
    splited_row = ft_split(splitme, ' ');
    printf("%s\n", splited_row[0]);
    printf("%s\n", splited_row[1]);
}
