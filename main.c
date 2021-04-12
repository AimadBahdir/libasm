/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahdir <abahdir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 08:11:00 by abahdir           #+#    #+#             */
/*   Updated: 2021/04/11 13:59:12 by abahdir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int    ft_strlen(char *str);
int    ft_strcmp(char *s1, char *s2);
char   *ft_strcpy(char *src, char *dest);
char   *ft_strdup(char *str);
int    ft_write(int fd, char *buffer, int len);
int    ft_read(int fd, char *buffer, int len);

int main(int argc, char **argv)
{
       char *str;
       str = malloc(6);
       printf("ME: %d\n", ft_read(1, str, 5));
       printf(">> %s\n", str);
       printf("HE: %zd\n", read(0, str, 5));
       printf(">> %s\n", str);
}